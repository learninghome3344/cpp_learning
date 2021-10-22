#include <iostream>
#include <string>
using namespace std;


/// 一旦将对象定义为常对象之后，不管是哪种形式，该对象就只能访问被 const 修饰的成员了
/// （包括 const 成员变量和 const 成员函数），
/// 因为非 const 成员可能会修改对象的数据（编译器也会这样假设），C++禁止这样做。

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

void Student::show() {
    cout << this->get_name() << " " << this->get_age() << " " << this->get_score() << endl;
}

int main() {
    const Student stu("li_si", 19, 98);
    // const_object.cpp:40:5: error: 'this' argument to member function 'show' has type 'const Student', but function is not marked const
    // stu.show();
    cout << stu.get_name() << " " << stu.get_age() << " " << stu.get_score() << endl;

    const Student* p_stu = new Student("zhang_san", 18, 100);
    cout << p_stu->get_name() << " " << p_stu->get_age() << " " << p_stu->get_score() << endl;
}