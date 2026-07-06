#include "string.h"



///carga el string con caracteres
void strscan (str &s)
{
   int i=0;
   char c;
   scanf("%c", &c);
   while((c!= '\n') && (i < MAX -1))
   {
       s[i] = c;
       i++;
       scanf ("%c", &c);
   }
    s[i] = '\0';
}



///despliega por pantalla el string
void strprint (str s)
{
    int i=0;
    while ((s[i] != '\0') && (i<MAX))
    {
        printf("%c", s[i]);
        i++;
    }
}



///devuelve cant caracteres
int strlar (str s)
{
  int i=0;
  while (s[i] != '\0')
    i++;
  return i;
}



///recibe dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq (str s, str z)
{
    boolean iguales = TRUE;
    int i =0;

    while ((iguales) && (s[i] != '\0') && (z[i] != '\0'))
    {
        if(s[i] != z[i])
            iguales = FALSE;
        else
            i++;
    }
    if ((s[i] != '\0') || (z[i] != '\0'))
        iguales = FALSE;
    return iguales;
}



///recibe dos string y devuelve TRUE si el primero de ellos es menor (en orden alfabetico) o FALSE en caso contrario
boolean strmen (str s, str z)
{
    int i =0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while((!encontre) && (s[i] != '\0') && (z[i] != '\0'))
    {
        if (s[i] != z[i])
            encontre = TRUE;
        if (s[i] < z[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (z[i] != '\0'))
        menor = TRUE;
    return menor;
}



///recibe dos string y copia el segundo en el primero
void strcop (str &s, str z)
{
    int i =0;
    while(z[i] != '\0')
    {
        s[i] = z[i];
        i++;
    }
    s[i] = '\0';
}



///recibe dos string y concatena el segundo al final del primero
void strcon (str &s, str z)
{
   int i = strlar(s);
   int j =0;
    while ((i < MAX - 1) && (z[j] != '\0'))
    {
        s[i] = z[j];
        i++;
        j++;
    }
    s[i] = '\0';
}



///recibe dos string y devuelve el primero en el segundo y viceversa
void strswap (str &s, str &z)
{
    str aux;
    strcop (aux,s);
    strcop(s,z);
    strcop (z,aux);
}
