#include <iostream>
#include <cstring>

int main() {
    char s1[] = "hello ";
    char s2[] = "world";
    char s[strlen(s1) + strlen(s2) - 1];

    strcpy(s, s1);
    strcat(s, s2);

    std::cout << s << std::endl;
}