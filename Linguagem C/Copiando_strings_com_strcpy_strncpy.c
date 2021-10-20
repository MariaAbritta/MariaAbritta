/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(){

char nome1[15], nome2[15];

    printf("Digite seu nome: ");
    scanf("%s", nome1);
    printf("Nome: %s\n", nome1);
    
    strncpy(nome2, nome1, 3);
    //strcyp = string_Destino, string_origem)
    
    printf("Nome: %s\n", nome2);

    return 0;
}
