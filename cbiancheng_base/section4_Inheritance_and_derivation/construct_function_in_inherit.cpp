#include <iostream>
using namespace std;


/// 基类的普通成员函数可以被继承，可以通过派生类的对象访问，但是基类的构造函数不能被继承。
/// 构造函数不能被继承是有道理的，因为即使继承了，它的名字和派生类的名字也不一样，不能成为派生类的构造函数，当然更不能成为普通的成员函数。

/// 对继承过来的成员变量的初始化工作也要由派生类的构造函数完成，但是大部分基类都有 private 属性的成员变量，它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。
/// 这种矛盾在C++继承中是普遍存在的，解决这个问题的思路是：在派生类的构造函数中调用基类的构造函数。


class People {
public:
    People(char* name, int age);
    char* get_name() { return m_name; }
    int get_age() { return m_age; }

private:
    char* m_name;
    int m_age;
};

People::People(char* name, int age): m_name(name), m_age(age) { }

class Student: public People {
public:
    Student(char* name, int age, float score);
    void display();

private:
    float m_score;
};

// 派生类构造函数总是先调用基类构造函数再执行其他代码（包括参数初始化表以及函数体中的代码），不论基类构造函数的位置在前还是在后。
// 基类构造函数的调用放在函数头部，不能放在函数体中。
// 派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类的
Student::Student(char* name, int age, float score): People(name, age), m_score(score) { }
void Student::display() {
    cout << get_name() << " " << get_age() << " " << m_score << endl;
}

int main() {
    Student stu("zhangsan", 19, 80);
    stu.display();
}