#include <iostream>
using namespace std;

// 统计在输入中每个值连续出现了多少次


int main() {
    int cur_value = 0, value = 0;
    int count = 0;
    while (cin >> value) {
        if (cur_value == value) {
            count++;
        } else {
            if (count > 0)
                cout << cur_value << " occurs " << count << " times" << endl;
            cur_value = value;
            count = 1;
        }
    }
    cout << cur_value << " occurs " << count << " times" << endl;
}

// 2 2 3 3 4 4 4
// 2 occurs 2 times
// 3 occurs 2 times
// 4 occurs 3 times