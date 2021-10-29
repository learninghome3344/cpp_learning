#include <cstdio>


/// 有继承关系时，派生类的内存模型可以看成是基类成员变量和新增成员变量的总和，而所有成员函数仍然存储在另外一个区域——代码区，由所有对象共享
/// 基类的成员变量排在前面，派生类的排在后面。
/// 当基类的成员变量被遮蔽时，仍然会留在派生类对象的内存中，派生类新增的成员变量始终排在基类的后面。


//基类A
class A{
public:
    A(int a, int b);
public:
    void display();
protected:
    int m_a;
    int m_b;
};

A::A(int a, int b): m_a(a), m_b(b){}
void A::display(){
    printf("m_a=%d, m_b=%d\n", m_a, m_b);
}

class B: public A{
public:
    B(int a, int b, int c);
    void display();
protected:
    int m_c;
};

B::B(int a, int b, int c): A(a, b), m_c(c){ }
void B::display(){
    printf("m_a=%d, m_b=%d, m_c=%d\n", m_a, m_b, m_c);
}

class C: public B{
public:
    C(char a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};

C::C(char a, int b, int c, int d): B(a, b, c), m_d(d){ }
void C::display(){
    printf("m_a=%d, m_b=%d, m_c=%d, m_d=%d\n", m_a, m_b, m_c, m_d);
}

class D: public B{
public:
    D(char a, int b, int c, int d);
public:
    void display();
private:
    int m_b;
    int m_c;
    int m_d;
};

D::D(char a, int b, int c, int d): B(a, b, c), m_b(b+66), m_c(c+66), m_d(d){ }
void D::display(){
    printf("A::m_a=%d, A::m_b=%d, B::m_c=%d\n", m_a, A::m_b, B::m_c);
    printf("D::m_b=%d, D::m_c=%d, D::m_d=%d\n", m_b, m_c, m_d);
}

int main(){
    A obj_a(99, 10);
    B obj_b(84, 23, 95);
    C obj_c(11, 22, 33, 44);
    D obj_d(11, 22, 33, 44);
    obj_a.display();
    obj_b.display();
    obj_c.display();
    obj_d.display();
    return 0;
}