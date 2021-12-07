#include <iostream>
#include <string>

int main() {
    std::string s = "123456789";
    for (auto& c: s) {
        c = 'X';
    }
    std::cout << s << std::endl;
}