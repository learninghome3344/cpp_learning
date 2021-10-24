#include <iostream>
#include <string>
using namespace std;


// type &name = data;


void swap1(int a, int b);
void swap2(int *p1, int *p2);
void swap3(int &r1, int &r2);

int& plus10(int& r) {
    r += 10;
    return r;
    // ���ؾֲ�����������
    // int m = r + 10;
    // return m;
}


int main() {
    int a = 99;
    int& b = a;
    b = 22;
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;

    // ��ϣ��ͨ�������޸�ԭʼ����
    // const type &name = value; ���� type const &name = value;

    // ������Ϊ��������
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

    // ������Ϊ��������ֵ
    int x = 10;
    int& y = plus10(x);
    cout << x << " " << y << " " << &x << " " << &y << endl;
    // ������Ϊ��������ֵʱ���ܷ��ؾֲ����ݵ����á���Ϊ����������ֲ����ݾͻᱻ����
    int& num3 = plus10(x);
    int& num4 = plus10(num3);
    cout << num3 << " " << num4 << " " << &num3 << " " << &num4 << endl;
}

//ֱ�Ӵ��ݲ�������
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
//����ָ��
void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
//�����ô���
void swap3(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}