#include <iostream>
#include <string>
using namespace std;


// there is only one way to initialize const member variable, that is the initialized list of the constructed function.
// 函数开头的 const 用来修饰函数的返回值，表示返回值是 const 类型，也就是不能被修改，例如const string get_name()。
// 函数头部的结尾加上 const 表示常成员函数，这种函数只能读取成员变量的值，而不能修改成员变量的值，例如string getname() const。

class Student {
public:
    Student(string name, int age, float score);
    void show();

    string get_name() const;
    int get_age() const;
    float get_score() const;

private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }

string Student::get_name() const {
    return m_name;
}

int Student::get_age() const {
    return m_age;
}

float Student::get_score() const {
    return m_score;
}

int main() {
    Student* p_stu = new Student("zhang_san", 18, 100);
    cout << p_stu->get_name() << " " << p_stu->get_age() << " " << p_stu->get_score() << endl;
}