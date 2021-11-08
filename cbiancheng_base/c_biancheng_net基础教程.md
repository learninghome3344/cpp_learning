# Section1 from c to cpp

## function overloading

函数重载的例子

```c++
#include <iostream>
using namespace std;

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void Swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void Swap(bool &a, bool &b) {
    bool temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 2, b = 1;
    Swap(a, b);
    cout << a << " " << b << endl;

    double c = 0.2, d = 0.1;
    Swap(c, d);
    cout << c << " " << d << endl;
}
```



# Section2 class and object

## constructor

```c++
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
```

## destructor

-   构造函数为数组分配内存，这些内存在数组被销毁后不会自动释放，所以非常有必要再添加一个析构函数，专门用来释放已经分配的内存

```c++
#include <iostream>
using namespace std;

class VariantLenArray {
public:
    VariantLenArray(int len);
    ~VariantLenArray();

    void input();
    void show();

private:
    const int m_len;
    int* m_arr;

    int* at(int i);

};

VariantLenArray::VariantLenArray(int len): m_len(len) {
    m_arr = NULL;
    if (len > 0) {
        m_arr = new int[len];
    }
}

VariantLenArray::~VariantLenArray() {
    delete []m_arr;
}

int* VariantLenArray::at(int i) {
    if (!m_arr || i < 0 || i > m_len) {
        return NULL;
    } else {
        return m_arr + i;
    }
}

void VariantLenArray::input() {
    for (int i = 0; i < m_len; i++) {
        cin >> *at(i);
    }
}

void VariantLenArray::show() {
    for (int i = 0; i < m_len; i++) {
        cout << *at(i) << " ";
    }
    cout << endl;
}

int main() {
    // int n;
    // cin >> n;
    // VariantLenArray vla(n);
    // vla.input();
    // vla.show();

    //创建一个有n个元素的数组（对象）
    int n;
    cout<<"Input array length: ";
    cin>>n;
    VariantLenArray *parr = new VariantLenArray(n);
    //输入数组元素
    cout<<"Input "<<n<<" numbers: ";
    parr -> input();
    //输出数组元素
    cout<<"Elements: ";
    parr -> show();
    //删除数组（对象）
    delete parr;
}
```

## object array(every element of array is object)

```c++
#include<iostream>
using namespace std;

class CSample{
public:
    CSample(){  //构造函数 1
        cout<<"Constructor 1 Called"<<endl;
    }
    CSample(int n){  //构造函数 2
        cout<<"Constructor 2 Called"<<endl;
    }
};

int main(){
    cout<<"step1"<<endl;
    CSample arrayl[2];

    cout<<"step2"<<endl;
    CSample array2[2] = {4, 5};

    cout<<"step3"<<endl;
    CSample array3[2] = {3};

    cout<<"step4"<<endl;
    CSample* array4 = new CSample[2];
    delete [] array4;

    return 0;
}
```

-   注意在构造函数有多个参数时，数组的初始化列表中要显式地包含对构造函数的调用。例如下面的程序：

```c++
class CTest{
public:
    CTest(int n){ }  //构造函数(1)
    CTest(int n, int m){ }  //构造函数(2)
    CTest(){ }  //构造函数(3)
};
int main(){
    //三个元素分别用构造函数(1)、(2)、(3) 初始化
    CTest arrayl [3] = { 1, CTest(1,2) };
    //三个元素分别用构造函数(2)、(2)、(1)初始化
    CTest array2[3] = { CTest(2,3), CTest(1,2), 1};
    //两个元素指向的对象分别用构造函数(1)、(2)初始化
    CTest* pArray[3] = { new CTest(4), new CTest(1,2) };
    return 0;
}
```

## member object and enclosed class

-   一个类的成员变量如果是另一个类的对象，就称之为“成员对象”。包含成员对象的类叫封闭类（enclosed class）。

### member object initialization

-   创建封闭类的对象时，它包含的成员对象也需要被创建，这就会引发成员对象构造函数的调用。如何让编译器知道，成员对象到底是用哪个构造函数初始化的呢？这就需要借助封闭类构造函数的初始化列表。

```c++
#include <iostream>
using namespace std;

//轮胎类
class Tyre{
public:
    Tyre(int radius, int width);
    void show() const;
private:
    int m_radius;  //半径
    int m_width;  //宽度
};
Tyre::Tyre(int radius, int width) : m_radius(radius), m_width(width){ }
void Tyre::show() const {
    cout << "轮毂半径：" << this->m_radius << "吋" << endl;
    cout << "轮胎宽度：" << this->m_width << "mm" << endl;
}

//引擎类
class Engine{
public:
    Engine(float displacement = 2.0);
    void show() const;
private:
    float m_displacement;
};
Engine::Engine(float displacement) : m_displacement(displacement) {}
void Engine::show() const {
    cout << "排量：" << this->m_displacement << "L" << endl;
}

//汽车类
class Car{
public:
    Car(int price, int radius, int width);
    void show() const;
private:
    int m_price;  //价格
    Tyre m_tyre;
    Engine m_engine;
};
Car::Car(int price, int radius, int width): m_price(price), m_tyre(radius, width)/*指明m_tyre对象的初始化方式*/{ };
void Car::show() const {
    cout << "价格：" << this->m_price << "￥" << endl;
    this->m_tyre.show();
    this->m_engine.show();
}

int main()
{
    Car car(200000, 19, 245);
    car.show();
    return 0;
}
```

