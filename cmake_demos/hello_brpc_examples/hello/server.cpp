/**
 * @file server.cpp
 * @author yanbingjian1995@gmail.com
 * @brief 
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <gflags/gflags.h>
#include <brpc/server.h>
#include <butil/logging.h>
#include <hello.pb.h>

DEFINE_bool(hello_attach, true, "attach or not");
DEFINE_int32(port, 8000, "TCP port of this server");
DEFINE_int32(idle_timeout_s, -1, "connection will be closed");
DEFINE_int32(logoff_ms, 2000, "Maximum duration of server's LOGOFF state ");

namespace example {
class HelloServiceImpl: public HelloService {
public:
    HelloServiceImpl() {};
    virtual ~HelloServiceImpl() {};
    virtual void Hello(google::protobuf::RpcController* cntl_base,
                const HelloRequest* request,
                HelloResponse* response,
                google::protobuf::Closure* done) {
        brpc::ClosureGuard done_guard(done);
        brpc::Controller* cntl  = static_cast<brpc::Controller*>(cntl_base);
        LOG(INFO) << "Received request[log_id=" << cntl->log_id()
                << "] from " << cntl->remote_side()
                << " to " << cntl->local_side()
                << ": " << request->message()
                << " (attached=" << cntl->request_attachment() << ")";
        
        response->set_message(request->message());

        if (FLAGS_hello_attach) {
            cntl->response_attachment().append(cntl->request_attachment());
        }
    }
};
} // namespace example

int main(int argc, char* argv[]) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    brpc::Server server;
    example::HelloServiceImpl hello_service_impl;
    if (server.AddService(&hello_service_impl,
                        brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        LOG(ERROR) << "Fail to add service";
        return -1;
    }

    brpc::ServerOptions options;
    options.idle_timeout_sec = FLAGS_idle_timeout_s;
    if (server.Start(FLAGS_port, &options) != 0) {
        LOG(ERROR) << "Fail to start HelloServer";
        return -1;
    }

    server.RunUntilAskedToQuit();
    return 0;
}
