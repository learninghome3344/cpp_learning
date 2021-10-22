#include <iostream>
#include <string>
using namespace std;


/// normal member functions implicitly add a formal parameter, but static member functions not.
/// so static memeber function can not visit normal member functions and variables, can only visit static member variables and functions.


class Student {
public:
    Student(string name, int age, float score);
    void show();

private:
    static int m_total_amount;
    static float m_total_score;

public:
    static float get_total_score();
    static int get_total_amount();

private:
    string m_name;
    int m_age;
    float m_score;
};

int Student::m_total_amount = 0;
float Student::m_total_score = 0.05;

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) {
    m_total_amount++;
    m_total_score += score;
}

void Student::show() {
    cout << m_name << " " << m_age << " " << m_score << ";  " << m_total_amount << " " << m_total_score << endl;
}

float Student::get_total_score() {
    return Student::m_total_score;
}

int Student::get_total_amount() {
    return Student::m_total_amount;
}

int main() {
    Student* p_stu1 = new Student("zhang_san", 10, 100);
    p_stu1->show();
    cout << Student::get_total_amount() << " " << Student::get_total_score() << endl;
    Student* p_stu2 = new Student("zhang_san", 10, 100);
    p_stu2->show();
    cout << Student::get_total_amount() << " " << Student::get_total_score() << endl;
}