### member object demise

```c++
#include<iostream>
using namespace std;

class Tyre {
public:
    Tyre() { cout << "Tyre constructor" << endl; }
    ~Tyre() { cout << "Tyre destructor" << endl; }
};

class Engine {
public:
    Engine() { cout << "Engine constructor" << endl; }
    ~Engine() { cout << "Engine destructor" << endl; }
};

class Car {
private:
    Engine engine;
    Tyre tyre;
public:
    Car() { cout << "Car constructor" << endl; }
    ~Car() { cout << "Car destructor" << endl; }
};

int main() {
    Car car;
    return 0;
}
```

## this pointer

-   this指针是一个const指针，指向当前对象，通过它可以访问当前对象的所有成员
-   this指针只能用在类的内部，通过this可以访问类的所有成员

```c++
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    void set_name(string name);
    void set_age(int age);
    void set_score(float score);
    void show();

private:
    string m_name;
    int m_age;
    float m_score;
};

void Student::set_name(string name) {
    this->m_name = name;
}

void Student::set_age(int age) {
    this->m_age = age;
}

void Student::set_score(float score) {
    this->m_score = score;
}

void Student::show() {
    cout << this->m_name << " " << this->m_age << " " << this->m_score << endl;
}

int main() {

    Student *stu = new Student;
    stu->set_name("zhang_san");
    stu->set_age(18);
    stu->set_score(92.1);
    stu->show();

    return 0;
}
```



## static member

-   static member variable

    -   一个类中可以有一个或多个静态成员变量，所有的对象都共享这些静态成员变量，都可以引用它。

    -   static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。

    -   静态成员变量必须初始化，而且只能在类体外进行。例如：

        int Student::m_total = 10;

        初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0。全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。

    -   静态成员变量既可以通过对象名访问，也可以通过类名访问，但要遵循 private、protected 和 public 关键字的访问权限限制。当通过对象名访问时，对于不同的对象，访问的是同一份内存。

```c++
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
```

-   static member function
    -   normal member functions implicitly add a formal parameter, but static member functions not. so static memeber function can not visit normal member functions and variables, can only visit static member variables and functions.

```c++
#include <iostream>
#include <string>
using namespace std;

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

```



## const member

-   there is only one way to initialize const member variable, that is the initialized list of the constructed function.
-   函数开头的 const 用来修饰函数的返回值，表示返回值是 const 类型，也就是不能被修改，例如const string get_name()。
-   函数头部的结尾加上 const 表示常成员函数，这种函数只能读取成员变量的值，而不能修改成员变量的值，例如string getname() const。

```c++
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string name, int age, float score);
    void show();

    string get_name() const;
    int get_age() const;
    float get_score() const;

private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }

string Student::get_name() const {
    return m_name;
}

int Student::get_age() const {
    return m_age;
}

float Student::get_score() const {
    return m_score;
}

int main() {
    Student* p_stu = new Student("zhang_san", 18, 100);
    cout << p_stu->get_name() << " " << p_stu->get_age() << " " << p_stu->get_score() << endl;
}
```



## const object

-   一旦将对象定义为常对象之后，不管是哪种形式，该对象就只能访问被 const 修饰的成员了（包括 const 成员变量和 const 成员函数），因为非 const 成员可能会修改对象的数据（编译器也会这样假设），C++禁止这样做。

```c++
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student(string name, int age, float score);
    void show();

    string get_name() const;
    int get_age() const;
    float get_score() const;

private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }

string Student::get_name() const {
    return m_name;
}

int Student::get_age() const {
    return m_age;
}

float Student::get_score() const {
    return m_score;
}

void Student::show() {
    cout << this->get_name() << " " << this->get_age() << " " << this->get_score() << endl;
}

int main() {
    const Student stu("li_si", 19, 98);
    // const_object.cpp:40:5: error: 'this' argument to member function 'show' has type 'const Student', but function is not marked const
    // stu.show(); // 报错是因为成员变量不是const的，而成员函数是const的，因此可以调用
    cout << stu.get_name() << " " << stu.get_age() << " " << stu.get_score() << endl;

    const Student* p_stu = new Student("zhang_san", 18, 100);
    cout << p_stu->get_name() << " " << p_stu->get_age() << " " << p_stu->get_score() << endl;
}
```



## friend function and class

### friend function

-   借助friend，可以使得其他类中的成员函数以及全局范围内的函数访问当前类的 private 成员
-   友元函数不同于类的成员函数，在友元函数中不能直接访问类的成员，必须要借助对象
-   在当前类以外定义的、不属于当前类的函数也可以在类中声明，但要在前面加 friend 关键字，友元函数可以是不属于任何类的非成员函数，也可以是其他类的成员函数。下面的例子中，show_type1是不属于任何类的非成员函数，show_type2是属于另一个类的成员函数

