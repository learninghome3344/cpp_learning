#include <iostream>
using namespace std;

// add 50 to 100
int main() {
    int sum = 0, value = 50;
    while (value <= 100) {
        sum += value;
        ++value;
    }
    cout << "sum between 50 and 100 is " << sum << endl;
}