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