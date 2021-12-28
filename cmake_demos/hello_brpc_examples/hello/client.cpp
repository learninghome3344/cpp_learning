/**
 * @file client.cpp
 * @author yanbingjian1995@gmail.com
 * @brief 
 * after start server(./build/hello_server)
 * 1 ./build/hello_client
 * 2 curl -d '{"message": "hello"}' http://localhost:8000/HelloService/Hello
 * @version 0.1
 * @date 2021-12-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>
#include <hello.pb.h>

DEFINE_string(attachment, "", "Carry this along with requests");
DEFINE_string(protocol, "baidu_std", "Protocol type. Defined in src/brpc/options.proto");
DEFINE_string(connection_type, "", "Connection type. Available values: single, pooled, short");
DEFINE_string(server, "0.0.0.0:8000", "IP Address of server");
DEFINE_string(load_balancer, "", "The algorithm for load balancing");
DEFINE_int32(timeout_ms, 100, "RPC timeout in milliseconds");
DEFINE_int32(max_retry, 3, "Max retries(not including the first RPC)"); 
DEFINE_int32(interval_ms, 1000, "Milliseconds between consecutive requests");


int main(int argc, char* argv[]) {
    google::ParseCommandLineFlags(&argc, &argv, true);

    brpc::Channel channel;
    brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.connection_type = FLAGS_connection_type;
    options.timeout_ms = FLAGS_timeout_ms;
    options.max_retry = FLAGS_max_retry;
    if (channel.Init(FLAGS_server.c_str(), FLAGS_load_balancer.c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to intialize channel";
        return -1;
    }

    example::HelloService_Stub stub(&channel);

    int log_id = 0;
    while (!brpc::IsAskedToQuit()) {
        example::HelloRequest request;
        example::HelloResponse response;
        brpc::Controller cntl;

        request.set_message("hello world.");
        cntl.set_log_id(log_id++);
        cntl.request_attachment().append(FLAGS_attachment);
        
        stub.Hello(&cntl, &request, &response, NULL);
        if (!cntl.Failed()) {
            LOG(INFO) << "Received response from " << cntl.remote_side()
                << " to " << cntl.local_side()
                << ": " << response.message() << " (attached="
                << cntl.response_attachment() << ")"
                << "latency= " << cntl.latency_us() << "us";
        } else {
            usleep(FLAGS_interval_ms * 1000);
        }
    }

    LOG(INFO) << "Hello Client is going to quit";
    return 0;
}
