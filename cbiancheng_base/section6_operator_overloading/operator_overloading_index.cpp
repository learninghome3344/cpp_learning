#include <iostream>
using namespace std;

class Array {
public:
    Array(int length);
    ~Array();

    int& operator[](int i);
    const int& operator[](int i) const;

    int length() const { return m_length; }
    void display() const;
private:
    int m_length;
    int* m_p;
};

Array::Array(int length): m_length(length) {
    if (m_length == 0) {
        m_p = NULL;
    } else {
        m_p = new int[m_length];
    }
}

Array::~Array() {
    delete []m_p;
}

int& Array::operator[](int i) {
    return m_p[i];
}

const int & Array::operator[](int i) const {
    return m_p[i];
}

void Array::display() const {
    if (m_length == 0) {
        cout << "array is empty" << endl;
    }
    for (int i = 0; i < m_length; i++) {
        cout << m_p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Array A(n);
    for(int i = 0, len = A.length(); i < len; i++){
        A[i] = i * 5;
    }
    A.display();

    const Array B(n);
    cout << B[n-1] << endl;
}