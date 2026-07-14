#include "string.h"

void strcrear(string& s) {
    s = new char[1];
    s[0] = '\0';
}

void strdestruir(string& s) {
    delete[] s;
    s = NULL;
}

int strlar(string s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void strcop(string& s1, string s2) {
    int i = 0;
    int largo = strlar(s2) + 1;
    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void scan(string& s) {
    string aux = new char[MAX];
    int i = 0;
    char c;
    scanf(" %c", &c);
    while (c != '\n' && i < MAX - 1) {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }
    aux[i] = '\0';
    strcop(s, aux);
    strdestruir(aux);
}

void print(string s) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

void printRojo(string s) {
    print(rojo);
    print(s);
    print(reset);
}

void printVerde(string s) {
    print(verde);
    print(s);
    print(reset);
}

boolean streq(string s1, string s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return FALSE;
        i++;
    }
    if ((s1[i] == '\0' && s2[i] == '\0')) {
        return TRUE;
    } else {
        return FALSE;
    }
}
