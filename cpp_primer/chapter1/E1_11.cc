#include <iostream>
using namespace std;


// cin two numbers, print intergers between these two numbers

int main() {
    int left, right;
    cout << "Please input two numbers: " << endl;
    cin >> left >> right;
    if (left > right) {
        int tmp = left;
        left = right;
        right = tmp;
    }
    while (left <= right) {
        cout << left << " ";
        ++left;
    }
    cout << endl;
}
