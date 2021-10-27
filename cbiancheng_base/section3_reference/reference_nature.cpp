#include <iostream>
#include <iomanip>
using namespace std;

// 引用的后续知识过于生僻，暂时只了解到 「掌握一般用法，及编译器实际内部处理为指针的原理」 这一步

/*
引用只是对指针进行了简单的封装，它的底层依然是通过指针实现的，引用占用的内存和指针占用的内存长度一样
之所以不能获取引用的地址，是因为编译器进行了内部转换

int a = 99;
int &r = a;
r = 18;

------------>

int a = 99;
int *r = &a;
*r = 18;

&r：取r的地址自动变为&a取a的地址
因此不是变量 r 不占用内存，而是编译器不让获取它的地址
*/

/* 
引用作为函数参数时也同样进行转换
//定义函数
void swap(int &r1, int &r2){
    int temp = r1;
    r1 = r2;
    r2 = temp;
}
//调用函数
int num1 = 10, num2 = 20;
swap(num1, num2);

------------->

//定义函数
void swap(int *r1, int *r2){
    int temp = *r1;
    *r1 = *r2;
    *r2 = temp;
}
//调用函数
int num1 = 10, num2 = 20;
swap(&num1, &num2);
*/

/*
引用和指针的其他区别
1. 引用必须在定义时初始化，并且以后也要从一而终，不能再指向其他数据；而指针没有这个限制，指针在定义时不必赋值，以后也能指向任意数据
2. 可以有 const 指针，但是没有 const 引用
3. 指针可以有多级，但是引用只能有一级，例如，int **p是合法的，而int &&r是不合法的
4. 指针和引用的自增（++）自减（--）运算意义不一样。对指针使用 ++ 表示指向下一份数据，对引用使用 ++ 表示它所指代的数据本身加 1；自减（--）也是类似的道理
*/


int num = 99;

class A{
public:
    A();
    int get_n() { return n; }
    int get_r() { return r; }
private:
    int n;
    int &r; // 不是变量 r 不占用内存，而是编译器不让获取它的地址。
};

A::A(): n(1), r(num){}

int main (){
    A *a = new A();
    cout << sizeof(a) << " " << sizeof(num) << endl; // a占8个字节，num占4个字节，说明n和r各占四个字节，说明引用本质上占内存

    // hex表示以十六进制输出，showbase表示添加十六进制前缀0x
    // 成员变量 r 是 private 属性的，不能直接通过对象来访问，但是借助强大的指针和类型转换，我们依然可以得到它的内容，只不过这种方法有点蹩脚
    cout << hex << showbase << *((int*)a + 1) << endl;  //输出r本身的内容

    cout << &num << endl;
    return 0;
}