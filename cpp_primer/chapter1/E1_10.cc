#include <iostream>
using namespace std;


// print intergers between 10 and 0
int main() {
    int value = 10;
    while (value >= 0) {
        cout << value << " ";
        --value;
    }
    cout << endl;
}
