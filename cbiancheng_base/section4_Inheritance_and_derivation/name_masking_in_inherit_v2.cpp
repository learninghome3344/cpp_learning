#include<iostream>
using namespace std;


/// 基类成员函数和派生类成员函数不构成重载
/// 基类成员和派生类成员的名字一样时会造成遮蔽，这句话对于成员变量很好理解，对于成员函数要引起注意，不管函数的参数如何，只要名字一样就会造成遮蔽。
/// 换句话说，基类成员函数和派生类成员函数不会构成重载，如果派生类有同名函数，那么就会遮蔽基类中的所有同名函数，不管它们的参数是否一样。


//基类Base
class Base{
public:
    void func();
    void func(int);
};
void Base::func(){ cout<<"Base::func()"<<endl; }
void Base::func(int a){ cout<<"Base::func(int)"<<endl; }

//派生类Derived
class Derived: public Base{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *str){ cout<<"Derived::func(char *)"<<endl; }
void Derived::func(bool is){ cout<<"Derived::func(bool)"<<endl; }

int main(){
    Derived d;
    d.func("c.biancheng.net");
    d.func(true);
    // d.func();  //compile error
    // d.func(10);  //compile error
    d.Base::func();
    d.Base::func(100);

    return 0;
}