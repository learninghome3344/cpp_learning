#include <iostream>
#include <iomanip>
using namespace std;

/// 重载自增和自减运算符

/// new和delete运算符也可以重载 http://c.biancheng.net/view/2314.html
/// 其重载形式既可以是类的成员函数，也可以是全局函数。一般情况下，内建的内存管理运算符就够用了，只有在需要自己管理内存时才会重载。

class stopwatch {
public:
    stopwatch(int min, int sec): m_min(min), m_sec(sec) { }

    void set_zero();
    stopwatch run();
    stopwatch operator++();
    stopwatch operator++(int n);
    friend ostream& operator<<(ostream&, const stopwatch&);

private:
    int m_min;
    int m_sec;
};

void stopwatch::set_zero() {
    m_min = 0;
    m_sec = 0;
}

stopwatch stopwatch::run() {
    m_sec++;
    if (m_sec == 60) {
        m_min++;
        m_sec = 0;
    }
    return *this;
}

// 前置++直接返回对象，后置++修改对象的值且返回修改前的副本
stopwatch stopwatch::operator++() {
    run();
    return *this;
}

stopwatch stopwatch::operator++(int n) {
    stopwatch sw = *this;
    run();
    return sw;
}

ostream& operator<<(ostream& os, const stopwatch& sw) {
    os << setfill('0') << setw(2) << sw.m_min << ":" << setw(2) << sw.m_sec;
    return os;
}

int main() {
    stopwatch s1(0,0), s2(0,0);
    s1 = s2++;
    cout << "s1: "<< s1 <<endl;
    cout << "s2: "<< s2 <<endl;
    s1.set_zero();
    s2.set_zero();
    s1 = ++s2;
    cout << "s1: "<< s1 <<endl;
    cout << "s2: "<< s2 <<endl;
    return 0;
}