```c++
#include <iostream>
#include <string>
using namespace std;

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
```

### friend class

-   不仅可以将一个函数声明为一个类的“朋友”，还可以将整个类声明为另一个类的“朋友”，这就是友元类。
-   友元类中的所有成员函数都是另外一个类的友元函数。
-   如下面的例子所示，将Student类声明为Address类的友元类
    -   友元的关系是单向的而不是双向的，Student类是Address类的友元类，不等于Address类是Student类的友元
    -   Student类中的成员函数可以访问Address类的private成员，Address类中的成员函数不能访问Student类中的private成员
    -   友元的关系不能传递。如果类 B 是类 A 的友元类，类 C 是类 B 的友元类，不等于类 C 是类 A 的友元类。

```c++
#include <iostream>
#include <string>
using namespace std;

class Address;

class Student {
public:
    Student(string name, int age, float score);
    void show(Address* p_addr);

private:
    string m_name;
    int m_age;
    float m_score;
};

class Address {
public:
    Address(string province, string city, string district);
    friend class Student;

private:
    string m_province;
    string m_city;
    string m_district;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score) { }
Address::Address(string province, string city, string district): m_province(province), m_city(city), m_district(district) { }


void Student::show(Address* p_addr) {
    cout << m_name << " " << m_age << " " << m_score << "\t" << p_addr->m_province << "/" << p_addr->m_city << "/" << p_addr->m_district << endl;
}

int main() {
    Student* p_stu = new Student("zhang_san", 18, 100);
    Address* p_addr = new Address("hebei", "lubei", "gangyao");
    p_stu->show(p_addr);

}
```



## c++ string 

string类的一些用法

```c++
#include <iostream>
#include <string>
using namespace std;


int main() {
    // 初始化方式
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4 (5, 's');

    // 遍历 下标
    string s = "1234567890";
    for (int i = 0; i < s.length(); ++i) {
        cout << s[i] << ",";
    }
    cout << endl;

    // 转换为c风格字符串, 例如在作为文件路径时必须打开
    cout << s << "\t" << s.c_str() << endl;

    // string的输入输出
    string s5;
    cin >> s5;  //输入字符串
    cout << s5 << endl;  //输出字符串

    // 字符串的拼接，string可以和string，c风格字符，字符数组，单个字符进行拼接
    string s6 = "six ";
    char* s7 = "seven ";
    char s8[] = "eight ";
    char ch = '@';
    cout << s5 + s6 << " " << s5 + s7 << " " << s5 + s8 << " " << s5 + ch << endl;

    // 增删改查
    /// 插入字符串 string& insert (size_t pos, const string& str);
    cout << s << endl;
    s.insert(5, "aaa");
    cout << s << endl;
    /// 删除字符串 string& erase (size_t pos = 0, size_t len = npos);
    s.erase(5, 3);
    cout << s << endl;
    /// 提取子字符串 string substr (size_t pos = 0, size_t len = npos) const;
    cout << s.substr(5, 3) << endl;
    /// 查找字符串find,rfind,find_first_of：find从pos位置往后找，rfind最多查到pos位置,find_first_of查到首次出现的位置
    //// size_t find (const string& str, size_t pos = 0) const;
    //// size_t rfind( const string& str, size_t pos = npos ) const;
    string ss = "678";
    int index = s.find(ss, 2);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    index = s.rfind(ss, 2);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    index = s.find_first_of(ss);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
}
```





# Section3 reference

# Section4 Inheritance and derivation

# Section5 polymophism and virtual function

# Section6 operator overloading

# Section7 template

-   泛型编程

泛型程序设计（generic programming）是一种算法在实现时不指定具体要操作的数据的类型的程序设计方法。
所谓“泛型”，指的是算法只要实现一遍，就能适用于多种数据类型。泛型程序设计方法的优势在于能够减少重复代码的编写。

-   类型的参数化

在C++中，数据的类型也可以通过参数来传递，在函数定义时可以不指明具体的数据类型，当发生函数调用时，编译器可以根据传入的实参自动推断数据类型。这就是类型的参数化。
值（Value）和类型（Type）是数据的两个主要特征，它们在C++中都可以被参数化。

## function template example

```c++
#include <iostream>
using namespace std;

template<typename T> 
void Swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    //交换 int 变量的值
    int n1 = 100, n2 = 200;
    Swap(n1, n2);
    cout<<n1<<", "<<n2<<endl;

    //交换 float 变量的值
    float f1 = 12.5, f2 = 56.93;
    Swap(f1, f2);
    cout<<f1<<", "<<f2<<endl;

    //交换 char 变量的值
    char c1 = 'A', c2 = 'B';
    Swap(c1, c2);
    cout<<c1<<", "<<c2<<endl;

    //交换 bool 变量的值
    bool b1 = false, b2 = true;
    Swap(b1, b2);
    cout<<b1<<", "<<b2<<endl;
    return 0;
}
```

