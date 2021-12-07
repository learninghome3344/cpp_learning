#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    int tmp;
    while (std::cin >> tmp) {
        vec.push_back(tmp);
    }

    // 输出每个相邻位置两个数的和 
    for (decltype((vec.size())) i = 0; i+1 < vec.size(); i+=2) {
        std::cout << vec[i] + vec[i+1] << " ";
    }
    if (vec.size() %2 == 1) std::cout << vec[vec.size()-1];
    std::cout << std::endl;

    // 输出每个首尾对称位置两个数的和
    for (decltype((vec.size())) i = 0; i < (vec.size()-1)/2; i++) {
        std::cout << vec[i] + vec[vec.size()-i-1] << " ";
    }
    if (vec.size() %2 == 1) std::cout << vec[vec.size()/2];
    std::cout << std::endl;

    /* 1 2 3 4 5
     * 3 7 5
     * 6 6 3
     */
}