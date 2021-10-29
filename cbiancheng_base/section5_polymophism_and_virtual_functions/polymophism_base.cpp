#include <iostream>
using namespace std;


/// “多态（polymorphism）”指的是同一名字的事物可以完成不同的功能。
/// 多态可以分为编译时的多态和运行时的多态。前者主要是指函数的重载（包括运算符的重载）、对重载函数的调用，在编译时就能根据实参确定应该调用哪个函数，因此叫编译时的多态；
/// 而后者则和继承、虚函数等概念有关，是本章要讲述的内容。本教程后面提及的多态都是指运行时的多态。


/// 有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。
/// 换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为多态（Polymorphism）。

/// C++提供多态的目的是：可以通过基类指针对所有派生类（包括直接派生和间接派生）的成员变量和成员函数进行“全方位”的访问，尤其是成员函数。如果没有多态，我们只能访问成员变量。
/// 前面我们说过，通过指针调用普通的成员函数时会根据指针的类型（通过哪个类定义的指针）来判断调用哪个类的成员函数，
/// 但是通过本节的分析可以发现，这种说法并不适用于虚函数，虚函数是根据指针的指向来调用的，指针指向哪个类的对象就调用哪个类的虚函数。


//基类People
class People{
public:
    People(char *name, int age);
    virtual void display();
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    virtual void display();
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
    /*
    我们直观上认为，如果指针指向了派生类对象，那么就应该使用派生类的成员变量和成员函数，这符合人们的思维习惯。
    但是本例的运行结果却告诉我们，当基类指针 p 指向派生类 Teacher 的对象时，
    虽然使用了 Teacher 的成员变量，但是却没有使用它的成员函数，导致输出结果不伦不类（赵宏佳本来是一名老师，输出结果却显示人家是个无业游民），不符合我们的预期。
    换句话说，通过基类指针只能访问派生类的成员变量，但是不能访问派生类的成员函数。
    为了消除这种尴尬，让基类指针能够访问派生类的成员函数，C++ 增加了虚函数（Virtual Function）

    王志刚今年23岁了，是个无业游民。
    赵宏佳今年45岁了，是个无业游民。

    在基类的display函数前加了virtual关键字后

    王志刚今年23岁了，是个无业游民。
    赵宏佳今年45岁了，是一名教师，每月有8200元的收入。
    */

    People *p = new People("王志刚", 23);
    p -> display(); 
    p = new Teacher("赵宏佳", 45, 8200);
    p -> display(); 

    // 引用同样可以实现多态
    People p1("王志刚", 23);
    Teacher t("赵宏佳", 45, 8200);
    People &rp = p1;
    People &rt = t;
    rp.display();
    rt.display();


    return 0;
}