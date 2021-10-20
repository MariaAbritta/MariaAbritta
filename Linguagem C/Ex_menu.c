/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

//PROCEDIMENTO:
//1 - Tipo de retorno void =  nenhum retorno
//2 - Zero ou vários parâmetros
//3 - Não é expressão

int main()
{
    short opcao;
    double resultado;
    do{
        menu();
        scanf("%hd", &opcao);
    } while (opcao != 3);

}

void menu()
{
    printf("1 - Incluir \n");
    printf("2 - Excluir \n");
    printf("3 - Sair \n");
}
