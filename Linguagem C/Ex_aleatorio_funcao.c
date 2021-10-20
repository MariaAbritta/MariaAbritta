/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void imprime_qualquer_coisa(); //Avisando que existe a função
int calcula_dobro(int numero);

int main(){
    int numero, dobro;
    imprime_qualquer_coisa();
    printf("digite um numero: ");
    scanf("%d", &numero);
    
    dobro = calcula_dobro(numero);
    
    printf("O dobro e: %d\n", dobro);
    return 0;
}

void imprime_qualquer_coisa (){ //Void = Procedimento
    printf("Qualquer coisa! \n");
}

int calcula_dobro(int numero){
    return numero * 2;
}