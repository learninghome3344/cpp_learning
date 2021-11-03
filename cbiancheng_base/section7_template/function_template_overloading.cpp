#include <iostream>
using namespace std;

template<typename T> void Swap(T& a, T& b);
template<typename T> void Swap(T a[], T b[], int len);

template<typename T>
void printArray(T arr[], int len);


int main() {
    int m = 10, n = 99;
    Swap(m, n);
    cout<<m<<", "<<n<<endl;

    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 10, 20, 30, 40, 50 };
    int len = sizeof(a) / sizeof(int);
    Swap(a, b, len);
    printArray(a, len);
    printArray(b, len);

    return 0;
}

template<typename T>
void Swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void Swap(T a[], T b[], int len) {
    T tmp;
    for (int i = 0; i < len; i++) {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

template<typename T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (i == len-1) {
            cout << arr[i] << endl;
        } else {
            cout << arr[i] << " ";
        }
    }
}

