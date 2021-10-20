#include <stdio.h>

double potencia(double base, int expoente); //Protótipo da função

int main(){
    double x;
    int y;
    
    scanf(" %lf", &x);
    scanf(" %d", &y);
    printf(" %lf\n", potencia(x,y)); //Função.

}

double potencia(double base, int expoente){ //Código da função. Retorno só 1. 2 paprametros e pode ser vários.
    int i;
    double p;
    p=1;
    
    for(i=0; i<expoente; i++){
        p=p*base;
    }
    
    return p;
}


