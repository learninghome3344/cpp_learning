#include <iostream>
using namespace std;


extern int i1 = 1; // ����������i1������ֵ������extern�ؼ��ֵ�����
extern int i2; // ����i2���Ƕ���i2
int i3; // ����������i3

int main() {
    // �������ʽ�����޷���������int��int��תΪ�޷�����������㡣
    unsigned u = 10;
    int i = -42;  // -42 % 2^32
    cout << i + i << " " << u + i << endl;

    cout << "ha ha "
            "xi xi" << endl;

    char s1 = 'a';
    auto s2 = L'a';  // ���Lǰ׺�����ͱ�Ϊ/wchar_t
    cout << sizeof(s1) << " " << sizeof(s2) << endl;

    cout << "2\115\n" << endl;

    // int a = b = 1; //δ�����ʶ�� "b"C/C++(20)
    int a, b;
    a = b = 1;

    // �ں������ڲ������ͼ��ʼ��һ��extern��ǵı����ᱨ��
    // extern int i1 = 1; // ��������ⲿ�����ľֲ�����ʹ�ó�ʼֵ�趨��C/C++(2442)

    // ��������ֻ�ܱ�����һ�Σ����ǿ��Ա����������
}