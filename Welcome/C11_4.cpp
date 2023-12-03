#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


int strlen(char str[]);
int strlen_p(char *cp);
int strlen_pv2(char *str);

int main_C11(){
    char input_s[] = "a";
    cout << strlen(input_s);

    char *input_S_p = "hello\n";
    cout << "\n" << strlen_p(input_S_p);

    char *input_S_pv2 = "hello world \n";
    cout << "\n" << strlen_pv2(input_S_pv2);
    return 0;
}

int strlen(char str[]) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n;
}

int strlen_p(char *cp) {
    int n = 0;
    while (*cp++ != '\0') {
        n++;
    }
    return n;
}

int strlen_pv2(char *str) {
    char *cp;
    for (cp = str; *cp != '\0'; cp++);
    return cp - str;
}
