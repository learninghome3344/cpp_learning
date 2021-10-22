#include <iostream>
#include <string>
using namespace std;


class Student {
public:
    Student(string name, int age, float score);
    void show();

    static int m_total;

private:
    string m_name;
    int m_age;
    float m_score;
};

int Student::m_total = 0;

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) {
    m_total++;
}

void Student::show() {
    cout << m_name << " " << m_age << " " << m_score << " total_num: " << m_total << endl;
}

int main() {    
    Student* p_stu1 = new Student("zhang_san", 10, 100);
    p_stu1->show();
    Student* p_stu2 = new Student("zhang_san", 10, 100);
    p_stu2->show();
    cout << Student::m_total << endl;
    
}