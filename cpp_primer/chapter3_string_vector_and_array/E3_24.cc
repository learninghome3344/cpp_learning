#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int tmp;
    while (std::cin >> tmp) {
        vec.push_back(tmp);
    }
    // 输出每个相邻位置两个数的和 
    for (auto it = vec.begin(); it != vec.end()-1; it+=2) {
        std::cout << *(it) + *(it+1) << " ";
    }
    if (vec.size() % 2 == 1) std::cout << vec[vec.size()-1];
    std::cout << std::endl;

    // 输出每个首尾对称位置两个数的和
    for (auto it = vec.begin(); it != vec.begin() + (vec.end() - vec.begin()) / 2; it++) {
        std::cout << *it + *(vec.begin() + (vec.size() - (it - vec.begin()) - 1)) << " ";
    }
    if (vec.size() %2 == 1) std::cout << vec[vec.size()/2];
    std::cout << std::endl;
}