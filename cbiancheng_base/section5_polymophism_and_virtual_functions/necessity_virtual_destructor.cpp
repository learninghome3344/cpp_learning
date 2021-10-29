#include <iostream>
using namespace std;

//基类
class Base{
public:
    Base();
    virtual ~Base();
protected:
    char *str;
};
Base::Base(){
    str = new char[100];
    cout<<"Base constructor"<<endl;
}
Base::~Base(){
    delete[] str;
    cout<<"Base destructor"<<endl;
}

//派生类
class Derived: public Base{
public:
    Derived();
    ~Derived();
private:
    char *name;
};
Derived::Derived(){
    name = new char[100];
    cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
    delete[] name;
    cout<<"Derived destructor"<<endl;
}

int main(){

    /// delete pb;不会调用派生类的析构函数
    /// 因为通过指针访问非虚函数时，编译器会根据指针的类型来确定要调用的函数
    /// pb 是基类的指针，所以不管它指向基类的对象还是派生类的对象，始终都是调用基类的析构函数。

    Base *pb = new Derived();
    delete pb;

    cout<<"-------------------"<<endl;

    Derived *pd = new Derived();
    delete pd;

    return 0;
}