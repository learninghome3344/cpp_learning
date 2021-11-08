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