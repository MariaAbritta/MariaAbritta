/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

 // Calcular faotrial:
 
int fatorial(int n);

int fatorial(int n){
    int f=1;
    for(int i = 2; i <= n; i++){
        f = f * i;
    }
    return f;
}

int main(){
    int x;
    int y;
    float res;
    
    printf("Entre com um numero inteiro maior que 0: ");
    scanf("%d", &x);
    printf("Entre com outro numero inteiro maior que 0: ");
    scanf("%d", &y);
    
    //printf("O fatorial de 5 e: %d \n", fatorial(5));
    
    res = fatorial(x+y)/(fatorial(x) + fatorial(y));
    printf("O resultado da expressao e %.f", res);
}