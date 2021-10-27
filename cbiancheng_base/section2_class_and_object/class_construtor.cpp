#include <iostream>
using namespace std;

class Student
{
private:
    char* m_name;
    int m_age;
    float m_score;

public:
    Student(char* name, int age, float score);
    void show();
};

Student::Student(char* name, int age, float score): m_name(name), m_age(age), m_score(score) {

}

void Student::show() {
    cout << m_name << " " << m_age << " " << m_score << endl;
}

int main() {
    Student stu("xiaoming", 19, 91);
    stu.show();

    Student *stu2 = new Student("xiaohong", 18, 59);
    stu2->show();
}