## class template example

-   以坐标为例，一个点的坐标可以是多种数据类型，例如数字或字符串

```c++
#include <iostream>
using namespace std;

template<typename T1, typename T2>  //这里不能有分号
class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const;  //获取x坐标
    void setX(T1 x);  //设置x坐标
    T2 getY() const;  //获取y坐标
    void setY(T2 y);  //设置y坐标
private:
    T1 m_x;  //x坐标
    T2 m_y;  //y坐标
};

template<typename T1, typename T2>  //模板头
T1 Point<T1, T2>::getX() const /*函数头*/ {
    return m_x;
}

template<typename T1, typename T2>
void Point<T1, T2>::setX(T1 x){
    m_x = x;
}

template<typename T1, typename T2>
T2 Point<T1, T2>::getY() const{
    return m_y;
}

template<typename T1, typename T2>
void Point<T1, T2>::setY(T2 y){
    m_y = y;
}

int main(){
    Point<int, int> p1(10, 20);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;

    Point<int, char*> p2(10, "东经180度");
    cout<<"x="<<p2.getX()<<", y="<<p2.getY()<<endl;

    Point<char*, char*> *p3 = new Point<char*, char*>("东经180度", "北纬210度");
    cout<<"x="<<p3->getX()<<", y="<<p3->getY()<<endl;

    return 0;
}
```

使用类模板实现变长数组

```c++
#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class CArray {
public:
    CArray(int size = 0);
    CArray(CArray& carr);
    ~CArray();

    void push_back(const T& val);
    CArray& operator=(const CArray& carr);
    int length() {
        return m_size;
    }
    T& operator[](int i) {
        return m_ptr[i];
    }

private:
    int m_size;
    T* m_ptr;
};

template<typename T>
CArray<T>::CArray(int size): m_size(size) {
    if (size == 0) {
        m_ptr = NULL;
    } else {
        m_ptr = new T[size];
    }
}

template<typename T>
CArray<T>::CArray(CArray& carr) {
    if (!carr.m_ptr) {
        m_ptr = NULL;
        m_size = 0;
        return;
    }

    m_size = carr.m_size;
    m_ptr = new T[m_size];
    memcpy(m_ptr, carr.m_ptr, sizeof(T) * m_size);
}

template<typename T>
CArray<T>::~CArray() {
    if (m_ptr) {
        delete []m_ptr;
    }
}

template<typename T>
CArray<T>& CArray<T>::operator=(const CArray& carr) {
    // avoid a = a;
    if (this == &carr) {
        return *this;
    }
    if (carr.m_ptr == NULL) {
        if (m_ptr) {
            delete []m_ptr;
        }
        m_ptr = NULL;
        m_size = 0;
        return *this;
    }
    if (m_size < carr.m_size) {
        if (m_ptr) {
            delete []m_ptr;
        }
        m_ptr = new T[carr.m_size];
    }
    m_size = carr.m_size;
    memcpy(m_ptr, carr.m_ptr, sizeof(T) * m_size);
    return *this;
}

template<typename T>
void CArray<T>::push_back(const T& val) {
    if (m_ptr) {
        T* tmp_ptr = new T[m_size+1];
        memcpy(tmp_ptr, m_ptr, sizeof(T) * m_size);
        delete []m_ptr;
        m_ptr = tmp_ptr;
    } else {
        m_ptr = new T[1];
    }
    m_ptr[m_size++] = val;
}

int main()
{
    CArray<int> a;
    cout << a.length() << endl;
    cout << endl;

    for(int i = 0;i < 5;++i) {
        a.push_back(i+1);
        cout << i << " " << i+1 << " " << a.length() << endl;
    }
    cout << endl;

    for(int i = 0; i < a.length(); ++i)
        cout << i << " " << a[i] << " " << a.length() << endl;
    cout << endl;   
    return 0;
}
```

## function template overloading

```c++
#include <iostream>
using namespace std;

template<typename T> void Swap(T& a, T& b);
template<typename T> void Swap(T a[], T b[], int len);

template<typename T>
void printArray(T arr[], int len);


int main() {
    int m = 10, n = 99;
    Swap(m, n);
    cout<<m<<", "<<n<<endl;

    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 10, 20, 30, 40, 50 };
    int len = sizeof(a) / sizeof(int);
    Swap(a, b, len);
    printArray(a, len);
    printArray(b, len);

    return 0;
}

template<typename T>
void Swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void Swap(T a[], T b[], int len) {
    T tmp;
    for (int i = 0; i < len; i++) {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

template<typename T>
void printArray(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        if (i == len-1) {
            cout << arr[i] << endl;
        } else {
            cout << arr[i] << " ";
        }
    }
}


```

## argument inference in function template

-   类模板创建对象时，需要显式指明实参，例如

```c++
template<typename T1, typename T2> class Point;

Point<int, int> p1(10, 20);
Point<char*, char*> *p = new Point<char*, char*>("东京180度", "北纬210度");
```

