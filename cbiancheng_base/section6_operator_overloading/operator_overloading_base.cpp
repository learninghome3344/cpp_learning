#include <iostream>
using namespace std;


/// 所谓重载，就是赋予新的含义。
/// 函数重载（Function Overloading）可以让一个函数名有多种功能，在不同情况下进行不同的操作。
/// 运算符重载（Operator Overloading）也是一个道理，同一个运算符可以有不同的功能。

/// 实际上，我们已经在不知不觉中使用了运算符重载。
/// 例如，+号可以对不同类型（int、float 等）的数据进行加法操作；<<既是位移运算符，又可以配合 cout 向控制台输出数据。
/// C++ 本身已经对这些运算符进行了重载。


/// tips: 在c++成员函数中使用const
/// 前面使用const 表示返回值为const
/// 后面加 const表示函数不可以修改class的成员


class complex{
public:
    complex();
    complex(double real, double imag);

    complex operator+(const complex& A) const;
    void display() const;

private:
    double m_real;
    double m_imag;
};

complex::complex(): m_real(0.0), m_imag(0.0) { }
complex::complex(double real, double imag): m_real(real), m_imag(imag) { }

complex complex::operator+(const complex& A) const {
    complex B;
    B.m_real = this->m_real + A.m_real;
    B.m_imag = this->m_imag + B.m_imag;
    return B;
}

void complex::display() const {
    cout << m_real << " + i" << m_imag << endl;
}

int main() {
    complex c1(4.3, 5.8);
    complex c2(2.4, 3.7);
    complex c3;
    c3 = c1 + c2;
    c3.display();
}