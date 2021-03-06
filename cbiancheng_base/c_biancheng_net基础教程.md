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

*   引用分别作为函数参数和函数返回值

```c++
#include <iostream>
#include <string>
using namespace std;

// 语法格式：type &name = data;

void swap1(int a, int b);
void swap2(int *p1, int *p2);
// 引用作为函数参数
void swap3(int &r1, int &r2);

// 引用作为函数返回值
int& plus10(int& r) {
    r += 10;
    return r;
    // 返回局部变量的引用
    // int m = r + 10;
    // return m;
}


int main() {
    int a = 99;
    int& b = a;
    b = 22;
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;

    // 不希望通过引用修改原始数据
    // const type &name = value; 或者 type const &name = value;

    // 引用作为函数参数
    int num1, num2;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap1(num1, num2);
    cout << num1 << " " << num2 << endl;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap2(&num1, &num2);
    cout << num1 << " " << num2 << endl;
    cout << "Input two integers: ";
    cin >> num1 >> num2;
    swap3(num1, num2);
    cout << num1 << " " << num2 << endl;

    // 引用作为函数返回值
    int x = 10;
    int& y = plus10(x);
    cout << x << " " << y << " " << &x << " " << &y << endl;
    // 引用作为函数返回值时不能返回局部数据的引用。因为函数调用完局部数据就会被销毁
    int& num3 = plus10(x);
    int& num4 = plus10(num3);
    cout << num3 << " " << num4 << " " << &num3 << " " << &num4 << endl;
}

//直接传递参数内容
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
//传递指针
void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//按引用传参
void swap3(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}
```

*   引用的本质

    -   引用的后续知识过于生僻，暂时只了解到 「掌握一般用法，及编译器实际内部处理为指针的原理」 这一步。

    -   引用只是对指针进行了简单的封装，它的底层依然是通过指针实现的，引用占用的内存和指针占用的内存长度一样。之所以不能获取引用的地址，是因为编译器进行了内部转换。

        -   ```c++
            // 普通引用的内部转换
            
            int a = 99;
            int &r = a;
            r = 18;
            // 转换为
            int a = 99;
            int *r = &a;
            *r = 18;
            
            // &r：取r的地址自动变为&a取a的地址
            // 因此不是变量 r 不占用内存，而是编译器不让获取它的地址
            ```

        -   ```c++
            // 引用作为函数参数的内部转换
            
            void swap(int &r1, int &r2){
                int temp = r1;
                r1 = r2;
                r2 = temp;
            }
            int num1 = 10, num2 = 20;
            swap(num1, num2);
            // 转换为
            void swap(int *r1, int *r2){
                int temp = *r1;
                *r1 = *r2;
                *r2 = temp;
            }
            int num1 = 10, num2 = 20;
            swap(&num1, &num2);
            ```

        -   引用和指针的其他区别

        -   1.   引用必须在定义时初始化，并且以后也要从一而终，不能再指向其他数据；而指针没有这个限制，指针在定义时不必赋值，以后也能指向任意数据
            2.   可以有 const 指针，但是没有 const 引用
            3.   指针可以有多级，但是引用只能有一级，例如，int **p是合法的，而int &&r是不合法的
            4.   指针和引用的自增（++）自减（--）运算意义不一样。对指针使用 ++ 表示指向下一份数据，对引用使用 ++ 表示它所指代的数据本身加 1；自减（--）也是类似的道理

```c++
#include <iostream>
#include <iomanip>
using namespace std;

int num = 99;

class A{
public:
    A();
    int get_n() { return n; }
    int get_r() { return r; }
private:
    int n;
    int &r; // 不是变量 r 不占用内存，而是编译器不让获取它的地址。
};

A::A(): n(1), r(num){}

int main (){
    A *a = new A();
    cout << sizeof(a) << " " << sizeof(num) << endl; // a占8个字节，num占4个字节，说明n和r各占四个字节，说明引用本质上占内存

    // hex表示以十六进制输出，showbase表示添加十六进制前缀0x
    // 成员变量 r 是 private 属性的，不能直接通过对象来访问，但是借助强大的指针和类型转换，我们依然可以得到它的内容，只不过这种方法有点蹩脚
    cout << hex << showbase << *((int*)a + 1) << endl;  //输出r本身的内容

    cout << &num << endl;
    return 0;
}
```



# Section4 Inheritance and derivation

## An example

```c++
#include <iostream>
#include <string>
using namespace std;

class People {
public:
    void set_name(string name);
    void set_age(int age);
    string get_name();
    int get_age();

private:
    string m_name;
    int m_age;
};

void People::set_name(string name) { m_name = name; }
void People::set_age(int age) { m_age = age; }
string People::get_name() {return m_name; }
int People::get_age() {return m_age; }

class Student: public People {
public:
    void set_score(float score);
    float get_score();

private:
    float m_score;
};

void Student::set_score(float score) { m_score = score; }
float Student::get_score() {return m_score; }

int main() {
    Student stu;
    stu.set_name("xiaoming");
    stu.set_age(20);
    stu.set_score(98.3);
    cout << stu.get_name() << " " << stu.get_age() << " " << stu.get_score() << endl;
}
```

## three inherit ways

-   继承方式\基类成员	基类public成员	基类protected成员	基类private成员
-   public继承	              public	               protected	               不可见
-   protected继承	       protected	         protected	               不可见
-   private继承	            private	              private	                    不可见

```c++
#include <iostream>
#include <string>
using namespace std;

//基类People
class People{
public:
    void setname(char *name);
    void setage(int age);
    void sethobby(char *hobby);
    char *gethobby();
protected:
    char *m_name;
    int m_age;
private:
    char *m_hobby;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
void People::sethobby(char *hobby){ m_hobby = hobby; }
char *People::gethobby(){ return m_hobby; }

//派生类Student
class Student: public People{
public:
    void setscore(float score);
protected:
    float m_score;
};
void Student::setscore(float score){ m_score = score; }

//派生类Pupil
class Pupil: public Student{
public:
    void setranking(int ranking);
    void display();
private:
    int m_ranking;
};
void Pupil::setranking(int ranking){ m_ranking = ranking; }
void Pupil::display(){
    cout<<m_name<<"的年龄是"<<m_age<<"，考试成绩为"<<m_score<<"分，班级排名第"<<m_ranking<<"，TA喜欢"<<gethobby()<<"。"<<endl;
}

int main(){
    Pupil pup;
    pup.setname("小明");
    pup.setage(15);
    pup.setscore(92.5f);
    pup.setranking(4);
    pup.sethobby("乒乓球");
    pup.display();

    return 0;
}
```

## access permission modify with 'using'

-   使用 using 关键字可以改变基类成员在派生类中的访问权限
-   注意：using 只能改变基类中 public 和 protected 成员的访问权限，不能改变 private 成员的访问权限，因为基类中 private 成员在派生类中是不可见的，根本不能使用，所以基类中的 private 成员在派生类中无论如何都不能访问。

```c++
#include<iostream>
using namespace std;

//基类People
class People {
public:
    void show();
protected:
    char *m_name;
    int m_age;
};
void People::show() {
    cout << m_name << "的年龄是" << m_age << endl;
}

//派生类Student
class Student : public People {
public:
    void learning();
public:
    using People::m_name;  //将protected改为public
    using People::m_age;  //将protected改为public
    float m_score;
private:
    using People::show;  //将public改为private
};
void Student::learning() {
    cout << "我是" << m_name << "，今年" << m_age << "岁，这次考了" << m_score << "分！" << endl;
}

int main() {
    Student stu;
    stu.m_name = "小明";
    stu.m_age = 16;
    stu.m_score = 99.5f;
    // stu.show();  //compile error
    stu.learning();

    return 0;
}
```



## name masking in inherit

-   an example
    -   如果派生类中的成员（包括成员变量和成员函数）和基类中的成员重名，那么就会遮蔽从基类继承过来的成员

```c++
#include<iostream>
using namespace std;

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
```



-   基类成员函数和派生类成员函数不构成重载
    -   基类成员和派生类成员的名字一样时会造成遮蔽，这句话对于成员变量很好理解，对于成员函数要引起注意，不管函数的参数如何，只要名字一样就会造成遮蔽。
    -    换句话说，基类成员函数和派生类成员函数不会构成重载，如果派生类有同名函数，那么就会遮蔽基类中的所有同名函数，不管它们的参数是否一样。

```c++
#include<iostream>
using namespace std;

//基类Base
class Base{
public:
    void func();
    void func(int);
};
void Base::func(){ cout<<"Base::func()"<<endl; }
void Base::func(int a){ cout<<"Base::func(int)"<<endl; }

//派生类Derived
class Derived: public Base{
public:
    void func(char *);
    void func(bool);
};
void Derived::func(char *str){ cout<<"Derived::func(char *)"<<endl; }
void Derived::func(bool is){ cout<<"Derived::func(bool)"<<endl; }

int main(){
    Derived d;
    d.func("c.biancheng.net");
    d.func(true);
    // d.func();  //compile error
    // d.func(10);  //compile error
    d.Base::func();
    d.Base::func(100);

    return 0;
}
```

