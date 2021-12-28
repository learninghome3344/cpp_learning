#include <iostream>
#include <vector>
#include <string>
#include <gflags/gflags.h>

// ./build/hello_gflags
// ./build/hello_gflags --port 3344

DEFINE_int32(port, 9888, "TCP Port of up server");
DEFINE_string(host, "127.0.0.1", "Server ip");

int main(int argc, char *argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    std::vector<std::string> msg = {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const std::string& word : msg)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::cout << FLAGS_host << ":" << FLAGS_port << std::endl;
}