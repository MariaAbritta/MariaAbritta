/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>

//Faça um programa que receba uma sequência indefinida de números inteiros
//E retorna quantos números negativos foram inseridos
//A sequência termina quando o usuáruio inserir um número > 100
void imprime_resultado(int quant);
void eh_negatvio(int num, int* apontador);

int main(){
int numero, conta_negatvios=0;

    do{
        printf("Digite um numero: ");
        scanf(" %d", &numero);
        eh_negatvio(numero, &conta_negatvios);
    }while(numero<=100);

    imprime_resultado(conta_negatvios);
}

void imprime_resultado(int quant){
    printf("\t Quantidade de nagativos = %d \n", quant);
}

void eh_negatvio(int num, int *apontador){
    if(num < 0){
        (*apontador)++;
    }
}