## scope nesting:作用域嵌套

-   scope nesting: 作用域嵌套
    -   类其实也是一种作用域，基类是外层作用域，派生类是内层作用域
    -   当存在继承关系时，派生类的作用域嵌套在基类的作用域之内，如果一个名字在派生类的作用域内无法找到，编译器会继续到外层的基类作用域中查找该名字的定义。

```c++
#include <iostream>
using namespace std;

class A {
public:
    void func();
    int n;
};

void A::func() { cout << "c.biancheng.net" << endl; }

class B: public A {
public:
    int x;
    int n;
};

class C: public B {
public:
    int y;
    int n;
};


int main() {
    C obj;
    obj.n = 2;
    cout << obj.n << endl;
    obj.func();
    cout << sizeof(C) << endl;  // 4(int) * 5 = 20
}
```

## memory model in inherit

-   有继承关系时，派生类的内存模型可以看成是基类成员变量和新增成员变量的总和，而所有成员函数仍然存储在另外一个区域——代码区，由所有对象共享
-   基类的成员变量排在前面，派生类的排在后面。
-   当基类的成员变量被遮蔽时，仍然会留在派生类对象的内存中，派生类新增的成员变量始终排在基类的后面。

```c++
#include <cstdio>

//基类A
class A{
public:
    A(int a, int b);
public:
    void display();
protected:
    int m_a;
    int m_b;
};

A::A(int a, int b): m_a(a), m_b(b){}
void A::display(){
    printf("m_a=%d, m_b=%d\n", m_a, m_b);
}

class B: public A{
public:
    B(int a, int b, int c);
    void display();
protected:
    int m_c;
};

B::B(int a, int b, int c): A(a, b), m_c(c){ }
void B::display(){
    printf("m_a=%d, m_b=%d, m_c=%d\n", m_a, m_b, m_c);
}

class C: public B{
public:
    C(char a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};

C::C(char a, int b, int c, int d): B(a, b, c), m_d(d){ }
void C::display(){
    printf("m_a=%d, m_b=%d, m_c=%d, m_d=%d\n", m_a, m_b, m_c, m_d);
}

class D: public B{
public:
    D(char a, int b, int c, int d);
public:
    void display();
private:
    int m_b;
    int m_c;
    int m_d;
};

D::D(char a, int b, int c, int d): B(a, b, c), m_b(b+66), m_c(c+66), m_d(d){ }
void D::display(){
    printf("A::m_a=%d, A::m_b=%d, B::m_c=%d\n", m_a, A::m_b, B::m_c);
    printf("D::m_b=%d, D::m_c=%d, D::m_d=%d\n", m_b, m_c, m_d);
}

int main(){
    A obj_a(99, 10);
    B obj_b(84, 23, 95);
    C obj_c(11, 22, 33, 44);
    D obj_d(11, 22, 33, 44);
    obj_a.display();
    obj_b.display();
    obj_c.display();
    obj_d.display();
    return 0;
}
```

## construct and destruct function in inherit

-   construct function in inherit
    -   基类的普通成员函数可以被继承，可以通过派生类的对象访问，但是基类的构造函数不能被继承。构造函数不能被继承是有道理的，因为即使继承了，它的名字和派生类的名字也不一样，不能成为派生类的构造函数，当然更不能成为普通的成员函数。
    -   对继承过来的成员变量的初始化工作也要由派生类的构造函数完成，但是大部分基类都有 private 属性的成员变量，它们在派生类中无法访问，更不能使用派生类的构造函数来初始化。这种矛盾在C++继承中是普遍存在的，解决这个问题的思路是：在派生类的构造函数中调用基类的构造函数。

```c++
#include <iostream>
using namespace std;

class People {
public:
    People(char* name, int age);
    char* get_name() { return m_name; }
    int get_age() { return m_age; }

private:
    char* m_name;
    int m_age;
};

People::People(char* name, int age): m_name(name), m_age(age) { }

class Student: public People {
public:
    Student(char* name, int age, float score);
    void display();

private:
    float m_score;
};

// 派生类构造函数总是先调用基类构造函数再执行其他代码（包括参数初始化表以及函数体中的代码），不论基类构造函数的位置在前还是在后。
// 基类构造函数的调用放在函数头部，不能放在函数体中。
// 派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类的
Student::Student(char* name, int age, float score): People(name, age), m_score(score) { }
void Student::display() {
    cout << get_name() << " " << get_age() << " " << m_score << endl;
}

int main() {
    Student stu("zhangsan", 19, 80);
    stu.display();
}
```



-   destruct function in inherit
    -   创建派生类对象时，构造函数的执行顺序和继承顺序相同，即先执行基类构造函数，再执行派生类构造函数。
    -   而销毁派生类对象时，析构函数的执行顺序和继承顺序相反，即先执行派生类析构函数，再执行基类析构函数。

```c++
#include <iostream>
using namespace std;
class A{
public:
    A(){cout<<"A constructor"<<endl;}
    ~A(){cout<<"A destructor"<<endl;}
};
class B: public A{
public:
    B(){cout<<"B constructor"<<endl;}
    ~B(){cout<<"B destructor"<<endl;}
};
class C: public B{
public:
    C(){cout<<"C constructor"<<endl;}
    ~C(){cout<<"C destructor"<<endl;}
};
int main(){
    C test;
    return 0;
}
```

## multiple inherit

### multiple inherit example

-   在前面的例子中，派生类都只有一个基类，称为单继承（Single Inheritance）。除此之外，C++也支持多继承（Multiple Inheritance），即一个派生类可以有两个或多个基类。

-   多继承形式下的构造函数和单继承形式基本相同，只是要在派生类的构造函数中调用多个基类的构造函数

-   ```c++
    class D: public A, private B, protected C{
        //类D新增加的成员
    }
    ```

```c++
#include <iostream>
using namespace std;

//基类
class BaseA{
public:
    BaseA(int a, int b);
    ~BaseA();
protected:
    int m_a;
    int m_b;
};
BaseA::BaseA(int a, int b): m_a(a), m_b(b){
    cout<<"BaseA constructor"<<endl;
}
BaseA::~BaseA(){
    cout<<"BaseA destructor"<<endl;
}

//基类
class BaseB{
public:
    BaseB(int c, int d);
    ~BaseB();
protected:
    int m_c;
    int m_d;
};
BaseB::BaseB(int c, int d): m_c(c), m_d(d){
    cout<<"BaseB constructor"<<endl;
}
BaseB::~BaseB(){
    cout<<"BaseB destructor"<<endl;
}

//派生类
class Derived: public BaseA, public BaseB{
public:
    Derived(int a, int b, int c, int d, int e);
    ~Derived();
public:
    void show();
private:
    int m_e;
};
Derived::Derived(int a, int b, int c, int d, int e): BaseA(a, b), BaseB(c, d), m_e(e){
    cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
    cout<<"Derived destructor"<<endl;
}
void Derived::show(){
    cout<<m_a<<", "<<m_b<<", "<<m_c<<", "<<m_d<<", "<<m_e<<endl;
}

int main(){
    Derived obj(1, 2, 3, 4, 5);
    obj.show();
    return 0;
}
```

### name conflict in multiple inherit

-   当两个或多个基类中有同名的成员时，如果直接访问该成员，就会产生命名冲突，编译器不知道使用哪个基类的成员。
-   这个时候需要在成员名字前面加上类名和域解析符::，以显式地指明到底使用哪个类的成员，消除二义性。

```c++
#include <iostream>
using namespace std;

//基类
class BaseA{
public:
    BaseA(int a, int b);
    ~BaseA();
public:
    void show();
protected:
    int m_a;
    int m_b;
};
BaseA::BaseA(int a, int b): m_a(a), m_b(b){
    cout<<"BaseA constructor"<<endl;
}
BaseA::~BaseA(){
    cout<<"BaseA destructor"<<endl;
}
void BaseA::show(){
    cout<<"m_a = "<<m_a<<endl;
    cout<<"m_b = "<<m_b<<endl;
}

//基类
class BaseB{
public:
    BaseB(int c, int d);
    ~BaseB();
    void show();
protected:
    int m_c;
    int m_d;
};
BaseB::BaseB(int c, int d): m_c(c), m_d(d){
    cout<<"BaseB constructor"<<endl;
}
BaseB::~BaseB(){
    cout<<"BaseB destructor"<<endl;
}
void BaseB::show(){
    cout<<"m_c = "<<m_c<<endl;
    cout<<"m_d = "<<m_d<<endl;
}

//派生类
class Derived: public BaseA, public BaseB{
public:
    Derived(int a, int b, int c, int d, int e);
    ~Derived();
public:
    void display();
private:
    int m_e;
};
Derived::Derived(int a, int b, int c, int d, int e): BaseA(a, b), BaseB(c, d), m_e(e){
    cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
    cout<<"Derived destructor"<<endl;
}
void Derived::display(){
    // show(); // reference to 'show' is ambiguous
    BaseA::show();  //调用BaseA类的show()函数
    BaseB::show();  //调用BaseB类的show()函数
    cout<<"m_e = "<<m_e<<endl;
}

int main(){
    Derived obj(1, 2, 3, 4, 5);
    obj.display();
    return 0;
}
```



