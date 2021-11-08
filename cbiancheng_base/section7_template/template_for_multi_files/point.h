#include <iostream>
using namespace std;

#ifndef _POINT_H
#define _POINT_H
template<class T1, class T2>
class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const{ return m_x; }
    void setX(T1 x){ m_x = x; }
    T2 getY() const{ return m_y; };
    void setY(T2 y){ m_y = y; };
    void display() const;
private:
    T1 m_x;
    T2 m_y;
};

// 声明和定义需要在一个文件中
template<class T1, class T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}
#endif