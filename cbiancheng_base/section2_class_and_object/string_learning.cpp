#include <iostream>
#include <string>
using namespace std;


int main() {
    // 初始化方式
    string s1;
    string s2 = "c plus plus";
    string s3 = s2;
    string s4 (5, 's');

    // 遍历 下标
    string s = "1234567890";
    for (int i = 0; i < s.length(); ++i) {
        cout << s[i] << ",";
    }
    cout << endl;

    // 转换为c风格字符串, 例如在作为文件路径时必须打开
    cout << s << "\t" << s.c_str() << endl;

    // string的输入输出
    string s5;
    cin >> s5;  //输入字符串
    cout << s5 << endl;  //输出字符串

    // 字符串的拼接，string可以和string，c风格字符，字符数组，单个字符进行拼接
    string s6 = "six ";
    char* s7 = "seven ";
    char s8[] = "eight ";
    char ch = '@';
    cout << s5 + s6 << " " << s5 + s7 << " " << s5 + s8 << " " << s5 + ch << endl;

    // 增删改查
    /// 插入字符串 string& insert (size_t pos, const string& str);
    cout << s << endl;
    s.insert(5, "aaa");
    cout << s << endl;
    /// 删除字符串 string& erase (size_t pos = 0, size_t len = npos);
    s.erase(5, 3);
    cout << s << endl;
    /// 提取子字符串 string substr (size_t pos = 0, size_t len = npos) const;
    cout << s.substr(5, 3) << endl;
    /// 查找字符串find,rfind,find_first_of：find从pos位置往后找，rfind最多查到pos位置,find_first_of查到首次出现的位置
    //// size_t find (const string& str, size_t pos = 0) const;
    //// size_t rfind( const string& str, size_t pos = npos ) const;
    string ss = "678";
    int index = s.find(ss, 2);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    index = s.rfind(ss, 2);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }
    index = s.find_first_of(ss);
    if (index < s.length()) {
        cout << "Found at index " << index << endl;
    } else {
        cout << "Not found" << endl;
    }




    
}