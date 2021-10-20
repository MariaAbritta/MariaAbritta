/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(){

char str[] = "Curso de programacao C";
int tamanho;

tamanho = strlen(str);
//Strlen calcula o tamanho de uma srting e volta um inteiro.
    printf("o tamanho da string %s vale %d \n", str, tamanho);
    return 0;
}
