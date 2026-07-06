#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>
#include "boolean.h"

const int MAX =80;
typedef char str[MAX];

///carga el string con caracteres
void strscan (str &s);

///despliega por pantalla el string
void strprint (str s);

///devuelve cant caracteres
int strlar (str s);

///recibe dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq (str s, str z);

///recibe dos string y devuelve TRUE si el primero de ellos es menor (en orden alfabetico) o FALSE en caso contrario
boolean strmen (str s, str z);

///recibe dos string y copia el segundo en el primero
void strcop (str &s, str z);

///recibe dos string y concatena el segundo al final del primero
void strcon (str &s, str z);

///recibe dos string y devuelve el primero en el segundo y viceversa
void strswap (str &s, str &z);


#endif // STRING_H_INCLUDED
