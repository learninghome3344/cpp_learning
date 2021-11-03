#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


/// 1) 当非类型参数是一个整数时，传递给它的实参，或者由编译器推导出的实参必须是一个常量表达式，
/// 例如10、2 * 30、18 + 23 - 4等，但不能是n、n + 10、n + m等（n 和 m 都是变量）。

/// 2) 当非类型参数是一个指针（引用）时，绑定到该指针的实参必须具有静态的生存期；
/// 换句话说，实参必须存储在虚拟地址空间中的静态数据区。局部变量位于栈区，动态创建的对象位于堆区，
/// 它们都不能用作实参。



template<typename T, int N>
class Array{
public:
    Array();
    ~Array();
public:
    T & operator[](int i);  //重载下标运算符[]
    int length() const { return m_length; }  //获取数组长度
    bool capacity(int n);  //改变数组容量
private:
    int m_length;  //数组的当前长度
    int m_capacity;  //当前内存的容量（能容乃的元素的个数）
    T *m_p;  //指向数组内存的指针
};

template<typename T, int N>
Array<T, N>::Array(){
    m_p = new T[N];
    m_capacity = m_length = N;
}

template<typename T, int N>
Array<T, N>::~Array(){
    delete[] m_p;
}

template<typename T, int N>
T & Array<T, N>::operator[](int i){
    if(i<0 || i>=m_length){
        cout<<"Exception: Array index out of bounds!"<<endl;
    }
    return m_p[i];
}

template<typename T, int N>
bool Array<T, N>::capacity(int n){
    if(n > 0){  //增大数组
        int len = m_length + n;  //增大后的数组长度
        if(len <= m_capacity){  //现有内存足以容纳增大后的数组
            m_length = len;
            return true;
        }else{  //现有内存不能容纳增大后的数组
            //增加的内存足以容纳 2*n 个元素, 为啥要是2n，改成n也可正常运行
            T *pTemp = new T[m_length + 2 * n * sizeof(T)];  
            if(pTemp == NULL){  //内存分配失败
                cout<<"Exception: Failed to allocate memory!"<<endl;
                return false;
            }else{  //内存分配成功
                memcpy( pTemp, m_p, m_length*sizeof(T) );
                delete[] m_p;
                m_p = pTemp;
                m_capacity = m_length = len;
            }
        }
    }else{  //收缩数组
        int len = m_length - abs(n);  //收缩后的数组长度
        if(len < 0){
            cout<<"Exception: Array length is too small!"<<endl;
            return false;
        }else{
            m_length = len;
            return true;
        }
    }
}


int main(){
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