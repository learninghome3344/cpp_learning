/**
 * @file http_client.cpp
 * @author yanbingjian1995@gmail.com
 * @brief 
 * 命令行方式：./build/http_client http://localhost:8010/HttpService/Hello
 * 网页方式：
 * http://itdeMacBook-Pro.local:8010
 * http://localhost:8010/HttpService/Hello
 * http://localhost:8010/v1/queue/stats/haha
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/channel.h>

DEFINE_string(d, "", "POST this data to the http server");
DEFINE_string(load_balancer, "", "The algorithm for load balancing");
DEFINE_int32(timeout_ms, 2000, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)"); 
DEFINE_string(protocol, "http", "Client-side protocol");

namespace brpc {
DECLARE_bool(http_verbose);
} // namespace brpc

int main(int argc, char* argv[]) {
    google::ParseCommandLineFlags(&argc, &argv, true);
    
    if (argc != 2) {
        LOG(ERROR) << "Usage: ./http_client \"http(s)://www.foo.com\"";
        return -1;
    }
    char* url = argv[1];

    brpc::Channel channel;
    brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.timeout_ms = FLAGS_timeout_ms;
    options.max_retry = FLAGS_max_retry;
    if (channel.Init(url, FLAGS_load_balancer.c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel.";
        return -1;
    }

    brpc::Controller cntl;
    if (!FLAGS_d.empty()) {
        cntl.http_request().set_method(brpc::HTTP_METHOD_POST);
        cntl.request_attachment().append(FLAGS_d);
    }

    cntl.http_request().uri() = url;
    channel.CallMethod(NULL, &cntl, NULL, NULL, NULL);
    if (cntl.Failed()) {
        std::cerr << cntl.ErrorText() << std::endl;
        return -1;
    }
    if (!brpc::FLAGS_http_verbose) {
        std::cout << cntl.response_attachment() << std::endl;
    }
    return 0;
}