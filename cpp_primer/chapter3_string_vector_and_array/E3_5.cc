#include <iostream>
#include <string>

int main() {
    std::string result = "", termination = "y", tmp;
    while (std::cin >> tmp) {
        if (result.empty()) {
            result += tmp;
        } else {
            result += " " + tmp;
        }
        std::cout << "will you go on input, (y / n)?" << std::endl;
        std::cin >> termination;
        if (!(termination == "y" || termination == "Y")) {
            break;
        }
    }
    std::cout << result << std::endl;
}