### memory model in multiple inherit

-   内存模型中，基类对象的排列顺序和继承时声明的顺序相同。

```c++
#include <cstdio>
using namespace std;

//基类A
class A{
public:
    A(int a, int b);
protected:
    int m_a;
    int m_b;
};
A::A(int a, int b): m_a(a), m_b(b){ }

//基类B
class B{
public:
    B(int b, int c);
protected:
    int m_b;
    int m_c;
};
B::B(int b, int c): m_b(b), m_c(c){ }

//派生类C
class C: public A, public B{
public:
    C(int a, int b, int c, int d);
public:
    void display();
private:
    int m_a;
    int m_c;
    int m_d;
};
C::C(int a, int b, int c, int d): A(a, b), B(b, c), m_a(a), m_c(c), m_d(d){ }
void C::display(){
    printf("A::m_a=%d, A::m_b=%d\n", A::m_a, A::m_b);
    printf("B::m_b=%d, B::m_c=%d\n", B::m_b, B::m_c);
    printf("C::m_a=%d, C::m_c=%d, C::m_d=%d\n", C::m_a, C::m_c, m_d);
}

int main(){
    C obj_c(10, 20, 30, 40);
    obj_c.display();

    return 0;
}
```

## break access restriction with pointer

-   C++ 不允许通过对象来访问 private、protected 属性的成员变量，但是可以通过指针突破权限的限制

```c++
#include <iostream>
using namespace std;

class A{
public:
    A(int a, int b, int c);
private:
    int m_a;
    int m_b;
    int m_c;
};
A::A(int a, int b, int c): m_a(a), m_b(b), m_c(c){ }

int main(){
    A obj(10, 20, 30);
    int a1 = *((int*)(&obj)); 
    int b = *((int*)( (long)(&obj) + sizeof(int) ));

    A *p = new A(40, 50, 60);
    int a2 = *((int*)(p));
    int c = *((int*)( (long)p + sizeof(int)*2 ));
    cout << sizeof(int) << endl;
    cout<<"a1="<<a1<<", a2="<<a2<<", b="<<b<<", c="<<c<<endl;

    return 0;
}
```

## virtual inherit and virtual base class

### an example

-   类 A 派生出类 B 和类 C，类 D 继承自类 B 和类 C，这个时候类 A 中的成员变量和成员函数继承到类 D 中变成了两份，一份来自 A-->B-->D 这条路径，另一份来自 A-->C-->D 这条路径。

```c++
#include <iostream>
using namespace std;

//间接基类A
class A{
protected:
    int m_a;
};

//直接基类B
class B: public A{
protected:
    int m_b;
};

//直接基类C
class C: public A{
protected:
    int m_c;
};

//派生类D
class D: public B, public C{
public:
    // void seta(int a){ m_a = a; }  //命名冲突
    void setba(int a){ B::m_a = a; }
    void setca(int a){ C::m_a = a; }
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确
private:
    int m_d;
};

int main(){
    D d;
    return 0;
}
```

-   为了解决多继承时的命名冲突和冗余数据问题，C++ 提出了虚继承，使得在派生类中只保留一份间接基类的成员。
-   虚继承的目的是让某个类做出声明，承诺愿意共享它的基类。
-   其中，这个被共享的基类就称为虚基类（Virtual Base Class），本例中的 A 就是一个虚基类。
-   在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。

```c++
#include <iostream>
using namespace std;

//间接基类A
class A{
protected:
    int m_a;
};

//直接基类B
class B: virtual public A{  //虚继承
protected:
    int m_b;
};

//直接基类C
class C: virtual public A{  //虚继承
protected:
    int m_c;
};

//派生类D
class D: public B, public C{
public:
    void seta(int a){ m_a = a; }  //正确
    void setb(int b){ m_b = b; }  //正确
    void setc(int c){ m_c = c; }  //正确
    void setd(int d){ m_d = d; }  //正确
private:
    int m_d;
};

int main(){
    D d;
    return 0;
}
```

### construct function in virtual inherit

-   在虚继承中，虚基类是由最终的派生类初始化的，即最终派生类的构造函数必须要调用虚基类的构造函数。
-   对最终的派生类来说，虚基类是间接基类，而不是直接基类。
-   这跟普通继承不同，在普通继承中，派生类构造函数中只能调用直接基类的构造函数，不能调用间接基类的。

```c++
#include <iostream>
using namespace std;

//虚基类A
class A{
public:
    A(int a);
protected:
    int m_a;
};
A::A(int a): m_a(a){ }

//直接派生类B
class B: virtual public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
    cout<<"m_a="<<m_a<<", m_b="<<m_b<<endl;
}

//直接派生类C
class C: virtual public A{
public:
    C(int a, int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int a, int c): A(a), m_c(c){ }
void C::display(){
    cout<<"m_a="<<m_a<<", m_c="<<m_c<<endl;
}

//间接派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d): A(a), B(90, b), C(100, c), m_d(d){ }
void D::display(){
    cout<<"m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}

int main(){
    B b(10, 20);
    b.display();
   
    C c(30, 40);
    c.display();

    D d(50, 60, 70, 80);
    d.display();
    return 0;
}
```

### memory model in virtual inherit

-   对于普通继承，基类子对象始终位于派生类对象的前面（也即基类成员变量始终在派生类成员变量的前面），而且不管继承层次有多深，它相对于派生类对象顶部的偏移量是固定的
-   对于虚继承，不管是虚基类的直接派生类还是间接派生类，虚基类的子对象始终位于派生类对象的最后面。
-   VC 引入了虚基类表，如果某个派生类有一个或多个虚基类，编译器就会在派生类对象中安插一个指针，指向虚基类表。虚基类表其实就是一个数组，数组中的元素存放的是各个虚基类的偏移。

1.   普通继承的内存模型

```c++
#include <iostream>
using namespace std;

class A{
protected:
    int m_a1;
    int m_a2;
};

class B: public A{
protected:
    int b1;
    int b2;
};

class C: public B{
protected:
    int c1;
    int c2;
};

class D: public C{
protected:
    int d1;
    int d2;
};

int main(){
    A obj_a;
    B obj_b;
    C obj_c;
    D obj_d;

    return 0;
}
```

![avatar](./pictures/memory_model_in_inherit.jpeg)



2.   虚继承的内存模型

如果某个派生类有一个或多个虚基类，编译器就会在派生类对象中安插一个指针，指向虚基类表。

假设 A 是 B 的虚基类，那么各对象的内存模型如下图所示：

![avatar](./pictures/memory_model_in_virtual_inherit_v1.jpeg)

假设 A 是 B 的虚基类，同时 B 又是 C 的虚基类，那么各对象的内存模型如下图所示：

![avatar](./pictures/memory_model_in_virtual_inherit_v2.jpeg)

## upcasting

### assign the derived class object to the base class object

-   类其实也是一种数据类型，也可以发生数据类型转换，不过这种转换只有在基类和派生类之间才有意义，并且只能将派生类赋值给基类，包括将派生类对象赋值给基类对象、将派生类指针赋值给基类指针、将派生类引用赋值给基类引用，这在 C++ 中称为向上转型（Upcasting）。相应地，将基类赋值给派生类称为向下转型（Downcasting）。
-   赋值的本质是将现有的数据写入已分配好的内存中，对象的内存只包含了成员变量，所以对象之间的赋值是成员变量的赋值，成员函数不存在赋值问题
-   这种转换关系是不可逆的，只能用派生类对象给基类对象赋值，而不能用基类对象给派生类对象赋值

```c++
#include <iostream>
using namespace std;

//基类
class A{
public:
    A(int a);
public:
    void display();
public:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
    cout<<"Class A: m_a="<<m_a<<endl;
}

//派生类
class B: public A{
public:
    B(int a, int b);
public:
    void display();
public:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
    cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}


int main(){
    A a(10);
    B b(66, 99);
    //赋值前
    a.display();
    b.display();
    cout<<"--------------"<<endl;
    //赋值后
    a = b;
    a.display();
    b.display();

    return 0;
}
```

### assign the derived class pointer to the base class pointer

-   将派生类指针赋值给基类指针 | 将派生类引用赋值给基类引用
-   编译器通过指针来访问成员变量，指针指向哪个对象就使用哪个对象的数据；
-   编译器通过指针的类型来访问成员函数，指针属于哪个类的类型就使用哪个类的函数

