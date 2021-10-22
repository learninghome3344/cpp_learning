#include <iostream>
#include <string>
using namespace std;

/// 不仅可以将一个函数声明为一个类的“朋友”，还可以将整个类声明为另一个类的“朋友”，这就是友元类。
/// 友元类中的所有成员函数都是另外一个类的友元函数。
/// 将Student类声明为Address类的友元类

/// 友元的关系是单向的而不是双向的
/// Student类是Address类的友元类，不等于Address类是Student类的友元
/// Student类中的成员函数可以访问Address类的private成员，Address类中的成员函数不能访问Student类中的private成员

/// 友元的关系不能传递。如果类 B 是类 A 的友元类，类 C 是类 B 的友元类，不等于类 C 是类 A 的友元类。

class Address;

class Student {
public:
    Student(string name, int age, float score);
    void show(Address* p_addr);

private:
    string m_name;
    int m_age;
    float m_score;
};

class Address {
public:
    Address(string province, string city, string district);
    friend class Student;

private:
    string m_province;
    string m_city;
    string m_district;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }
Address::Address(string province, string city, string district): m_province(province), m_city(city), m_district(district) { }


void Student::show(Address* p_addr) {
    cout << m_name << " " << m_age << " " << m_score << "\t" << p_addr->m_province << "/" << p_addr->m_city << "/" << p_addr->m_district << endl;
}

int main() {
    Student* p_stu = new Student("zhang_san", 18, 100);
    Address* p_addr = new Address("hebei", "lubei", "gangyao");
    p_stu->show(p_addr);

}