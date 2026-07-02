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

void strcon(string& s1, string s2) {
    string aux;
    strcrear(aux);
    strcop(aux, s1);
    int largo = strlar(s1) + strlar(s2) + 1;
    if (largo > MAX) largo = MAX;
    delete[] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0') {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX - 1) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    strdestruir(aux);
}

void strswp(string& s1, string& s2) {
    string aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
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

boolean strmen(string s1, string s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] < s2[i])
            return TRUE;
        else if (s1[i] > s2[i])
            return FALSE;
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0') return TRUE;

    return FALSE;
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

void strMinus(string s, string& resultado) {
    strcop(resultado, s);
    int i = 0;
    while (resultado[i] != '\0') {
        if (resultado[i] >= 'A' && resultado[i] <= 'Z') {
            resultado[i] = resultado[i] + 32;
        }
        i++;
    }
}

boolean esEnteroValido(string s) {
    int i = 0;

    if (s[0] == '\0') {
        return FALSE;
    }

    // Verifica signo negativo opcional
    if (s[0] == '-') {
        i = 1;
    }

    if (s[i] == '\0') {
        return FALSE;
    }

    // Verificar que todos los caracteres sean d�gitos
    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') {
            return FALSE;
        }
        i++;
    }

    return TRUE;
}

int strAEntero(string s) {
    int resultado = 0;
    int i = 0;
    boolean esNegativo = FALSE;

    if (s[0] == '\0') {
        return 0;
    }

    if (s[0] == '-') {
        esNegativo = TRUE;
        i = 1;
    }

    while (s[i] != '\0') {
        resultado = resultado * 10 + (s[i] - '0');
        i++;
    }

    if (esNegativo) {
        resultado = resultado * -1;
    }

    return resultado;
}

void Bajar_String(string s, FILE* f) {
    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    char fin = '\0';
    fwrite(&fin, sizeof(char), 1, f);
}

void Levantar_String(string& s, FILE* f) {
    string aux = new char[MAX];
    char buffer;
    int i = 0;

    fread(&buffer, sizeof(char), 1, f);

    while (buffer != '\0' && i < MAX - 1) {
        aux[i] = buffer;
        i++;
        fread(&buffer, sizeof(char), 1, f);
    }

    aux[i] = '\0';
    strcrear(s);
    strcop(s, aux);

    delete[] aux;
}

boolean esOperador(string str) {
    if (streq(str, "+") || streq(str, "-") || streq(str, "/") ||
        streq(str, "*")) {
        return TRUE;
    } else {
        return FALSE;
    }
}

boolean esEnteroPositivo(string str) {
    if (esEnteroValido(str) && strAEntero(str) > 0) {
        return TRUE;
    }

    return FALSE;
}