```c++
#include <iostream>
using namespace std;

//基类A
class A{
public:
    A(int a);
public:
    void display();
protected:
    int m_a;
};
A::A(int a): m_a(a){ }
void A::display(){
    cout<<"Class A: m_a="<<m_a<<endl;
}

//中间派生类B
class B: public A{
public:
    B(int a, int b);
public:
    void display();
protected:
    int m_b;
};
B::B(int a, int b): A(a), m_b(b){ }
void B::display(){
    cout<<"Class B: m_a="<<m_a<<", m_b="<<m_b<<endl;
}

//基类C
class C{
public:
    C(int c);
public:
    void display();
protected:
    int m_c;
};
C::C(int c): m_c(c){ }
void C::display(){
    cout<<"Class C: m_c="<<m_c<<endl;
}

//最终派生类D
class D: public B, public C{
public:
    D(int a, int b, int c, int d);
public:
    void display();
private:
    int m_d;
};
D::D(int a, int b, int c, int d): B(a, b), C(c), m_d(d){ }
void D::display(){
    cout<<"Class D: m_a="<<m_a<<", m_b="<<m_b<<", m_c="<<m_c<<", m_d="<<m_d<<endl;
}


int main(){
    A *pa = new A(1);
    B *pb = new B(2, 20);
    C *pc = new C(3);
    D *pd = new D(4, 40, 400, 4000);

    pa = pd;
    pa -> display();

    pb = pd;
    pb -> display();

    pc = pd;
    pc -> display();

    /// 将派生类的指针赋值给基类指针，输出的值(指针的值，表示地址)有可能相等，如pa,pb和pd，也有可能不相等，如pc和pd
    /// 内存模型： m_a m_b m_c m_d
    /// 首先要明确的一点是，对象的指针必须要指向对象的起始位置。
    /// 对于 A 类和 B 类来说，它们的子对象的起始地址和 D 类对象一样，所以将 pd 赋值给 pa、pb 时不需要做任何调整，直接传递现有的值即可；
    /// 而 C 类子对象距离 D 类对象的开头有一定的偏移，将 pd 赋值给 pc 时要加上这个偏移，这样 pc 才能指向 C 类子对象的起始位置。
    /// 也就是说，执行pc = pd;语句时编译器对 pd 的值进行了调整，才导致 pc、pd 的值不同。

    cout<<"-----------------------"<<endl;
    cout<<"pa="<<pa<<endl;
    cout<<"pb="<<pb<<endl;
    cout<<"pc="<<pc<<endl;
    cout<<"pd="<<pd<<endl;



    D d(4, 40, 400, 4000);   
    A &ra = d;
    B &rb = d;
    C &rc = d;
    
    cout<<"-----------------------"<<endl;
    ra.display();
    rb.display();
    rc.display();

    return 0;
}
```



# Section5 polymophism and virtual function

-   “多态（polymorphism）”指的是同一名字的事物可以完成不同的功能。
-   多态可以分为编译时的多态和运行时的多态。
    -   前者主要是指函数的重载（包括运算符的重载）、对重载函数的调用，在编译时就能根据实参确定应该调用哪个函数，因此叫编译时的多态；
    -   而后者则和继承、虚函数等概念有关，是本章要讲述的内容。本教程后面提及的多态都是指运行时的多态。
-   有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为多态（Polymorphism）。
-   C++提供多态的目的是：可以通过基类指针对所有派生类（包括直接派生和间接派生）的成员变量和成员函数进行“全方位”的访问，尤其是成员函数。如果没有多态，我们只能访问成员变量。
-   前面我们说过，通过指针调用普通的成员函数时会根据指针的类型（通过哪个类定义的指针）来判断调用哪个类的成员函数，但是通过本节的分析可以发现，这种说法并不适用于虚函数，虚函数是根据指针的指向来调用的，指针指向哪个类的对象就调用哪个类的虚函数。

## the necessity of virtual functions

```c++
#include <iostream>
using namespace std;

//基类People
class People{
public:
    People(char *name, int age);
    virtual void display();
protected:
    char *m_name;
    int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

//派生类Teacher
class Teacher: public People{
public:
    Teacher(char *name, int age, int salary);
    virtual void display();
private:
    int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
    cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main(){
    /*
    我们直观上认为，如果指针指向了派生类对象，那么就应该使用派生类的成员变量和成员函数，这符合人们的思维习惯。
    但是本例的运行结果却告诉我们，当基类指针 p 指向派生类 Teacher 的对象时，
    虽然使用了 Teacher 的成员变量，但是却没有使用它的成员函数，导致输出结果不伦不类（赵宏佳本来是一名老师，输出结果却显示人家是个无业游民），不符合我们的预期。
    换句话说，通过基类指针只能访问派生类的成员变量，但是不能访问派生类的成员函数。
    为了消除这种尴尬，让基类指针能够访问派生类的成员函数，C++ 增加了虚函数（Virtual Function）


    王志刚今年23岁了，是个无业游民。
    赵宏佳今年45岁了，是个无业游民。

    在基类的display函数前加了virtual关键字后

    王志刚今年23岁了，是个无业游民。
    赵宏佳今年45岁了，是一名教师，每月有8200元的收入。
    */

    People *p = new People("王志刚", 23);
    p -> display(); 
    p = new Teacher("赵宏佳", 45, 8200);
    p -> display(); 

    // 引用同样可以实现多态
    People p1("王志刚", 23);
    Teacher t("赵宏佳", 45, 8200);
    People &rp = p1;
    People &rt = t;
    rp.display();
    rt.display();


    return 0;
}
```

## application of virtual functions -- an example

```c++
#include <iostream>
using namespace std;

/// 多态的应用场景

//军队
class Troops{
public:
    virtual void fight(){ cout<<"Strike back!"<<endl; }
};

//陆军
class Army: public Troops{
public:
    void fight(){ cout<<"--Army is fighting!"<<endl; }
};
//99A主战坦克
class _99A: public Army{
public:
    void fight(){ cout<<"----99A(Tank) is fighting!"<<endl; }
};
//武直10武装直升机
class WZ_10: public Army{
public:
    void fight(){ cout<<"----WZ-10(Helicopter) is fighting!"<<endl; }
};
//长剑10巡航导弹
class CJ_10: public Army{
public:
    void fight(){ cout<<"----CJ-10(Missile) is fighting!"<<endl; }
};

//空军
class AirForce: public Troops{
public:
    void fight(){ cout<<"--AirForce is fighting!"<<endl; }
};
//J-20隐形歼击机
class J_20: public AirForce{
public:
    void fight(){ cout<<"----J-20(Fighter Plane) is fighting!"<<endl; }
};
//CH5无人机
class CH_5: public AirForce{
public:
    void fight(){ cout<<"----CH-5(UAV) is fighting!"<<endl; }
};
//轰6K轰炸机
class H_6K: public AirForce{
public:
    void fight(){ cout<<"----H-6K(Bomber) is fighting!"<<endl; }
};

int main(){
    Troops *p = new Troops;
    p ->fight();
    //陆军
    p = new Army;
    p ->fight();
    p = new _99A;
    p -> fight();
    p = new WZ_10;
    p -> fight();
    p = new CJ_10;
    p -> fight();
    //空军
    p = new AirForce;
    p -> fight();
    p = new J_20;
    p -> fight();
    p = new CH_5;
    p -> fight();
    p = new H_6K;
    p -> fight();

    return 0;
}
```

## Conditions that constitute polymophism

-   polymophism considerations

    -   只需要在虚函数的声明处加上 virtual 关键字，函数定义处可以加也可以不加。

    -   为了方便，你可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。

    -   当在基类中定义了虚函数时，如果派生类没有定义新的函数来遮蔽此函数，那么将使用基类的虚函数。
        -   只有派生类的虚函数覆盖基类的虚函数（函数原型相同）才能构成多态（通过基类指针访问派生类函数）。
            -   例如基类虚函数的原型为virtual void func();，派生类虚函数的原型为virtual void func(int);，那么当基类指针 p 指向派生类对象时，语句p -> func(100);将会出错，而语句p -> func();将调用基类的函数。

    -   构造函数不能是虚函数。对于基类的构造函数，它仅仅是在派生类构造函数中被调用，这种机制不同于继承。也就是说，派生类不继承基类的构造函数，将构造函数声明为虚函数没有什么意义。

    -   析构函数可以声明为虚函数，而且有时候必须要声明为虚函数，这点我们将在下节中讲解。

-   conditions that constitute polymophism

  -   多态是指通过基类的指针既可以访问基类的成员，也可以访问派生类的成员。
  -   构成多态的条件：
    -   必须存在继承关系；
    -   继承关系中必须有同名的虚函数，并且它们是覆盖关系（函数原型相同）。
    -   存在基类的指针，通过该指针调用虚函数。

```c++
#include <iostream>
using namespace std;

//基类Base
class Base{
public:
    virtual void func();
    virtual void func(int);
};
void Base::func(){
    cout<<"void Base::func()"<<endl;
}
void Base::func(int n){
    cout<<"void Base::func(int)"<<endl;
}

//派生类Derived
class Derived: public Base{
public:
    void func();
    void func(char *);
};
void Derived::func(){
    cout<<"void Derived::func()"<<endl;
}
void Derived::func(char *str){
    cout<<"void Derived::func(char *)"<<endl;
}

int main(){
    Base *p = new Derived();
    p -> func();  //输出void Derived::func()
    p -> func(10);  //输出void Base::func(int)
    // p -> func("http://c.biancheng.net");  //compile error.因为通过基类的指针只能访问从基类继承过去的成员，不能访问派生类新增的成员。

    return 0;
}
```

