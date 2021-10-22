#include <iostream>
#include <string>
using namespace std;


/// this指针是一个const指针，指向当前对象，通过它可以访问当前对象的所有成员
/// this指针只能用在类的内部，通过this可以访问类的所有成员

class Student {
public:
    void set_name(string name);
    void set_age(int age);
    void set_score(float score);
    void show();

private:
    string m_name;
    int m_age;
    float m_score;
};

void Student::set_name(string name) {
    this->m_name = name;
}

void Student::set_age(int age) {
    this->m_age = age;
}

void Student::set_score(float score) {
    this->m_score = score;
}

void Student::show() {
    cout << this->m_name << " " << this->m_age << " " << this->m_score << endl;
}

int main() {

    Student *stu = new Student;
    stu->set_name("zhang_san");
    stu->set_age(18);
    stu->set_score(92.1);
    stu->show();

    return 0;
}