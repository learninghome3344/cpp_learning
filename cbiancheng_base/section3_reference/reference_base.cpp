#include <iostream>
#include <string>
using namespace std;


// type &name = data;


void swap1(int a, int b);
void swap2(int *p1, int *p2);
void swap3(int &r1, int &r2);

int& plus10(int& r) {
    r += 10;
    return r;
    // 返回局部变量的引用
    // int m = r + 10;
    // return m;
}


int main() {
    int a = 99;
    int& b = a;
    b = 22;
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;

    // 不希望通过引用修改原始数据
    // const type &name = value; 或者 type const &name = value;

    // 引用作为函数参数
    int num1, num2;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap1(num1, num2);
    cout << num1 << " " << num2 << endl;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap2(&num1, &num2);
    cout << num1 << " " << num2 << endl;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap3(num1, num2);
    cout << num1 << " " << num2 << endl;

    // 引用作为函数返回值
    int x = 10;
    int& y = plus10(x);
    cout << x << " " << y << " " << &x << " " << &y << endl;
    // 引用作为函数返回值时不能返回局部数据的引用。因为函数调用完局部数据就会被销毁
    int& num3 = plus10(x);
    int& num4 = plus10(num3);
    cout << num3 << " " << num4 << " " << &num3 << " " << &num4 << endl;
}

//直接传递参数内容
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
//传递指针
void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//按引用传参
void swap3(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}