## the necessity of virtual destructor

```c++
#include <iostream>
using namespace std;

//基类
class Base{
public:
    Base();
    virtual ~Base();
protected:
    char *str;
};
Base::Base(){
    str = new char[100];
    cout<<"Base constructor"<<endl;
}
Base::~Base(){
    delete[] str;
    cout<<"Base destructor"<<endl;
}

//派生类
class Derived: public Base{
public:
    Derived();
    ~Derived();
private:
    char *name;
};
Derived::Derived(){
    name = new char[100];
    cout<<"Derived constructor"<<endl;
}
Derived::~Derived(){
    delete[] name;
    cout<<"Derived destructor"<<endl;
}

int main(){

    /// 语句delete pb;只调用了基类的析构函数，没有调用派生类的析构函数；而语句delete pd;同时调用了派生类和基类的析构函数
    /// 因为通过指针访问非虚函数时，编译器会根据指针的类型来确定要调用的函数
    /// pb 是基类的指针，所以不管它指向基类的对象还是派生类的对象，始终都是调用基类的析构函数。
    /// 因此需要将基类的析构函数声明为虚函数
  
  	/// 将基类的析构函数声明为虚函数后，派生类的析构函数也会自动成为虚函数。
    /// 这个时候编译器会忽略指针的类型，而根据指针的指向来选择函数；也就是说，指针指向哪个类的对象就调用哪个类的函数。
    /// pb、pd 都指向了派生类的对象，所以会调用派生类的析构函数，继而再调用基类的析构函数。

    Base *pb = new Derived();
    delete pb;

    cout<<"-------------------"<<endl;

    Derived *pd = new Derived();
    delete pd;

    return 0;
}
```

## pure virtual function and abstract class

-   virtual 返回值类型 函数名 (函数参数) = 0;
-   包含纯虚函数的类称为抽象类（Abstract Class）。之所以说它抽象，是因为它无法实例化，也就是无法创建对象。原因很明显，纯虚函数没有函数体，不是完整的函数，无法调用，也无法为其分配内存空间。抽象类通常是作为基类，让派生类去实现纯虚函数。派生类必须实现纯虚函数才能被实例化。
-   一个纯虚函数就可以使类成为抽象基类，但是抽象基类中除了包含纯虚函数外，还可以包含其它的成员函数（虚函数或普通函数）和成员变量。
-   只有类中的虚函数才能被声明为纯虚函数，普通成员函数和顶层函数均不能声明为纯虚函数

```c++
#include <iostream>
using namespace std;

//线
class Line{
public:
    Line(float len);
    virtual float area() = 0;
    virtual float volume() = 0;
protected:
    float m_len;
};
Line::Line(float len): m_len(len){ }

//矩形
class Rec: public Line{
public:
    Rec(float len, float width);
    float area();
protected:
    float m_width;
};
Rec::Rec(float len, float width): Line(len), m_width(width){ }
float Rec::area(){ return m_len * m_width; }

//长方体
class Cuboid: public Rec{
public:
    Cuboid(float len, float width, float height);
    float area();
    float volume();
protected:
    float m_height;
};
Cuboid::Cuboid(float len, float width, float height): Rec(len, width), m_height(height){ }
float Cuboid::area(){ return 2 * ( m_len*m_width + m_len*m_height + m_width*m_height); }
float Cuboid::volume(){ return m_len * m_width * m_height; }

//正方体
class Cube: public Cuboid{
public:
    Cube(float len);
    float area();
    float volume();
};
Cube::Cube(float len): Cuboid(len, len, len){ }
float Cube::area(){ return 6 * m_len * m_len; }
float Cube::volume(){ return m_len * m_len * m_len; }

int main(){
    Line *p = new Cuboid(10, 20, 30);
    cout<<"The area of Cuboid is "<<p->area()<<endl;
    cout<<"The volume of Cuboid is "<<p->volume()<<endl;
  
    p = new Cube(15);
    cout<<"The area of Cube is "<<p->area()<<endl;
    cout<<"The volume of Cube is "<<p->volume()<<endl;

    return 0;
}
```

## virtual function table

```c++
#include <iostream>
#include <string>
using namespace std;

//People类
class People{
public:
    People(string name, int age);
public:
    virtual void display();
    virtual void eating();
protected:
    string m_name;
    int m_age;
};
People::People(string name, int age): m_name(name), m_age(age){ }
void People::display(){
    cout<<"Class People："<<m_name<<"今年"<<m_age<<"岁了。"<<endl;
}
void People::eating(){
    cout<<"Class People：我正在吃饭，请不要跟我说话..."<<endl;
}

//Student类
class Student: public People{
public:
    Student(string name, int age, float score);
public:
    virtual void display();
    virtual void examing();
protected:
    float m_score;
};
Student::Student(string name, int age, float score):
    People(name, age), m_score(score){ }
void Student::display(){
    cout<<"Class Student："<<m_name<<"今年"<<m_age<<"岁了，考了"<<m_score<<"分。"<<endl;
}
void Student::examing(){
    cout<<"Class Student："<<m_name<<"正在考试，请不要打扰T啊！"<<endl;
}

//Senior类
class Senior: public Student{
public:
    Senior(string name, int age, float score, bool hasJob);
public:
    virtual void display();
    virtual void partying();
private:
    bool m_hasJob;
};
Senior::Senior(string name, int age, float score, bool hasJob):
    Student(name, age, score), m_hasJob(hasJob){ }
void Senior::display(){
    if(m_hasJob){
        cout<<"Class Senior："<<m_name<<"以"<<m_score<<"的成绩从大学毕业了，并且顺利找到了工作，Ta今年"<<m_age<<"岁。"<<endl;
    }else{
        cout<<"Class Senior："<<m_name<<"以"<<m_score<<"的成绩从大学毕业了，不过找工作不顺利，Ta今年"<<m_age<<"岁。"<<endl;
    }
}
void Senior::partying(){
    cout<<"Class Senior：快毕业了，大家都在吃散伙饭..."<<endl;
}

int main(){
    People *p = new People("赵红", 29);
    p -> display();

    p = new Student("王刚", 16, 84.5);
    p -> display();

    p = new Senior("李智", 22, 92.0, true);
    p -> display();

    return 0;
}
```

-   当通过指针访问类的成员函数时：
    -   如果该函数是非虚函数，那么编译器会根据指针的类型找到该函数；也就是说，指针是哪个类的类型就调用哪个类的函数。
    -   如果该函数是虚函数，并且派生类有同名的函数遮蔽它，那么编译器会根据指针的指向找到该函数；也就是说，指针指向的对象属于哪个类就调用哪个类的函数。这就是多态。
-   编译器之所以能通过指针指向的对象找到虚函数，是因为在创建对象时额外地增加了虚函数表。
    -   如果一个类包含了虚函数，那么在创建该类的对象时就会额外地增加一个数组，数组中的每一个元素都是虚函数的入口地址。
    -   不过数组和对象是分开存储的，为了将对象和数组关联起来，编译器还要在对象中安插一个指针，指向数组的起始位置。这里的数组就是虚函数表（Virtual function table），简写为`vtable`。

![avatar](./pictures/virtual_function_table.jpeg)

## typeid operator

-   typeid返回type_info对象的引用

-   ```c++
    class type_info {
    public:
        virtual ~type_info();
        int operator==(const type_info& rhs) const;
        int operator!=(const type_info& rhs) const;
        int before(const type_info& rhs) const;
        const char* name() const;
        const char* raw_name() const;
    private:
        void *_m_data;
        char _m_d_name[1];
        type_info(const type_info& rhs);
        type_info& operator=(const type_info& rhs);
    };
    ```

-   

```c++
#include <iostream>
#include <typeinfo>
using namespace std;

class Base{ };

struct STU{ };

int main(){

    //获取一个普通变量的类型信息
    int n = 100;
    const type_info &nInfo = typeid(n);
    cout<<nInfo.name()<<" | "<<nInfo.hash_code()<<endl;

    //获取一个字面量的类型信息
    const type_info &dInfo = typeid(25.65);
    cout<<dInfo.name()<<" | "<<dInfo.hash_code()<<endl;

    //获取一个对象的类型信息
    Base obj;
    const type_info &objInfo = typeid(obj);
    cout<<objInfo.name()<<" | "<<objInfo.hash_code()<<endl;

    //获取一个类的类型信息
    const type_info &baseInfo = typeid(Base);
    cout<<baseInfo.name()<<" | "<<baseInfo.hash_code()<<endl;

    //获取一个结构体的类型信息
    const type_info &stuInfo = typeid(struct STU);
    cout<<stuInfo.name()<<" | "<<stuInfo.hash_code()<<endl;

    //获取一个普通类型的类型信息
    const type_info &charInfo = typeid(char);
    cout<<charInfo.name()<<" | "<<charInfo.hash_code()<<endl;

    //获取一个表达式的类型信息
    const type_info &expInfo = typeid(20 * 45 / 4.5);
    cout<<expInfo.name()<<" | "<<expInfo.hash_code()<<endl;

    return 0;
}
```

