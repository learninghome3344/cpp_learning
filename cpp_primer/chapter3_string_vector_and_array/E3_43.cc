#include <iostream>

int main() {
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};

    // ??Χfor
    for (int (&p)[4]: ia) {
        for (int &q: p) {
            std::cout << q << " ";
        }
        std::cout << std::endl;
    }

    // ????for
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // ָ??for
    for (int (*p)[4] = ia; p != ia+3; p++) {
        for (int *q = *p; q != *p+4; q++) {
            std:: cout << *q << " ";
        }
        std::cout << std::endl;
    }
}