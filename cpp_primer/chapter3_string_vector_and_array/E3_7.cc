#include <iostream>
#include <string>

int main() {
    std::string s = "123456789";
    for (char& c: s) {  // auto�ƶϳ����ľ���char
        c = 'X';
    }
    std::cout << s << std::endl;
}