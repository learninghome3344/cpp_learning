#include <iostream>
using namespace std;


/// 将派生类指针赋值给基类指针 | 将派生类引用赋值给基类引用
/// 编译器通过指针来访问成员变量，指针指向哪个对象就使用哪个对象的数据；
/// 编译器通过指针的类型来访问成员函数，指针属于哪个类的类型就使用哪个类的函数


//基类A
class A{
public:
    A(int a);
public:
    void display();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
    cout<<"Class A: m_a="<<m_a<<endl;
}

//中间派生类B
class B: public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
    cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}

//基类C
class C{
public:
    C(int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int c): m_c(c){ }
void C::display(){
    cout<<"Class C: m_c="<<m_c<<endl;
}

//最终派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d): B(a, b), C(c), m_d(d){ }
void D::display(){
    cout<<"Class D: m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}


int main(){
    A *pa = new A(1);
    B *pb = new B(2, 20);
    C *pc = new C(3);
    D *pd = new D(4, 40, 400, 4000);

    pa = pd;
    pa -> display();

    pb = pd;
    pb -> display();

    pc = pd;
    pc -> display();

    /// 将派生类的指针赋值给基类指针，输出的值有可能相等，如pa,pb和pd，也有可能不相等，如pc和pd
    /// 内存模型： m_a m_b m_c m_d
    /// 首先要明确的一点是，对象的指针必须要指向对象的起始位置。
    /// 对于 A 类和 B 类来说，它们的子对象的起始地址和 D 类对象一样，所以将 pd 赋值给 pa、pb 时不需要做任何调整，直接传递现有的值即可；
    /// 而 C 类子对象距离 D 类对象的开头有一定的偏移，将 pd 赋值给 pc 时要加上这个偏移，这样 pc 才能指向 C 类子对象的起始位置。
    /// 也就是说，执行pc = pd;语句时编译器对 pd 的值进行了调整，才导致 pc、pd 的值不同。

    cout<<"-----------------------"<<endl;
    cout<<"pa="<<pa<<endl;
    cout<<"pb="<<pb<<endl;
    cout<<"pc="<<pc<<endl;
    cout<<"pd="<<pd<<endl;



    D d(4, 40, 400, 4000);   
    A &ra = d;
    B &rb = d;
    C &rc = d;
    
    cout<<"-----------------------"<<endl;
    ra.display();
    rb.display();
    rc.display();

    return 0;
}