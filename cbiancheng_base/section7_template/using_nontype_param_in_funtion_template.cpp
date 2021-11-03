#include <iostream>
using namespace std;


/// int& array[10] 和 int (&attay)[10] 
/// 对于int& array[10]， array 首先向右结合，即array[10]，整体表示array索引为10的整型变量的引用
/// 对于int (&array)[10]，array首先和&结合，则表示数组array的引用


template<typename T> void Swap(T& a, T& b); // 模板①：交换基本类型的值
template<typename T, unsigned N> void Swap(T (&a)[N], T (&b)[N]); //模板②：交换两个数组


template<typename T, unsigned N> void printArray(T (&arr)[N]);  //打印数组元素

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

template<class T> void Swap(T &a, T &b){
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