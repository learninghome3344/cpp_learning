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