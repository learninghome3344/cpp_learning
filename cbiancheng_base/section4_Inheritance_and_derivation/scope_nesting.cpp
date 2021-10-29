#include <iostream>
using namespace std;


/// scope nesting: 作用域嵌套
/// 类其实也是一种作用域，基类是外层作用域，派生类是内层作用域
/// 当存在继承关系时，派生类的作用域嵌套在基类的作用域之内，如果一个名字在派生类的作用域内无法找到，编译器会继续到外层的基类作用域中查找该名字的定义。
/// 这就是名字遮蔽的本质

class A {
public:
    void func();
    int n;
};

void A::func() { cout << "c.biancheng.net" << endl; }

class B: public A {
public:
    int x;
    int n;
};

class C: public B {
public:
    int y;
    int n;
};


int main() {
    C obj;
    obj.n = 2;
    cout << obj.n << endl;
    obj.func();
    cout << sizeof(C) << endl;  // 4(int) * 5 = 20
}