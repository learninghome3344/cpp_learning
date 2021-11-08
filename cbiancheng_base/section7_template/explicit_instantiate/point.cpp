#include <iostream>
#include "point.h"
using namespace std;


template<class T1, class T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}
//显式实例化定义
template class Point<char*, char*>;
template class Point<int, int>;