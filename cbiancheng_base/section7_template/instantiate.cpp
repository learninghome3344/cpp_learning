#include <iostream>
using namespace std;

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

template<class T1, class T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}

int main(){
    Point<int, int> p1(10, 20);
    p1.setX(40);
    p1.setY(50);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;

    Point<char*, char*> p2("东京180度", "北纬210度");
    p2.display();

    return 0;
}