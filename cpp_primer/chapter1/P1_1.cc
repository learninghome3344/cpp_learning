#include <iostream>
using namespace std;

// ��ȡ������������������

int main() {
    int sum = 0, value = 0;
    while (cin >> value) {
        sum += value;
    }
    cout << sum << endl;
}

// ctrl + D to stop input