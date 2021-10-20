/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(){
  
char str1[15]="Curso de C", str2[15]="Curso de Java";
int retorno;

retorno = strncmp(str1, str2, 5); //0 =string iguais //<0 string1 menor que string2// >0 string1 maior que string2

    printf("Retorno = %d\n", retorno);
    return 0;
}
