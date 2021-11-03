#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


/// 1) �������Ͳ�����һ������ʱ�����ݸ�����ʵ�Σ������ɱ������Ƶ�����ʵ�α�����һ���������ʽ��
/// ����10��2 * 30��18 + 23 - 4�ȣ���������n��n + 10��n + m�ȣ�n �� m ���Ǳ�������

/// 2) �������Ͳ�����һ��ָ�루���ã�ʱ���󶨵���ָ���ʵ�α�����о�̬�������ڣ�
/// ���仰˵��ʵ�α���洢�������ַ�ռ��еľ�̬���������ֲ�����λ��ջ������̬�����Ķ���λ�ڶ�����
/// ���Ƕ���������ʵ�Ρ�



template<typename T, int N>
class Array{
public:
    Array();
    ~Array();
public:
    T & operator[](int i);  //�����±������[]
    int length() const { return m_length; }  //��ȡ���鳤��
    bool capacity(int n);  //�ı���������
private:
    int m_length;  //����ĵ�ǰ����
    int m_capacity;  //��ǰ�ڴ�������������˵�Ԫ�صĸ�����
    T *m_p;  //ָ�������ڴ��ָ��
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
    if(n > 0){  //��������
        int len = m_length + n;  //���������鳤��
        if(len <= m_capacity){  //�����ڴ�������������������
            m_length = len;
            return true;
        }else{  //�����ڴ治����������������
            //���ӵ��ڴ��������� 2*n ��Ԫ��, ΪɶҪ��2n���ĳ�nҲ����������
            T *pTemp = new T[m_length + 2 * n * sizeof(T)];  
            if(pTemp == NULL){  //�ڴ����ʧ��
                cout<<"Exception: Failed to allocate memory!"<<endl;
                return false;
            }else{  //�ڴ����ɹ�
                memcpy( pTemp, m_p, m_length*sizeof(T) );
                delete[] m_p;
                m_p = pTemp;
                m_capacity = m_length = len;
            }
        }
    }else{  //��������
        int len = m_length - abs(n);  //����������鳤��
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

    //Ϊ����Ԫ�ظ�ֵ
    for(int i=0, len=arr.length(); i<len; i++){
        arr[i] = 2*i;
    }
   
    //��һ�δ�ӡ����
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   

    //����������Ϊ���ӵ�Ԫ�ظ�ֵ
    arr.capacity(8);
    for(int i=5, len=arr.length(); i<len; i++){
        arr[i] = 2*i;
    }

    //�ڶ��δ�ӡ����
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //��������
    arr.capacity(-4);

    //�����δ�ӡ����
    for(int i=0, len=arr.length(); i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}