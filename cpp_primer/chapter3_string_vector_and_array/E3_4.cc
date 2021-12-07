#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    if (s1 == s2) {
        std::cout << s1 << " equal " << s2 << std::endl;
    } else if (s1 < s2) {
        std::cout << s1 << " < " << s2 << std::endl;
    } else {
        std::cout << s1 << " > " << s2 << std::endl;
    }
}