#include <iostream>
#include <string>
using namespace std;


/// 借助friend，可以使得其他类中的成员函数以及全局范围内的函数访问当前类的 private 成员
/// 友元函数不同于类的成员函数，在友元函数中不能直接访问类的成员，必须要借助对象
/// 在当前类以外定义的、不属于当前类的函数也可以在类中声明，但要在前面加 friend 关键字，友元函数可以是不属于任何类的非成员函数，也可以是其他类的成员函数。
/// show_type1是不属于任何类的非成员函数，show_type2是属于另一个类的成员函数

class Address;

class Student {
public:
    Student(string name, int age, float score);
    friend void show_type1(Student* p_stu); // show_type1是一个全局函数(非成员函数)
    void show_type2(Address* p_addr);

private:
    string m_name;
    int m_age;
    float m_score;
};

class Address {
public:
    Address(string province, string city, string district);
    friend void Student::show_type2(Address* p_addr);  // show_type2是另一个类Student的成员函数

private:
    string m_province;
    string m_city;
    string m_district;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }
Address::Address(string province, string city, string district): m_province(province), m_city(city), m_district(district) { }


void show_type1(Student* p_stu) {
    cout << p_stu->m_name << " " << p_stu->m_age << " " << p_stu->m_score << " " << endl;
}

void Student::show_type2(Address* p_addr) {
    cout << m_name << " " << m_age << " " << m_score << "\t" << p_addr->m_province << "/" << p_addr->m_city << "/" << p_addr->m_district << endl;
}

int main() {
    Student* p_stu = new Student("zhang_san", 18, 100);
    show_type1(p_stu);
    Address* p_addr = new Address("hebei", "lubei", "gangyao");
    p_stu->show_type2(p_addr);

}