#include <iostream>
#include <string>
using namespace std;


/// 继承和派生的一个基本例子

class People {
public:
    void set_name(string name);
    void set_age(int age);
    string get_name();
    int get_age();

private:
    string m_name;
    int m_age;
};

void People::set_name(string name) { m_name = name; }
void People::set_age(int age) { m_age = age; }
string People::get_name() {return m_name; }
int People::get_age() {return m_age; }

class Student: public People {
public:
    void set_score(float score);
    float get_score();

private:
    float m_score;
};

void Student::set_score(float score) { m_score = score; }
float Student::get_score() {return m_score; }

int main() {
    Student stu;
    stu.set_name("xiaoming");
    stu.set_age(20);
    stu.set_score(98.3);
    cout << stu.get_name() << " " << stu.get_age() << " " << stu.get_score() << endl;
}