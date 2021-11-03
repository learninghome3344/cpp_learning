#include <iostream>
#include <string>
using namespace std;


/// 函数的调用规则
//// 在 C++ 中，对于给定的函数名，可以有非模板函数、模板函数、显示具体化模板函数以及它们的重载版本，
//// 在调用函数时，显示具体化优先于常规模板，而非模板函数优先于显示具体化和常规模板。

typedef struct{
    string name;
    int age;
    float score;
} STU;

// 函数模板
template<class T> const T& Max(const T& a, const T& b);
// 函数模板的显式具体化（针对STU类型的显式具体化） 
/// 1. 模板只有一个类型参数T，已经被具体化为STU了，这样整个模板就不需要类型参数了，类型参数列表为空
/// 2. Max<STU>中的STU是可选的，因为函数的形参已经表明，这是 STU 类型的一个具体化
// template<> const STU& Max<STU>(const STU& a, const STU& b);
template<> const STU& Max(const STU& a, const STU& b);
// 重载<<
ostream & operator<<(ostream &out, const STU &stu);

int main(){
    int a = 10;
    int b = 20;
    cout<<Max(a, b)<<endl;

    STU stu1 = { "王明", 16, 95.5};
    STU stu2 = { "徐亮", 17, 90.0};
    cout<<Max(stu1, stu2)<<endl;

    return 0;
}

template<class T> const T& Max(const T& a, const T& b){
    return a > b ? a : b;
}

template<> const STU& Max<STU>(const STU& a, const STU& b){
    return a.score > b.score ? a : b;
}

ostream & operator<<(ostream &out, const STU &stu){
    out<<stu.name<<" , "<<stu.age <<" , "<<stu.score;
    return out;
}