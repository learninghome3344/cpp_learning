/**
 * @file http_server.cpp
 * @author yanbingjian1995@gmail.com
 * @brief 
 * http server with ssl encryption 
 * openssl cert.pem & key.pem generate: https://my.oschina.net/who7708/blog/3178769
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>
#include <brpc/restful.h>
#include <http.pb.h>

DEFINE_int32(port, 8010, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");
DEFINE_int32(logoff_ms, 2000, "Maximum duration of server's LOGOFF state "
             "(waiting for client to close connection before server stops)");

DEFINE_string(certificate, "cert.pem", "Certificate file path to enable SSL");
DEFINE_string(private_key, "key.pem", "Private key file path to enable SSL");
DEFINE_string(ciphers, "", "Cipher suite used for SSL connections");


namespace example {

class HttpServiceImpl: public HttpService {
public:
    HttpServiceImpl() {};
    virtual ~HttpServiceImpl() {};
    void Hello(google::protobuf::RpcController* controller,
            const ::example::HttpRequest* request,
            example::HttpResponse* response,
            google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);

        brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);
        cntl->http_response().set_content_type("text/plain");
        butil::IOBufBuilder os;
        os << "queries: ";
        for (brpc::URI::QueryIterator it = cntl->http_request().uri().QueryBegin();
                it != cntl->http_request().uri().QueryEnd(); ++it) {
            os << " " << it->first << "=" << it->second;
        }
        os << "\nbody: " << cntl->request_attachment() << "\n";
        os.move_to(cntl->response_attachment());
    }
};

class FileServiceImpl: public FileService {
public:
    FileServiceImpl() {};
    virtual ~FileServiceImpl() {};

    struct Iptr {
        butil::intrusive_ptr<brpc::ProgressiveAttachment> pa;
    };

    static void* SendLargeFile(void* raw_args) {
        std::unique_ptr<Iptr> iptr(static_cast<Iptr*>(raw_args));
        if (iptr->pa == NULL) {
            LOG(ERROR) << "ProgressiveAttachment is NULL.";
            return NULL;
        }
        for (int i = 0; i< 10; ++i) {
            char buf[16];
            int len = snprintf(buf, sizeof(buf), "part_%d", i);
            iptr->pa->Write(buf, len);

            bthread_usleep(10000);
        }
        return NULL;
    }

    void default_method(google::protobuf::RpcController* controller,
                       const example::HttpRequest* request,
                       example::HttpResponse* response,
                       google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);
        brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);
        const std::string filename = cntl->http_request().unresolved_path();
        if (filename == "largefile") {
            std::unique_ptr<Iptr> iptr(new Iptr);
            iptr->pa = cntl->CreateProgressiveAttachment();
            bthread_t th;
            bthread_start_background(&th, NULL, SendLargeFile, iptr.release());
        } else {
            cntl->response_attachment().append("Getting file: ");
            cntl->response_attachment().append(filename);
        }
    }
};

class QueueServiceImpl: public QueueService {
public:
    QueueServiceImpl() {};
    virtual ~QueueServiceImpl() {};
    void start(google::protobuf::RpcController* controller,
                    const example::HttpRequest* request,
                    example::HttpResponse* response,
                    google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);
        brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);
        cntl->response_attachment().append("queue started.");
    }

    void stop(google::protobuf::RpcController* controller,
                const ::example::HttpRequest* request,
                ::example::HttpResponse* response,
                ::google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);
        brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);
        cntl->response_attachment().append("queue stoped.");
    }

    void getstats(google::protobuf::RpcController* controller,
                const ::example::HttpRequest* request,
                ::example::HttpResponse* response,
                ::google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);
        brpc::Controller* cntl = static_cast<brpc::Controller*>(controller);
        const std::string& unresolved_path = cntl->http_request().unresolved_path();
        if (unresolved_path.empty()) {
            cntl->response_attachment().append("Require a name after /stats");
        } else {
            cntl->response_attachment().append("Get stats: ");
            cntl->response_attachment().append(unresolved_path);
        }
    }
};

} // namespace example


int main(int argc, char* argv[]) {
    google::ParseCommandLineFlags(&argc, &argv, NULL);
    brpc::Server server;

    example::HttpServiceImpl http_svc;
    example::FileServiceImpl file_svc;
    example::QueueServiceImpl queue_svc;

    if (server.AddService(&http_svc, brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add http_svc";
        return -1;
    }
    if (server.AddService(&file_svc, brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add file_svc";
        return -1;
    }
    if (server.AddService(&queue_svc,
                            brpc::SERVER_DOESNT_OWN_SERVICE,
                            "/v1/queue/start => start,"
                            "/v1/queue/stop => stop,"
                            "/v1/queue/stats/* => getstats") != 0) {
        LOG(ERROR) << "Fail to add queue_svc";
        return -1;
    }

    brpc::ServerOptions options;
    options.idle_timeout_sec = FLAGS_idle_timeout_s;
    options.mutable_ssl_options()->default_cert.certificate = FLAGS_certificate;
    options.mutable_ssl_options()->default_cert.private_key = FLAGS_private_key;
    options.mutable_ssl_options()->ciphers = FLAGS_ciphers;
    if (server.Start(FLAGS_port, &options) != 0) {
        LOG(ERROR) << "Fail to start server";
        return -1;
    }

    server.RunUntilAskedToQuit();
    return 0;
}