#include <iostream>
#include "Sales_item.h"
using namespace std;

// ��ȡ�������ۼ�¼��ͳ��ÿ�����м������ۼ�¼
// ע��ÿ����ļ�¼Ӧ������
int main() {
    Sales_item cur_item, item;
    if (!(cin >> cur_item)) {
        cerr << "no data" << endl;
    }
    while (cin >> item) {
        if (cur_item.isbn() == item.isbn()) {
            cur_item += item;
        } else {
            cout << cur_item << endl;
            cur_item = item;
        }
    }
    cout << cur_item << endl;
}