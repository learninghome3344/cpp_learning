#include <iostream>
using namespace std;

// 读取数量不定的输入数据

int main() {
    int sum = 0, value = 0;
    while (cin >> value) {
        sum += value;
    }
    cout << sum << endl;
}

// ctrl + D to stop input