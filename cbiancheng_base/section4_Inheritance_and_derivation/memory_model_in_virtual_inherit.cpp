#include <iostream>
using namespace std;

/// http://c.biancheng.net/view/vip_2282.html

/// 对于普通继承，基类子对象始终位于派生类对象的前面（也即基类成员变量始终在派生类成员变量的前面），而且不管继承层次有多深，它相对于派生类对象顶部的偏移量是固定的
/// 对于虚继承，不管是虚基类的直接派生类还是间接派生类，虚基类的子对象始终位于派生类对象的最后面。

/// VC 引入了虚基类表，如果某个派生类有一个或多个虚基类，编译器就会在派生类对象中安插一个指针，指向虚基类表。虚基类表其实就是一个数组，数组中的元素存放的是各个虚基类的偏移。


class A{
protected:
    int m_a1;
    int m_a2;
};

class B: public A{
protected:
    int b1;
    int b2;
};

class C: public B{
protected:
    int c1;
    int c2;
};

class D: public C{
protected:
    int d1;
    int d2;
};

int main(){
    A obj_a;
    B obj_b;
    C obj_c;
    D obj_d;

    return 0;
}