-   调用函数时可以不显式地指明实参

```c++
template<typename T> void Swap(T &a, T &b);

int n1 = 100, n2 = 200;
Swap(n1, n2);
float f1 = 12.5, f2 = 56.93;
Swap(f1, f2);
```

-   对于普通函数（非模板函数），发生函数调用时会对实参的类型进行适当的转换，以适应形参的类型。这些转换包括：
    -   算数转换：例如 int 转换为 float，char 转换为 int，double 转换为 int 等。
    -   派生类向基类的转换：也就是向上转型，请猛击《[C++向上转型（将派生类赋值给基类）](http://c.biancheng.net/view/2284.html)》了解详情。
    -   const 转换：也即将非 const 类型转换为 const 类型，例如将 char * 转换为 const char *。
    -   数组或函数指针转换：如果函数形参不是引用类型，那么数组名会转换为数组指针，函数名也会转换为函数指针。
    -   用户自定的类型转换。
-   模板实参推断过程中的类型转换
    -   const 转换
    -   数组或函数指针转换

-   为函数模板显式地指明实参

下面这种场景必须为函数模板显式地指明实参

```c++
template<typename T1, typename T2> void func(T1 a){
    T2 b;
}
func(10);  // 函数调用失败，因为无法确定T2的类型

// 注意只有尾部（最右）的类型参数的实参可以省略，而且前提是它们可以从传递给函数的实参中推断出来。
// 如果将上面T1 a和T2 b的位置交换下，func<int>(10);就不再报错了。
func<int>(10); // 函数调用失败，因为不能推断出T2的类型。
func<int, int>(10);
```

-   显式地指明实参时可以应用正常的类型转换

```c++
template<typename T> void func(T a, T b);

func(10, 23.5);  //Error
func<float>(20, 93.7);  //Correct
```



## explicit specialization

-   函数的调用规则
    -   在 C++ 中，对于给定的函数名，可以有非模板函数、模板函数、显示具体化模板函数以及它们的重载版本，在调用函数时，显示具体化优先于常规模板，而非模板函数优先于显示具体化和常规模板。

-   explicit specialization
    -   让模板能够针对不同的类型使用不同的算法
    -   函数模板和类模板都可以显式具体化

### explicit specialization in function template

```c++
#include <iostream>
#include <string>
using namespace std;

typedef struct{
    string name;
    int age;
    float score;
} STU;

// 函数模板的显式具体化（针对STU类型的显式具体化）
/// 1. 模板只有一个类型参数T，已经被具体化为STU了，这样整个模板就不需要类型参数了，类型参数列表为空
/// 2. Max<STU>中的STU是可选的，因为函数的形参已经表明，这是 STU 类型的一个具体化
// template<> const STU& Max<STU>(const STU& a, const STU& b);
template<typename T> const T& Max(const T& a, const T& b);
template<> const STU& Max(const STU& a, const STU& b);

ostream & operator<<(ostream &out, const STU &stu);

int main(){
    int a = 10;
    int b = 20;
    cout<<Max(a, b)<<endl;

    STU stu1 = { "王明", 16, 95.5};
    STU stu2 = { "徐亮", 17, 90.0};
    cout<<Max(stu1, stu2)<<endl;

    return 0;
}

// 未显式类型走原始逻辑
template<typename T> const T& Max(const T& a, const T& b){
    return a > b ? a : b;
}

// 显式类型走指定的逻辑
template<> const STU& Max<STU>(const STU& a, const STU& b){
    return a.score > b.score ? a : b;
}

ostream & operator<<(ostream &out, const STU &stu){
    out<<stu.name<<" , "<<stu.age <<" , "<<stu.score;
    return out;
}
```

### explicit specialization in class template

```c++
#include <iostream>
using namespace std;

template<typename T1, typename T2> class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const{ return m_x; }
    void setX(T1 x){ m_x = x; }
    T2 getY() const{ return m_y; }
    void setY(T2 y){ m_y = y; }
    void display() const;
private:
    T1 m_x;
    T2 m_y;
};

template<typename T1, typename T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}

//类模板的显示具体化（针对字符串类型的显示具体化）
template<> class Point<char*, char*>{
public:
    Point(char *x, char *y): m_x(x), m_y(y){ }
public:
    char *getX() const{ return m_x; }
    void setX(char *x){ m_x = x; } 
    char *getY() const{ return m_y; }
    void setY(char *y){ m_y = y; }
    void display() const;
private:
    char *m_x;  //x坐标
    char *m_y;  //y坐标
};

//这里不能带模板头template<>
void Point<char*, char*>::display() const{
    cout<<"x="<<m_x<<" | y="<<m_y<<endl;
}

int main(){
    ( new Point<int, int>(10, 20) ) -> display();
    ( new Point<int, char*>(10, "东京180度") ) -> display();
    ( new Point<char*, char*>("东京180度", "北纬210度") ) -> display();

    return 0;
}
```

### partial params explicit specialization

```c++
#include <iostream>
using namespace std;

template<typename T1, typename T2> class Point{
public:
    Point(T1 x, T2 y): m_x(x), m_y(y){ }
public:
    T1 getX() const{ return m_x; }
    void setX(T1 x){ m_x = x; }
    T2 getY() const{ return m_y; }
    void setY(T2 y){ m_y = y; }
    void display() const;
private:
    T1 m_x;
    T2 m_y;
};

template<typename T1, typename T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}

//类模板的部分显示具体化
template<typename T2> class Point<char*, T2>{
public:
    Point(char *x, T2 y): m_x(x), m_y(y){ }
public:
    char *getX() const{ return m_x; }
    void setX(char *x){ m_x = x; }
    T2 getY() const{ return m_y; }
    void setY(T2 y){ m_y = y; }
    void display() const;
private:
    char *m_x;  //x坐标
    T2 m_y;  //y坐标
};

template<typename T2>  //这里需要带上模板头
void Point<char*, T2>::display() const{
    cout<<"x="<<m_x<<" | y="<<m_y<<endl;
}

int main(){
    ( new Point<int, int>(10, 20) ) -> display();
    ( new Point<char*, int>("东京180度", 10) ) -> display();
    ( new Point<char*, char*>("东京180度", "北纬210度") ) -> display();

    return 0;
}
```



## using nontype params in template

-   C++ 对模板的支持非常自由，模板中除了可以包含类型参数，还可以包含非类型参数
-   非类型参数的类型不能随意指定，它受到了严格的限制，只能是一个整数，或者是一个指向对象或函数的指针（也可以是引用）
-   当非类型参数是一个整数时，传递给它的实参，或者由编译器推导出的实参必须是一个常量表达式；
    -   例如10、2 * 30、18 + 23 - 4等，但不能是n、n + 10、n + m等（n 和 m 都是变量）。
-   当非类型参数是一个指针（引用）时，绑定到该指针的实参必须具有静态的生存期；
    -   换句话说，实参必须存储在虚拟地址空间中的静态数据区。局部变量位于栈区，动态创建的对象位于堆区，它们都不能用作实参。

### using nontype params in function template

```c++
#include <iostream>
using namespace std;

/// *****  int& array[10] 和 int (&array)[10]  *****
/// 对于int& array[10]， array 首先向右结合，即array[10]，整体表示array索引为10的整型变量的引用
/// 对于int (&array)[10]，array首先和&结合，则表示数组array的引用

template<typename T> void Swap(T& a, T& b); // 模板①：交换基本类型的值
template<typename T, unsigned N> void Swap(T (&a)[N], T (&b)[N]); //模板②：交换两个数组

template<typename T, unsigned N> void printArray(T (&arr)[N]);

int main(){
    //交换基本类型的值
    int m = 10, n = 99;
    Swap(m, n);  //匹配模板①
    cout<<m<<", "<<n<<endl;

    //交换两个数组
    int a[5] = { 1, 2, 3, 4, 5 };
    int b[5] = { 10, 20, 30, 40, 50 };
    Swap(a, b);  //匹配模板②
    printArray(a);
    printArray(b);

    return 0;
}

template<typename T> void Swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, unsigned N> void Swap(T (&a)[N], T (&b)[N]){
    T temp;
    for(int i=0; i<N; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<typename T, unsigned N> void printArray(T (&arr)[N]){
    for(int i=0; i<N; i++){
        if(i == N-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
}
```



### using nontype params in class template

```c++
#include <iostream>
#include <cstring>
using namespace std;

template<typename T, int N>
class Array {
public:
    Array();
    ~Array();

    T& operator[](int i);
    int length() const {
        return m_length;
    }
    // 调整数组长度为m_length+n, 如果m_length+n>m_capacity则需要调整容量
    bool capacity(int n);

private:
    int m_length; // 数组当前长度
    int m_capacity; // 数组当前内存容量
    T* m_ptr;
};

template<typename T, int N>
Array<T, N>::Array() {
    m_ptr = new T[N];
    m_capacity = m_length = N;
}

template<typename T, int N>
Array<T, N>::~Array() {
    delete []m_ptr;
}

template<typename T, int N>
T& Array<T, N>::operator[](int i) {
    if (i < 0 || i >= m_length) {
        cout << "Exception: Array index out of bounds!" << endl;
        // 需要写成try...catch的形式
    }
    return m_ptr[i];
}

template<typename T, int N>
bool Array<T, N>::capacity(int n) {
    int len = m_length + n;
    // 增大数组
    if (n > 0) {
        if (len <= m_capacity) {
            m_length = len;
            return true;
        }
        // 多申请点空间，提高效率，扩充长度的2倍是一个合适的数值。
        T* tmp_ptr = new T[m_length + 2 * n * sizeof(T)];
        if (tmp_ptr == NULL) {
            cout << "Exception: Failed to allocate memory" << endl;
            return false;
        }
        memcpy(tmp_ptr, m_ptr, m_length * sizeof(T));
        delete []m_ptr;
        m_ptr = tmp_ptr;
        m_length = len;
        m_capacity = len + n;
        return true;
    }
    // 收缩数组：一种是收缩的过短导致最终长度小于0，则报错；一种是虽然收缩，但是最终数组长度大于0，那么调整数组长度即可。
    if (len < 0) {
        cout << "Exception: Array length is too small" << endl;
        return false;
    }
    m_length = len;
    return true;
}

int main() {
    Array<int, 5> arr;

    //为数组元素赋值
    for(int i=0, len=arr.length(); i<len; i++){
        arr[i] = 2*i;
    }

    //第一次打印数组
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    //扩大容量并为增加的元素赋值
    arr.capacity(8);
    for(int i=5, len=arr.length(); i<len; i++){
        arr[i] = 2*i;
    }

    //第二次打印数组
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //收缩容量
    arr.capacity(-4);

    //第三次打印数组
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
```

## instantiation of template

-   模板并不是真正的函数或类，它仅仅是编译器用来生成函数或类的一张“图纸”。模板不会占用内存，最终生成的函数或者类才会占用内存。
-   由模板生成函数或类的过程叫做模板的实例化（Instantiate），相应地，针对某个类型生成的特定版本的函数或类叫做模板的一个实例（Instantiation）。
-   模板的实例化是按需进行的，用到哪个类型就生成针对哪个类型的函数或类，不会提前生成过多的代码。也就是说，编译器会根据传递给类型参数的实参（也可以是编译器自己推演出来的实参）来生成一个特定版本的函数或类，并且相同的类型只生成一次。实例化的过程也很简单，就是将所有的类型参数用实参代替。

```c++
#include <iostream>
using namespace std;

template<typename T1, typename T2>
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

template<typename T1, typename T2>
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
```

## template in multiple files coiding

-   不管是函数还是类，声明和定义（实现）的分离其实是一回事，都是将函数定义放到其他文件中，最终要解决的问题也只有一个，就是把函数调用和函数定义对应起来（找到函数定义的地址，并填充到函数调用处），而保证完成这项工作的就是链接器。
-   基于传统的编程思维，初学者往往也会将模板（函数模板和类模板）的声明和定义分散到不同的文件中，以期达到「模块化编程」的目的。但事实证明这种做法是不对的，程序员惯用的做法是将模板的声明和定义都放到头文件中。
-   模板并不是真正的函数或类，它仅仅是用来生成函数或类的一张“图纸”，在这个生成过程中有三点需要明确：
    -   模板的实例化是按需进行的，用到哪个类型就生成针对哪个类型的函数或类，不会提前生成过多的代码；
    -   模板的实例化是由编译器完成的，而不是由链接器完成的；
    -   在实例化过程中需要知道模板的所有细节，包含声明和定义。

-   不能将模板的声明和定义分散到多个文件中」的根本原因是：模板的实例化是由编译器完成的，而不是由链接器完成的，这可能会导致在链接期间找不到对应的实例。

example

point.h

```c++
#include <iostream>
using namespace std;

#ifndef _POINT_H
#define _POINT_H
template<typename T1, typename T2>
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
template<typename T1, class T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}
#endif
```

point.cpp

```c++
#include <iostream>
#include "point.h"
using namespace std;


// 需要和声明放在一起
// template<typename T1, class T2>
// void Point<T1, T2>::display() const{
//     cout<<"x="<<m_x<<", y="<<m_y<<endl;
// }
```

main.cpp

```c++
#include <iostream>
#include "point.h"
using namespace std;

int main(){
    Point<int, int> p1(10, 20);
    p1.setX(40);
    p1.setY(50);
    cout<<"x="<<p1.getX()<<", y="<<p1.getY()<<endl;
    Point<char*, char*> p2("东京180度", "北纬210度");
    p2.display();
    return 0;
}
```



## explicit instantiation of template

-   前面讲到的模板的实例化是在调用函数或者创建对象时由编译器自动完成的，不需要程序员引导，因此称为隐式实例化。
-   对应的，我们也可以通过代码明确地告诉编译器需要针对哪个类型进行实例化，这称为显式实例化。
    -   显式实例化的一个好处是，可以将模板的声明和定义（实现）分散到不同的文件中了。
    -   显式实例化也包括声明和定义，定义要放在模板定义（实现）所在的源文件，声明要放在模板声明所在的头文件（当然也可以不写）。
-   注：根据我的实际test，使用显式实例化时多文件编程声明和定义分散在h和cpp文件也会报错。且原文总结说【如果我们开发的模板只有我们自己使用，那也可以勉强使用显式实例化；如果希望让其他人使用（例如库、组件等），那只能将模板的声明和定义都放到头文件中了。】因此以后模板的声明和定义都放在头文件中。报错详细日志如下： 
    -   ld: symbol(s) not found for architecture x86_64
    -   collect2: error: ld returned 1 exit status

### explicit instantiation of class template

point.h

```c++
#ifndef _POINT_H
#define _POINT_H
template<typename T1, typename T2>
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
#endif
```

point.cpp

```c++
#include <iostream>
#include "point.h"
using namespace std;


template<typename T1, typename T2>
void Point<T1, T2>::display() const{
    cout<<"x="<<m_x<<", y="<<m_y<<endl;
}
//显式实例化定义
template class Point<char*, char*>;
template class Point<int, int>;
```

main.cpp

```c++
#include <iostream>
#include "point.h"
using namespace std;

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
```



## class template and inheritance



- 1.类模板从类模板派生

```cpp
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class A
{
public:
    T1 v1; 
    T2 v2;
};

template <typename T1, typename T2>
class B : public A <T2, T1>
{
public:
    T1 v3; 
    T2 v4;
};

template <typename T>
class C : public B <T, T>
{
public:
    T v5;
};

int main()
{
    // B <int, double> 的基类是 A <double, int>
    B<int, double> obj1;
    cout << typeid(obj1.v1).name() << " " << typeid(obj1.v2).name() << " " << typeid(obj1.v3).name() << " " << typeid(obj1.v4).name() << endl;
    C<int> obj2;
    return 0;
}
```

- 2.类模板从模板类派生
    - 模板类和类模板的区别：https://blog.csdn.net/sunxx1986/article/details/6619144
    - 模板类表示的是一个模板，可以生成各种不同 参数类型 的类
    - 类模板表示的是一个由模板生成而来的类


```c++
template<typename T1, typename T2>
class A{ 
    T1 v1; 
    T2 v2; 
};

// 继承自类模板 class B: public A <T1, T2>{
// 继承自模板类 class B: public A <int, double>{

template <typename T>
class B: public A <int, double>{
    T v;
};

int main() {
    B <char> obj1; 
    return 0; 
}
```

- 3.类模板从普通类派生

``` c++
class A{ 
    int v1; 
};

template<typename T>
class B: public A{ 
    T v; 
};

int main (){ 
    B <char> obj1; 
    return 0; 
}
```



- 4.普通类从模板类派生

```c++
template <typename T>
class A{ 
    T v1; 
    int n; 
};

class B: public A <int> {
    double v;
};

int main() { 
    B obj1; 
    return 0; 
}
```



## class template and friend

-   函数、类、类的成员函数作为类模板的友元

```c++
void Func1() {  }
class A {  };
class B
{
public:
    void Func() { }
};

template <typename T>
class Tmpl
{
    friend void Func1();
    friend class A;
    friend void B::Func();
};
int main()
{
    Tmpl<int> i;
    Tmpl<double> f;
    return 0;
}
```



-   函数模板作为类模板的友元

```c++
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair
{
private:
    T1 key;  //关键字
    T2 value;  //值
public:
    Pair(T1 k, T2 v) : key(k), value(v) { };
    bool operator < (const Pair<T1, T2> & p) const;

    template <typename T3, typename T4>
    friend ostream & operator << (ostream & o, const Pair<T3, T4> & p);
};

template <typename T1, typename T2>
bool Pair <T1, T2>::operator< (const Pair<T1, T2> & p) const
{
    return key < p.key;
}

template <typename T1, typename T2>
ostream & operator << (ostream & o, const Pair<T1, T2> & p)
{
    o << "(" << p.key << "," << p.value << ")";
    return o;
}
int main()
{
    Pair<string, int> student("Tom", 29);
    Pair<int, double> obj(12, 3.14);
    cout << student << " " << obj << endl;
    return 0;
}
```

-   函数模板作为类的友元

```c++
#include <iostream>
using namespace std;

class A
{
    int v;
public:
    A(int n) :v(n) { }

    template <typename T>
    friend void Print(const T & p);
};

template <typename T>
void Print(const T & p)
{
    cout << p.v;
}

int main()
{
    A a(4);
    Print(a);
    return 0;
}
```

-   类模板作为类模板的友元

```c++
#include <iostream>
using namespace std;

template<typename T>
class A
{
public:
    void Func(const T & p)
    {
        cout << p.v;
    }
};

template <typename T>
class B
{
private:
    T v;
public:
    B(T n) : v(n) { }
  
    template <typename T2>
    friend class A;  //把类模板A声明为友元
};

int main()
{
    B<int> b(5);
    A< B<int> > a;  //用B<int>替换A模板中的 T
    a.Func(b);
    return 0;
}
```

## static member in class template

-   类模板中可以定义静态成员，从该类模板实例化得到的所有类都包含同样的静态成员。

```c++
#include <iostream>
using namespace std;

template <typename T>
class A
{
private:
    static int count;
public:
    A() { count ++; }
    ~A() { count -- ; };
    A(A &) { count ++ ; }
  
    static void PrintCount() { cout << count << endl; }
};

template<> int A<int>::count = 0;
template<> int A<double>::count = 0;

int main()
{
  	// A<int> 的对象 ia 和 A<double> 的对象 da 不会共享一份 count
    A<int> ia;
    A<double> da;
    ia.PrintCount();
    da.PrintCount();
    return 0;
}
```





