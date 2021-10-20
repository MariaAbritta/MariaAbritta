#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void regras(); //Anunciando a função das regras.
int verifica_x (int x, int i, int verifica); //Anunciando a função que verifica o valor de x.
int verifica_y (int y, int i, int verifica); //Anunciando a função que verifica o valor de y.
int verifica_z (int z, int i, int verifica); //Anunciando a função que verifica o valor de z.
void menu(); //Anunciando a função do menu.

int main(){
    
int x, y, z, i, verifica, op, receptora, receptora2, receptora3, receptora4, receptora5, receptora6, n, j;
n=5;
int space, rows = 5, k=0;
float fatorial_x, fatorial_y, fatorial_z, resultado, fatorial_resultado2, resultado2, fatorial_resultado3, fatorial_resultado4, resultado3;
float fatorial_resultado5, fatorial_resultado6, resultado4; 
 
    printf("Seja Bem vindo! Precisamos que você adicione 3 numeros, MAS temos regras: \n"); //Entrada, onde já aparece as regras dos números.
    regras(); //Regras.
    printf("Adicione seu primeiro valor: "); //Inserção do primeiro valor (x).
    scanf("%d", &x); //Leitura do valor de x.
    verifica_x (x, i, verifica); //Fução para verificar se o valor de x está dentro das regras.
    printf("Adicione seu segundo valor: "); //Inserção do segundo valor (y).
    scanf("%d", &y); //Leitura do valor de y.
    verifica_y (y, i, verifica); //Fução para verificar se o valor de y está dentro das regras.
    printf("Adicione seu terceiro e ultimo valor: "); //Inserção do terceiro valor (z).
    scanf("%d", &z); //Leitura do valor de z.
    verifica_z (z, i, verifica); //Fução para verificar se o valor de z está dentro das regras.
    menu(); //Função do menu, que vai de 1 a 7.
    
    do{ //Repetição tipo looping do menu.
        scanf(" %d", &op);
            switch (op){
                case 1: //x! + y! + z!
                    receptora=x;
                    for(fatorial_x=1; receptora>1; receptora--){
                        fatorial_x=fatorial_x*receptora;
                    }
                    receptora=y;
                    for(fatorial_y=1; receptora>1; receptora--){
                        fatorial_y=fatorial_y*receptora;
                    }
                    receptora=z;
                    for(fatorial_z=1; receptora>1; receptora--){
                        fatorial_z=fatorial_z*receptora;
                    }
                    resultado=fatorial_x+fatorial_y+fatorial_z;
                    printf("O resultado da expressao e %.f\n", resultado);
                break;
                case 2: //(x + y + z)!
                    receptora2=x+y+z;
                    for(fatorial_resultado2=1; receptora2>1; receptora2--){
                        fatorial_resultado2= fatorial_resultado2*receptora2;
                    }
                    resultado2= fatorial_resultado2;
                    printf("O resultado da expressao e %.f\n", resultado2);
                break;
                case 3: //(x + y)! + (x - z)!
                    receptora3= x+y;
                    receptora4= x-z;
                    for(fatorial_resultado3=1; receptora3>1; receptora3--){
                        fatorial_resultado3= fatorial_resultado3*receptora3;
                    }
                    for(fatorial_resultado4=1; receptora4>1; receptora4--){
                        fatorial_resultado4= fatorial_resultado4*receptora4;
                    }
                    resultado3=fatorial_resultado3+fatorial_resultado4;
                    printf("O resultado da expressao e %.f\n", resultado3);
                break;
                case 4: //x! - (z + y)!
                    receptora5=x;
                    receptora6=z+y;
                    for(fatorial_resultado5=1; receptora5>1; receptora5--){
                        fatorial_resultado5= fatorial_resultado5*receptora5;
                    }
                    for(fatorial_resultado6=1; receptora6>1; receptora6--){
                        fatorial_resultado6= fatorial_resultado6*receptora6;
                    }
                    resultado4=fatorial_resultado5-fatorial_resultado6;
                    printf("O resultado da expressao e %.f\n", resultado4);
                break;
                case 5: //Triângulo equilátero.
                    if(x == y == z){ //Caso os valores dêem um triângulo equilátero.
                        printf("Seus numeros formariam um triangulo equilatero!\n");
                        printf("Triangulo equilatero: Um tipo de triangulo que possui os tres lados congruentes (mesma medida).\nAlem dos lados, os angulos internos dessa figura apresentam as mesmas medidas: 3 angulos de 60º, os quais totalizam 180°.\n");
                        for(i = 1; i <= n; i++) { //Desenho do triângulo equilátero.
                            for(j = 1; j <= n-i; j++)
                            printf(" ");
                            
                            for(j = 1; j <= i; j++)
                            printf("* ");
                            printf("\n");
                        }
                    }else{ //Caso os valores não dêem um triângulo equilátero.
                        printf("Seus numeros não formariam um triangulo equilatero :(\n");
                        printf("Triangulo equilatero: Um tipo de triangulo que possui os tres lados congruentes (mesma medida).\nAlem dos lados, os angulos internos dessa figura apresentam as mesmas medidas: 3 angulos de 60º, os quais totalizam 180°.\n");
                    }
                break;
                case 6: //Triângulo isóceles.
                    if(x == y != z || x != y == z || x == z != y){ //Caso os valores dêem um triângulo isóceles.
                        printf("Seus numeros formariam um triangulo isoceles!\n"); 
                        printf("Triangulo isosceles: Uma tipo de triangulo de três lados, sendo que dois possuem a mesma medida, considerados congruentes.\nJa o lado que possui a medida diferente e denominado de base do triangulo\n");
                        for (i = 1; i <= rows; ++i, k = 0) { //Desenho do triângulo isóceles.
                            for (space = 1; space <= rows - i; ++space){
                                printf("  ");
                            }
                            while (k != 2 * i - 1) {
                                printf("* ");
                                ++k;
                            }
                        printf("\n");
                        }
                    }else{ //Caso os valores não dêem um triângulo isóceles.
                        printf("Seus numeros não formariam um triangulo isoceles :(\n");
                        printf("Triangulo isosceles: Uma tipo de triangulo de três lados, sendo que dois possuem a mesma medida, considerados congruentes.\nJa o lado que possui a medida diferente e denominado de base do triangulo\n");
                    }
                break;
            }menu();
    }while (op != 7); //Saída da repetição do menu.
    printf("Tchauzinho :)"); //FIM.
    
    
    return 0;
}

