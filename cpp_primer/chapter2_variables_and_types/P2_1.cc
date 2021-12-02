#include <iostream>
using namespace std;


extern int i1 = 1; // 声明并定义i1，赋初值抵消了extern关键字的作用
extern int i2; // 声明i2而非定义i2
int i3; // 声明并定义i3

int main() {
    // 算术表达式既有无符号数又有int，int会转为无符号数参与计算。
    unsigned u = 10;
    int i = -42;  // -42 % 2^32
    cout << i + i << " " << u + i << endl;

    cout << "ha ha "
            "xi xi" << endl;

    char s1 = 'a';
    auto s2 = L'a';  // 添加L前缀，类型变为/wchar_t
    cout << sizeof(s1) << " " << sizeof(s2) << endl;

    cout << "2\115\n" << endl;

    // int a = b = 1; //未定义标识符 "b"C/C++(20)
    int a, b;
    a = b = 1;

    // 在函数体内部如果试图初始化一个extern标记的变量会报错
    // extern int i1 = 1; // 不允许对外部变量的局部声明使用初始值设定项C/C++(2442)

    // 变量能且只能被定义一次，但是可以被多次声明。
}