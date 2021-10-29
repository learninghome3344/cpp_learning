#include <iostream>
using namespace std;

/*
1) 只需要在虚函数的声明处加上 virtual 关键字，函数定义处可以加也可以不加。
2) 为了方便，你可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。
3) 当在基类中定义了虚函数时，如果派生类没有定义新的函数来遮蔽此函数，那么将使用基类的虚函数。
4) 只有派生类的虚函数覆盖基类的虚函数（函数原型相同）才能构成多态（通过基类指针访问派生类函数）。
    例如基类虚函数的原型为virtual void func();，派生类虚函数的原型为virtual void func(int);
    那么当基类指针 p 指向派生类对象时，语句p -> func(100);将会出错，而语句p -> func();将调用基类的函数。
5) 构造函数不能是虚函数。对于基类的构造函数，它仅仅是在派生类构造函数中被调用，这种机制不同于继承。也就是说，派生类不继承基类的构造函数，将构造函数声明为虚函数没有什么意义。
6) 析构函数可以声明为虚函数，而且有时候必须要声明为虚函数，这点我们将在下节中讲解。necessity_virtual_destructor.cpp
*/

/// 多态是指通过基类的指针既可以访问基类的成员，也可以访问派生类的成员。
/// 构成多态的条件：
//// 必须存在继承关系；
//// 继承关系中必须有同名的虚函数，并且它们是覆盖关系（函数原型相同）。
//// 存在基类的指针，通过该指针调用虚函数。

//基类Base
class Base{
public:
    virtual void func();
    virtual void func(int);
};
void Base::func(){
    cout<<"void Base::func()"<<endl;
}
void Base::func(int n){
    cout<<"void Base::func(int)"<<endl;
}

//派生类Derived
class Derived: public Base{
public:
    void func();
    void func(char *);
};
void Derived::func(){
    cout<<"void Derived::func()"<<endl;
}
void Derived::func(char *str){
    cout<<"void Derived::func(char *)"<<endl;
}

int main(){
    Base *p = new Derived();
    p -> func();  //输出void Derived::func()
    p -> func(10);  //输出void Base::func(int)
    // p -> func("http://c.biancheng.net");  //compile error.因为通过基类的指针只能访问从基类继承过去的成员，不能访问派生类新增的成员。

    return 0;
}