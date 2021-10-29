#include<iostream>
using namespace std;


/// 如果派生类中的成员（包括成员变量和成员函数）和基类中的成员重名，那么就会遮蔽从基类继承过来的成员

//基类People
class People{
public:
    void show();
protected:
    char *m_name;
    int m_age;
};
void People::show(){
    cout<<"嗨，大家好，我叫"<<m_name<<"，今年"<<m_age<<"岁"<<endl;
}
//派生类Student
class Student: public People{
public:
    Student(char *name, int age, float score);
public:
    void show();  //遮蔽基类的show()
private:
    float m_score;
};
Student::Student(char *name, int age, float score){
    m_name = name;
    m_age = age;
    m_score = score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main() {
    Student stu("张三", 10, 98);
    stu.show();
    stu.People::show();
}