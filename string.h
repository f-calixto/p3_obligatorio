#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

#include "boolean.h"

const int MAX = 80;
typedef char* string;
const string rojo = "\033[31m";
const string verde = "\033[32m";
const string reset = "\033[0m";

/* crea un string vac�o */
void strcrear(string& s);

/* libera la memoria usada por el string */
void strdestruir(string& s);

/* devuelve el largo del string s */
int strlar(string s);

/* copia el contenido del string s2 en s1 */
void strcop(string& s1, string s2);

/* lee el string s desde teclado */
void scan(string& s);

/* concatena el contenido de s2 al final de s1 */
void strcon(string& s1, string s2);

/* intercambia los contenidos de s1 y s2 */
void strswp(string& s1, string& s2);

/* imprime el string s por pantalla */
void print(string s);

/* Imprime el string en rojo por pantalla*/
void printRojo(string s);

/* Imprime el string en verde por pantalla*/
void printVerde(string s);

/* determina si s1 es alfab�ticamente menor que s2 */
boolean strmen(string s1, string s2);

/* determina si los strings s1 y s2 son iguales */
boolean streq(string s1, string s2);

/* convierte el string s a minuscula y lo almacena en resultado */
void strMinus(string s, string& resultado);

/* Indica si el string representa un entero valido */
boolean esEnteroValido(string s);

boolean esEnteroPositivo(string str);

// convierte el string s a un entero
// precondicion: es un entero valido
int strAEntero(string s);

#endif  // STRING_H_INCLUDED
