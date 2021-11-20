#include <iostream>
#include "Sales_item.h"
using namespace std;

// 读取多条销售记录，统计每本书有几条销售记录
// 注意每本书的记录应该连续
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