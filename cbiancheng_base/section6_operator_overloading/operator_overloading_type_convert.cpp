#include <iostream>
using namespace std;

/// 重载()  强制类型转换运算符

/*
在 C++ 中进行运算符重载时，有以下问题需要注意：
重载后运算符的含义应该符合原有用法习惯。例如重载+运算符，完成的功能就应该类似于做加法，在重载的+运算符中做减法是不合适的。此外，重载应尽量保留运算符原有的特性。
C++ 规定，运算符重载不改变运算符的优先级。
以下运算符不能被重载：.、.*、::、? :、sizeof。
重载运算符()、[]、->、或者赋值运算符=时，只能将它们重载为成员函数，不能重载为全局函数。
*/

/// 运算符重载的实质是将运算符重载为一个函数，使用运算符的表达式就被解释为对重载函数的调用。
/// 类型的名字可以作为强制类型转换运算符，也可以被重载为类的成员函数。它能使得对象被自动转换为某种类型。



class Complex
{
    double real, imag;
public:
    Complex(double r = 0, double i = 0) :real(r), imag(i) {};
    operator double() { return real; }  //重载强制类型转换运算符 double
};
int main()
{
    Complex c(1.2, 3.4);
    cout << (double)c << endl;  //输出 1.2
    double n = 2 + c;  //等价于 double n = 2 + c. operator double()
    cout << n;  //输出 3.2
}