#include <iostream>
#include "point.h"
using namespace std;


/// 前面讲到的模板的实例化是在调用函数或者创建对象时由编译器自动完成的，不需要程序员引导，因此称为隐式实例化。
/// 对应的，我们也可以通过代码明确地告诉编译器需要针对哪个类型进行实例化，这称为显式实例化。

/// 显式实例化的一个好处是，可以将模板的声明和定义（实现）分散到不同的文件中了。
/// 显式实例化也包括声明和定义，定义要放在模板定义（实现）所在的源文件，声明要放在模板声明所在的头文件（当然也可以不写）。


/// 注：根据我的实际test，这种方法会报错，
/// 且原文总结说
/// 如果我们开发的模板只有我们自己使用，那也可以勉强使用显式实例化；如果希望让其他人使用（例如库、组件等），那只能将模板的声明和定义都放到头文件中了。
/// *****因此以后模板的声明和定义都放在头文件中。*****

//// ld: symbol(s) not found for architecture x86_64
//// collect2: error: ld returned 1 exit status


extern template class Point<char*, char*>;
extern template class Point<int, int>;
int main(){
    Point<int, int> p1(10, 20);
    p1.setX(40);
    p1.setY(50);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
    Point<char*, char*> p2("东京180度", "北纬210度");
    p2.display();
    return 0;
}