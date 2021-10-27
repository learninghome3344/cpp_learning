#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void Swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void Swap(bool &a, bool &b) {
    bool temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 2, b = 1;
    Swap(a, b);
    cout << a << " " << b << endl;

    double c = 0.2, d = 0.1;
    Swap(c, d);
    cout << c << " " << d << endl;
}