void regras(){ //Função que imprime as regras.
    printf("1 - Tem que ser um numero POSITIVO (>=0)\n");
    printf("2 - Tem que ser um numero menor que 7 (<7)\n");
    printf("3 - Não pode ser um numero primo (2, 3, 5 e 7)\n");
}

int verifica_x (int x, int i, int verifica){ //Função que verifica os valores de x.
    int flag = 0;
    int t = x;

    for (i = 2; i*i <= t; ++i, t /= 2) { // O(n) -> O(raiz(n))
        if (x % i == 0 || x == 1) {
            flag = 1;
            break;
        }
    }
    if(flag == 1 || x == 1){
        printf("numero correto \n");
    } else {
        printf("Por favor, adicione um valor CORRETO: ");
        scanf("%d", &x);
    }

    return 0;
}

int verifica_y(int y, int i, int verifica){ //Função que verifica os valores de y.

    int flag = 0;
    int t = y;

    for (i = 2; i*i <= t; ++i, t /= 2) { // O(n) -> O(raiz(n))
        if (y % i == 0 || y == 1) {
            flag = 1;
            break;
        }
    }
    if(flag == 1 || y == 1){
        printf("numero correto \n");
    } else {
        printf("Por favor, adicione um valor CORRETO: ");
        scanf("%d", &y);
    }

    return 0;
}

int verifica_z(int z, int i, int verifica){ //Função que verifica os valores de z.

    int flag = 0;
    int t = z;

    for (i = 2; i*i <= t; ++i, t /= 2) { // O(n) -> O(raiz(n))
        if (z % i == 0 || z == 1) {
            flag = 1;
            break;
        }
    }
    if(flag == 1 || z == 1){
        printf("numero correto \n");
    } else {
        printf("Por favor, adicione um valor CORRETO: ");
        scanf("%d", &z);
    }

    return 0;
}

void menu(){ //Função que imprime o menu.
 
    printf("1 -> x! + y! + z! \n");
    printf("2 -> (x + y + z)! \n");
    printf("3 -> (x + y)! + (x - z)! \n");
    printf("4 -> x! - (z + y)! \n");
    printf("5 -> Os 3 numeros formariam um triangulo equilatero? \n");
    printf("6 -> Os 3 numeros formariam um triangulo isoceles? \n");
    printf("7 -> Sair \n");
    printf("Escolha uma opcao!\n");

}


