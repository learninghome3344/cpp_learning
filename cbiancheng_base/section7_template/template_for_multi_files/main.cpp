#include <iostream>
#include "point.h"
using namespace std;


/// 不能将模板的声明和定义分散到多个文件中」的根本原因是：模板的实例化是由编译器完成的，而不是由链接器完成的，这可能会导致在链接期间找不到对应的实例。


int main(){
    Point<int, int> p1(10, 20);
    p1.setX(40);
    p1.setY(50);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
    Point<char*, char*> p2("东京180度", "北纬210度");
    p2.display();
    return 0;
}