```c++
char *str;
int a = 2;
int b = 10;
float f;
```



<img src="./pictures/typeid_v1.png" alt="avatar" style="zoom:50%;" />

```c++
class Base{};
class Derived: public Base{};
Base obj1;
Base *p1;
Derived obj2;
Derived *p2 = new Derived;
p1 = p2;
```

<img src="./pictures/typeid_v2.png" alt="avatar" style="zoom:50%;" />

表达式`typeid(*p1) == typeid(Base)`和`typeid(p1) == typeid(Base*)`的结果为 true 可以说明：即使将派生类[指针](http://c.biancheng.net/c/80/) p2 赋值给基类指针 p1，p1 的类型仍然为 Base*。

## run-time type identification(RTTI)

```c++
#include <iostream>
using namespace std;

//基类
class Base{
public:
    virtual void func();
protected:
    int m_a;
    int m_b;
};
void Base::func(){ cout<<"Base"<<endl; }

//派生类
class Derived: public Base{
public:
    void func();
private:
    int m_c;
};
void Derived::func(){ cout<<"Derived"<<endl; }

int main(){
    Base *p;
    int n;

    cin>>n;
    if(n <= 100){
        p = new Base();
    }else{
        p = new Derived();
    }
    cout<<typeid(*p).name()<<endl;

    return 0;
}
```

-   C++ 的对象内存模型：
    -   如果没有虚函数也没有虚继承，那么对象内存模型中只有成员变量。
    -   如果类包含了虚函数，那么会额外添加一个虚函数表，并在对象内存中插入一个指针，指向这个虚函数表。
    -   如果类包含了虚继承，那么会额外添加一个虚基类表，并在对象内存中插入一个指针，指向这个虚基类表。
    -   如果类包含了虚函数，那么该类的对象内存中还会额外增加类型信息，也即 type_info 对象。编译器在虚函数表 vftable 的开头插入一个指针，指向当前类对应的 type_info 对象。以上面的代码为例，Base 和 Derived 的对象内存模型如下图所示：

![avatar](./pictures/rtti_v1.jpeg)



-   RTTI的对象内存模型较为复杂，可参考https://blog.csdn.net/pi9nc/article/details/21742355

# Section6 operator overloading

-   所谓重载，就是赋予新的含义。
    -   函数重载（Function Overloading）可以让一个函数名有多种功能，在不同情况下进行不同的操作。
    -   运算符重载（Operator Overloading）也是一个道理，同一个运算符可以有不同的功能。
-   实际上，我们已经在不知不觉中使用了运算符重载。
    -   例如，+号可以对不同类型（int、float 等）的数据进行加法操作；<<既是位移运算符，又可以配合 cout 向控制台输出数据。
    -   C++ 本身已经对这些运算符进行了重载。

## an example

1.   重载为类的成员函数

```c++
#include <iostream>
using namespace std;

class complex{
public:
    complex();
    complex(double real, double imag);

    complex operator+(const complex& A) const;
    void display() const;

private:
    double m_real;
    double m_imag;
};

complex::complex(): m_real(0.0), m_imag(0.0) { }
complex::complex(double real, double imag): m_real(real), m_imag(imag) { }

complex complex::operator+(const complex& A) const {
    complex B;
    B.m_real = this->m_real + A.m_real;
    B.m_imag = this->m_imag + B.m_imag;
    return B;
}

void complex::display() const {
    cout << m_real << " + i" << m_imag << endl;
}

int main() {
    complex c1(4.3, 5.8);
    complex c2(2.4, 3.7);
    complex c3;
    c3 = c1 + c2;
    c3.display();
}
```

2.   重载为全局函数

```c++
#include <iostream>
using namespace std;

class complex{
public:
    complex();
    complex(double real, double imag);
public:
    void display() const;
    //声明为友元函数
    friend complex operator+(const complex &A, const complex &B);
private:
    double m_real;
    double m_imag;
};

complex operator+(const complex &A, const complex &B);

complex::complex(): m_real(0.0), m_imag(0.0){ }
complex::complex(double real, double imag): m_real(real), m_imag(imag){ }
void complex::display() const{
    cout<<m_real<<" + "<<m_imag<<"i"<<endl;
}

//在全局范围内重载+
complex operator+(const complex &A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}

int main(){
    complex c1(4.3, 5.8);
    complex c2(2.4, 3.7);
    complex c3;
    c3 = c1 + c2;
    c3.display();
 
    return 0;
}
```

## operator overloading rules

-   并不是所有的运算符都可以重载。能够重载的运算符包括：
    -   /  %  ^  &  |  ~  !  =  <  >  +=  -=  *=  /=  %=  ^=  &=  |=  <<  >>  <<=  >>=  ==  !=  <=  >=  &&  ||  ++  --  ,  ->*  ->  ()  []  new  new[]  delete  delete[]
    -   上述运算符中，[]是下标运算符，()是函数调用运算符。自增自减运算符的前置和后置形式都可以重载。
    -   长度运算符sizeof、条件运算符: ?、成员选择符.和域解析运算符::不能被重载。
    -   箭头运算符->、下标运算符[ ]、函数调用运算符( )、赋值运算符=只能以成员函数的形式重载
-   重载不能改变运算符的优先级和结合性。
-   重载不会改变运算符的用法，原来有几个操作数、操作数在左边还是在右边，这些都不会改变。例如~号右边只有一个操作数，+号总是出现在两个操作数之间，重载后也必须如此。
-   运算符重载函数不能有默认的参数，否则就改变了运算符操作数的个数，这显然是错误的。
-   运算符重载函数既可以作为类的成员函数，也可以作为全局函数。
    -   将运算符重载函数作为类的成员函数时，二元运算符的参数只有一个，一元运算符不需要参数。之所以少一个参数，是因为这个参数是隐含的。
    -   将运算符重载函数作为全局函数时，二元操作符就需要两个参数，一元操作符需要一个参数，而且其中必须有一个参数是对象，好让编译器区分这是程序员自定义的运算符，防止程序员修改用于内置类型的运算符的性质。
-   运算符重载的实质是将运算符重载为一个函数，使用运算符的表达式就被解释为对重载函数的调用。
-   类型的名字可以作为强制类型转换运算符，也可以被重载为类的成员函数。它能使得对象被自动转换为某种类型。

## math operator overloading

-   二元运算符最好以全局函数的形式重载
-   如果以成员函数的形式重载，则只能写成c1 + 15.6，因为+号具有左结合性，15.6 + c1会报错，这是因为编译器会尝试将15.6转换为Complex对象，但是没有转换构造函数Complex(double)，因此如果以成员函数的形式重载，需要补充转换构造函数

```c++
#include <iostream>
#include <cmath>
using namespace std;

//复数类
class Complex{
public:  //构造函数
    Complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ }
public:  //运算符重载
    //以全局函数的形式重载
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);
    friend bool operator==(const Complex &c1, const Complex &c2);
    friend bool operator!=(const Complex &c1, const Complex &c2);
    //以成员函数的形式重载
    Complex & operator+=(const Complex &c);
    Complex & operator-=(const Complex &c);
    Complex & operator*=(const Complex &c);
    Complex & operator/=(const Complex &c);
public:  //成员函数
    double real() const{ return m_real; }
    double imag() const{ return m_imag; }
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

//重载+运算符
Complex operator+(const Complex &c1, const Complex &c2){
    Complex c;
    c.m_real = c1.m_real + c2.m_real;
    c.m_imag = c1.m_imag + c2.m_imag;
    return c;
}
//重载-运算符
Complex operator-(const Complex &c1, const Complex &c2){
    Complex c;
    c.m_real = c1.m_real - c2.m_real;
    c.m_imag = c1.m_imag - c2.m_imag;
    return c;
}
//重载*运算符  (a+bi) * (c+di) = (ac-bd) + (bc+ad)i
Complex operator*(const Complex &c1, const Complex &c2){
    Complex c;
    c.m_real = c1.m_real * c2.m_real - c1.m_imag * c2.m_imag;
    c.m_imag = c1.m_imag * c2.m_real + c1.m_real * c2.m_imag;
    return c;
}
//重载/运算符  (a+bi) / (c+di) = [(ac+bd) / (c²+d²)] + [(bc-ad) / (c²+d²)]i
Complex operator/(const Complex &c1, const Complex &c2){
    Complex c;
    c.m_real = (c1.m_real*c2.m_real + c1.m_imag*c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
    c.m_imag = (c1.m_imag*c2.m_real - c1.m_real*c2.m_imag) / (pow(c2.m_real, 2) + pow(c2.m_imag, 2));
    return c;
}
//重载==运算符
bool operator==(const Complex &c1, const Complex &c2){
    if( c1.m_real == c2.m_real && c1.m_imag == c2.m_imag ){
        return true;
    }else{
        return false;
    }
}
//重载!=运算符
bool operator!=(const Complex &c1, const Complex &c2){
    if( c1.m_real != c2.m_real || c1.m_imag != c2.m_imag ){
        return true;
    }else{
        return false;
    }
}

//重载+=运算符
Complex & Complex::operator+=(const Complex &c){
    this->m_real += c.m_real;
    this->m_imag += c.m_imag;
    return *this;
}
//重载-=运算符
Complex & Complex::operator-=(const Complex &c){
    this->m_real -= c.m_real;
    this->m_imag -= c.m_imag;
    return *this;
}
//重载*=运算符
Complex & Complex::operator*=(const Complex &c){
    this->m_real = this->m_real * c.m_real - this->m_imag * c.m_imag;
    this->m_imag = this->m_imag * c.m_real + this->m_real * c.m_imag;
    return *this;
}
//重载/=运算符
Complex & Complex::operator/=(const Complex &c){
    this->m_real = (this->m_real*c.m_real + this->m_imag*c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
    this->m_imag = (this->m_imag*c.m_real - this->m_real*c.m_imag) / (pow(c.m_real, 2) + pow(c.m_imag, 2));
    return *this;
}

int main(){
    Complex c1(25, 35);
    Complex c2(10, 20);
    Complex c3(1, 2);
    Complex c4(4, 9);
    Complex c5(34, 6);
    Complex c6(80, 90);
   
    Complex c7 = c1 + c2;
    Complex c8 = c1 - c2;
    Complex c9 = c1 * c2;
    Complex c10 = c1 / c2;
    cout<<"c7 = "<<c7.real()<<" + "<<c7.imag()<<"i"<<endl;
    cout<<"c8 = "<<c8.real()<<" + "<<c8.imag()<<"i"<<endl;
    cout<<"c9 = "<<c9.real()<<" + "<<c9.imag()<<"i"<<endl;
    cout<<"c10 = "<<c10.real()<<" + "<<c10.imag()<<"i"<<endl;
   
    c3 += c1;
    c4 -= c2;
    c5 *= c2;
    c6 /= c2;
    cout<<"c3 = "<<c3.real()<<" + "<<c3.imag()<<"i"<<endl;
    cout<<"c4 = "<<c4.real()<<" + "<<c4.imag()<<"i"<<endl;
    cout<<"c5 = "<<c5.real()<<" + "<<c5.imag()<<"i"<<endl;
    cout<<"c6 = "<<c6.real()<<" + "<<c6.imag()<<"i"<<endl;
   
    if(c1 == c2){
        cout<<"c1 == c2"<<endl;
    }
    if(c1 != c2){
        cout<<"c1 != c2"<<endl;
    }
   
    return 0;
}
```

## >> and << operator overloading

```c++
#include <iostream>
using namespace std;

class complex{
public:
    complex(double real = 0.0, double imag = 0.0): m_real(real), m_imag(imag){ };
public:
    friend complex operator+(const complex & A, const complex & B);
    friend complex operator-(const complex & A, const complex & B);
    friend complex operator*(const complex & A, const complex & B);
    friend complex operator/(const complex & A, const complex & B);
    friend istream & operator>>(istream & in, complex & A);
    friend ostream & operator<<(ostream & out, complex & A);
private:
    double m_real;  //实部
    double m_imag;  //虚部
};

//重载加法运算符
complex operator+(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real + B.m_real;
    C.m_imag = A.m_imag + B.m_imag;
    return C;
}

//重载减法运算符
complex operator-(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real - B.m_real;
    C.m_imag = A.m_imag - B.m_imag;
    return C;
}

//重载乘法运算符
complex operator*(const complex & A, const complex &B){
    complex C;
    C.m_real = A.m_real * B.m_real - A.m_imag * B.m_imag;
    C.m_imag = A.m_imag * B.m_real + A.m_real * B.m_imag;
    return C;
}

//重载除法运算符
complex operator/(const complex & A, const complex & B){
    complex C;
    double square = A.m_real * A.m_real + A.m_imag * A.m_imag;
    C.m_real = (A.m_real * B.m_real + A.m_imag * B.m_imag)/square;
    C.m_imag = (A.m_imag * B.m_real - A.m_real * B.m_imag)/square;
    return C;
}

//重载输入运算符
istream & operator>>(istream & in, complex & A){
    in >> A.m_real >> A.m_imag;
    return in;
}

//重载输出运算符
ostream & operator<<(ostream & out, complex & A){
    out << A.m_real <<" + "<< A.m_imag <<" i ";;
    return out;
}

int main(){
    complex c1, c2, c3;
    cin>>c1>>c2;
 
    c3 = c1 + c2;
    cout<<"c1 + c2 = "<<c3<<endl;

    c3 = c1 - c2;
    cout<<"c1 - c2 = "<<c3<<endl;

    c3 = c1 * c2;
    cout<<"c1 * c2 = "<<c3<<endl;

    c3 = c1 / c2;
    cout<<"c1 / c2 = "<<c3<<endl;

    return 0;
}
```

## [] operator overloading

```	c++
#include <iostream>
using namespace std;

class Array {
public:
    Array(int length);
    ~Array();

    int& operator[](int i);
    const int& operator[](int i) const;

    int length() const { return m_length; }
    void display() const;
private:
    int m_length;
    int* m_p;
};

Array::Array(int length): m_length(length) {
    if (m_length == 0) {
        m_p = NULL;
    } else {
        m_p = new int[m_length];
    }
}

Array::~Array() {
    delete []m_p;
}

int& Array::operator[](int i) {
    return m_p[i];
}

const int & Array::operator[](int i) const {
    return m_p[i];
}

void Array::display() const {
    if (m_length == 0) {
        cout << "array is empty" << endl;
    }
    for (int i = 0; i < m_length; i++) {
        cout << m_p[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Array A(n);
    for(int i = 0, len = A.length(); i < len; i++){
        A[i] = i * 5;
    }
    A.display();

    const Array B(n);
    cout << B[n-1] << endl;
}
```

## ++ and -- operator overloading

```c++
#include <iostream>
#include <iomanip>
using namespace std;

class stopwatch {
public:
    stopwatch(int min, int sec): m_min(min), m_sec(sec) { }

    void set_zero();
    stopwatch run();
    stopwatch operator++();
    stopwatch operator++(int n);
    friend ostream& operator<<(ostream&, const stopwatch&);

private:
    int m_min;
    int m_sec;
};

void stopwatch::set_zero() {
    m_min = 0;
    m_sec = 0;
}

stopwatch stopwatch::run() {
    m_sec++;
    if (m_sec == 60) {
        m_min++;
        m_sec = 0;
    }
    return *this;
}

// 前置++直接返回对象，后置++修改对象的值且返回修改前的副本
stopwatch stopwatch::operator++() {
    run();
    return *this;
}

stopwatch stopwatch::operator++(int n) {
    stopwatch sw = *this;
    run();
    return sw;
}

ostream& operator<<(ostream& os, const stopwatch& sw) {
    os << setfill('0') << setw(2) << sw.m_min << ":" << setw(2) << sw.m_sec;
    return os;
}

int main() {
    stopwatch s1(0,0), s2(0,0);
    s1 = s2++;
    cout << "s1: "<< s1 <<endl;
    cout << "s2: "<< s2 <<endl;
    s1.set_zero();
    s2.set_zero();
    s1 = ++s2;
    cout << "s1: "<< s1 <<endl;
    cout << "s2: "<< s2 <<endl;
    return 0;
}
```

## new and delete operator overloading

-   在重载 new 或 new[] 时，无论是作为成员函数还是作为全局函数，它的第一个参数必须是 size_t 类型。size_t 表示的是要分配空间的大小，对于 new[] 的重载函数而言，size_t 则表示所需要分配的所有空间的总和。
-   其重载形式既可以是类的成员函数，也可以是全局函数。一般情况下，内建的内存管理运算符就够用了，只有在需要自己管理内存时才会重载。

## () operator overloading

```c++
#include <iostream>
using namespace std;

class Complex
{
    double real, imag;
public:
    Complex(double r = 0, double i = 0) :real(r), imag(i) {};
    operator double() { return real; }  //重载强制类型转换运算符 double
};
int main()
{
    Complex c(1.2, 3.4);
    cout << (double)c << endl;  //输出 1.2 double(c)等价于c.operator double()
    double n = 2 + c;  //等价于 double n = 2 + c. operator double()
    cout << n;  //输出 3.2
}
```



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

# Section8 exception

-   程序的错误大致可以分为三种，分别是语法错误、逻辑错误和运行时错误：
    -   语法错误在编译和链接阶段就能发现，只有 100% 符合语法规则的代码才能生成可执行程序。语法错误是最容易发现、最容易定位、最容易排除的错误，程序员最不需要担心的就是这种错误。
    -   逻辑错误是说我们编写的代码思路有问题，不能够达到最终的目标，这种错误可以通过调试来解决。
    -   运行时错误是指程序在运行期间发生的错误，例如除数为 0、内存分配失败、数组越界、文件不存在等。[C++](http://c.biancheng.net/cplus/) 异常（Exception）机制就是为解决运行时错误而引入的。
-   运行时错误如果放任不管，系统就会执行默认的操作，终止程序运行，也就是我们常说的程序崩溃（Crash）。C++ 提供了异常（Exception）机制，让我们能够捕获运行时错误，给程序一次“起死回生”的机会，或者至少告诉用户发生了什么再终止程序。

## an example

```c++
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// cannot run in vscode, can run in clion successfully

int main(){
    string str = "http://c.biancheng.net";

     try{
         char ch1 = str[100];
         cout<<ch1<<endl;
     }catch(exception e){
         cout<<"[1]out of bound!"<<endl;
     }

    try{
        char ch2 = str.at(100);
        cout<<ch2<<endl;
    }catch(exception &e){  //exception类位于<exception>头文件中
        cout<<"[2]out of bound!"<<endl;
    }
    return 0;
}
```

-   捕获异常的语法

    -   ```
        try{
            // 可能抛出异常的语句
        }catch(exceptionType variable){
            // 处理异常的语句
        }
        ```

-   处理异常的过程

    -   抛出（Throw）--> 检测（Try） --> 捕获（Catch）
    -   发生异常时必须将异常明确地抛出，try 才能检测到；如果不抛出来，即使有异常 try 也检测不到。所谓抛出异常，就是明确地告诉程序发生了什么错误。
    -   检测到异常后程序的执行流会发生跳转，从异常点跳转到 catch 所在的位置，位于异常点之后的、并且在当前 try 块内的语句就都不会再执行了；即使 catch 语句成功地处理了错误，程序的执行流也不会再回退到异常点，所以这些语句永远都没有执行的机会了。

## exception type and multi-level matching

### exception type

-   `exceptionType`是异常类型，它指明了当前的 catch 可以处理什么类型的异常；`variable`是一个变量，用来接收异常信息。当程序抛出异常时，会创建一份数据，这份数据包含了错误信息。
-   异常类型可以是 int、char、float、bool 等基本类型，也可以是指针、数组、字符串、结构体、类等聚合类型。C++ 语言本身以及标准库中的函数抛出的异常，都是 exception 类或其子类的异常。也就是说，抛出异常时，会创建一个 exception 类或其子类的对象。
-   `exceptionType variable`和函数的形参非常类似，当异常发生后，会将异常数据传递给 variable 这个变量，这和函数传参的过程类似。当然，只有跟 exceptionType 类型匹配的异常数据才会被传递给 variable，否则 catch 不会接收这份异常数据，也不会执行 catch 块中的语句，即catch 不会处理当前的异常。
-   如果只是`catch(exceptionType)`，没有variable，则仅匹配异常类型，不传递异常信息。

### multi-level matching

-   当异常发生时，程序会按照从上到下的顺序，将异常类型和 catch 所能接收的类型逐个匹配。一旦找到类型匹配的 catch 就停止检索，并将异常交给当前的 catch 处理（其他的 catch 不会被执行）。如果最终也没有找到匹配的 catch，就只能交给系统处理，终止程序的运行。

```c++
try{
    //可能抛出异常的语句
}catch (exception_type_1 e){
    //处理异常的语句
}catch (exception_type_2 e){
    //处理异常的语句
}
//其他的catch
catch (exception_type_n e){
    //处理异常的语句
}
```

-   多级catch的用法

```c++
#include <iostream>
#include <string>
using namespace std;

class Base{ };
class Derived: public Base{ };
int main(){
    try{
        throw Derived();  //抛出自己的异常类型，实际上是创建一个Derived类型的匿名对象
        cout<<"This statement will not be executed."<<endl;
    }catch(int){
        cout<<"Exception type: int"<<endl;
    }catch(char *){
        cout<<"Exception type: cahr *"<<endl;
    }catch(Base){  //匹配成功（向上转型）
        cout<<"Exception type: Base"<<endl;
    }catch(Derived){
        cout<<"Exception type: Derived"<<endl;
    }
    return 0;
}
```

-   普通函数（非模板函数）的类型转换
    -   算数转换：例如 int 转换为 float，char 转换为 int，double 转换为 int 等。
    -   向上转型：也就是派生类向基类的转换。
    -   const 转换：也即将非 const 类型转换为 const 类型，例如将 char * 转换为 const char *。
    -   数组或函数指针转换：如果函数形参不是引用类型，那么数组名会转换为数组指针，函数名也会转换为函数指针。
    -   用户自定的类型转换。
-   catch在匹配过程中的类型转换
    -   仅能进行「向上转型」、「const 转换」和「数组或函数指针转换」

-   const转换例子

```c++
#include <iostream>
using namespace std;
int main(){
    int nums[] = {1, 2, 3};
    try{
        throw nums;
        cout<<"This statement will not be executed."<<endl;
    }catch(const int *){
        cout<<"Exception type: const int *"<<endl;
    }
    return 0;
}
```



## throw

-    C++ 使用 throw 关键字来显式地抛出异常

### an example

-   动态数组的例子
    -   C/C++ 规定，数组一旦定义后，它的长度就不能改变了；换句话说，数组容量不能动态地增大或者减小。这样的数组称为静态数组（Static array）。静态数组有时候会给编码代码不便，我们可以通过自定义的 Array 类来实现动态数组（Dynamic array）。所谓动态数组，是指数组容量能够在使用的过程中随时增大或减小。

```c++
#include <iostream>
using namespace std;

//自定义的异常类型
class OutOfRange{
public:
    OutOfRange(): m_flag(1){ };
    OutOfRange(int len, int index): m_len(len), m_index(index), m_flag(2){ }
public:
    void what() const;  //获取具体的错误信息
private:
    int m_flag;  //不同的flag表示不同的错误
    int m_len;  //当前数组的长度
    int m_index;  //当前使用的数组下标
};

void OutOfRange::what() const {
    if(m_flag == 1){
        cout<<"Error: empty array, no elements to pop."<<endl;
    }else if(m_flag == 2){
        cout<<"Error: out of range( array length "<<m_len<<", access index "<<m_index<<" )"<<endl;
    }else{
        cout<<"Unknown exception."<<endl;
    }
}

//实现动态数组
class Array{
public:
    Array();
    ~Array(){
        delete []m_p;
    };
public:
    int operator[](int i) const;  //获取数组元素
    int push(int ele);  //在末尾插入数组元素
    int pop();  //在末尾删除数组元素
    int length() const{ return m_len; };  //获取数组长度
private:
    int m_len;  //数组长度
    int m_capacity;  //当前的内存能容纳多少个元素
    int *m_p;  //内存指针
private:
    static const int m_stepSize = 5;  //每次扩容的步长
};

Array::Array(){
    m_p = new int[m_stepSize];
    m_capacity = m_stepSize;
    m_len = 0;
}

int Array::operator[](int index) const {
    if( index<0 || index>=m_len ){  //判断是否越界
        throw OutOfRange(m_len, index);  //抛出异常（创建一个匿名对象）
    }

    return *(m_p + index);
}

int Array::push(int ele){
    if(m_len >= m_capacity){  //如果容量不足就扩容
        m_capacity += m_stepSize;
        int* tmp = new int[m_capacity];  //扩容
        memcpy(tmp, m_p, (m_capacity - m_stepSize) * sizeof(int));
        m_p = tmp;
    }
    *(m_p + m_len) = ele;
    m_len++;
    return m_len-1;
}

int Array::pop(){
    if(m_len == 0){
        throw OutOfRange();  //抛出异常（创建一个匿名对象）
    }

    m_len--;
    return *(m_p + m_len);
}

//打印数组元素
void printArray(Array &arr){
    int len = arr.length();

    //判断数组是否为空
    if(len == 0){
        cout<<"Empty array! No elements to print."<<endl;
        return;
    }

    for(int i=0; i<len; i++){
        if(i == len-1){
            cout<<arr[i]<<endl;
        }else{
            cout<<arr[i]<<", ";
        }
    }
}

int main(){
    Array nums;
    //向数组中添加十个元素
    for(int i=0; i<10; i++){
        nums.push(i);
    }
    printArray(nums);

    //尝试访问第20个元素
    try{
        cout<<nums[20]<<endl;
    }catch(OutOfRange &e){
        e.what();
    }

    //尝试弹出20个元素
    try{
        for(int i=0; i<20; i++){
            nums.pop();
        }
    }catch(OutOfRange &e){
        e.what();
    }

    printArray(nums);

    return 0;
}
```

### throw used as an exception specification

不常用

## c++ exception class

-   c++语言本身或者标准库抛出的异常都是 exception 的子类，称为标准异常（S[tan](http://c.biancheng.net/ref/tan.html)dard Exception）。

-   ```c++
    try{
        //可能抛出异常的语句
    }catch(exception &e){
        //处理异常的语句
    }
    ```

-   ```c++
    class exception{
    public:
        exception () throw();  //构造函数
        exception (const exception&) throw();  //拷贝构造函数
        exception& operator= (const exception&) throw();  //运算符重载
        virtual ~exception() throw();  //虚析构函数
        virtual const char* what() const throw();  //虚函数
    }
    ```

![avrtar](/Users/bingjian.yan/recent_learning/cpp_learning/20211105/pictures/exception_v1.jpeg)



# Section9 c++面向对象进阶

# Section10 输入输出流

# Section11 文件操作

# Section12 c++多文件编程

