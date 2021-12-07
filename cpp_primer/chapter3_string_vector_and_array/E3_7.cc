#include <iostream>
#include <string>

int main() {
    std::string s = "123456789";
    for (char& c: s) {  // auto推断出来的就是char
        c = 'X';
    }
    std::cout << s << std::endl;
}