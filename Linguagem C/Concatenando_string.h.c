/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

//strcat = concatena strings

int main(){

char str[11]="Curso";

strcat(str, "de C");
//Concatenar a strind "de C" com o conteúdo da string str
    
    printf("str = %s \n", str);
    //Exibir o C
    
printf("-----------------------------------\n");

char str1[21]="Curso", str2[18]= " de programacao C";

    strncat(str1, str2, 15);
    printf("str1 = %s \n", str1);
    //Curso de progamação
    return 0;
}
