#include <stdio.h>
#include <stdlib.h>

int main(){

int op, i, ii, check = 0, linha, coluna;
int ID [3][3] = {{-1, -1, -1},
                {-1, -1, -1},
                {-1, -1, -1}};
                
do{
    printf("\n");
    printf("---------- MENU ----------\n");//Impressao do Menu Peincipal.
    printf("1 - Cadastrar aluno: \n"); 
    printf("2 - Ver turma: \n");
    printf("3 - Sair: \n");
    printf("Escolha a opcao desejada : \n");
        scanf("%d" , &op); //Leitura de opcao do menu de 1 a 3, onde 3 é a saída do código.
        printf("\n");
        switch(op){
        case 1 :                
           printf("__________Cadastro de alunos__________\n");
           printf("Insira a linha na qual quer cadastrar o ID, sendo os valores de linha validos entre 0 e 2: \n");
                scanf("%d" , &linha); //Leitura da linha.
                    if(linha >=0 && linha<3){ //Condicoes adequadas de linha.
                        printf("Linha validada.\n");
                    }else{
                        printf("Linha invalida.\n");
                        check++; //Linha errada.
                    }
                    while(check!=0){ //Looping de correcao de erros.
                        printf("ERRO! Valor da linha incorreto! Por favor, insira uma linha entre 0 e 2: \n");
                            scanf("%d" , &linha); //Leitura da linha.
                                if(linha >=0 && linha<3){ //Condicoes adequadas de linha.
                                    printf("Linha validada.\n");
                                    check--;
                                }else{
                                    printf("Linha invalida.\n");
                                    check++; //Erro.
                                }
                    }
        printf("\n");
        printf("Insira a coluna na qual quer cadastrar o ID, sendo os valores de coluna validos entre 0 e 2: \n");
            scanf("%d" , &coluna); //Leitura da coluna.
                if(coluna>=0 && coluna<3){ //Condicoes corretas de coluna.
                    printf("Coluna valida.\n");
                }else{
                    printf("Coluna invalida.\n");
                    check++;
                }
                while(check!=0){ //Looping de correcao de erros.
                    printf("ERRO! Valor da coluna incorreto! Por favor, insira uma coluna entre 0 e 2: \n");
                        scanf("%d" , &coluna); //Leitura da linha.
                            if(coluna >=0 && coluna<3){ //Condicoes adequadas de linha.
                                printf("coluna validada \n");
                                check--;
                            }else{
                                printf("coluna invalida,tente novamente. \n");
                                check++; //Sinalizador de erro.
                            }
                }
        printf("\n");
        printf("Insira a ID do(a) aluno(a), sendo validos valores entre 1 e 99: \n");
            scanf("%d" , &ID[linha][coluna]); //Leitura de ID.
                if(ID[linha][coluna]>0 && ID[linha][coluna]<100){ //Condicoes adequadas de ID.
                    printf("ID cadastrado: %d\n" , ID[linha][coluna] );
                }else{
                    printf("ID invalido.\n");
                    check++;
                }
                while(check!=0){ //Looping de correcao de erros.  
                    printf("ERRO! Valores de ID incorretos! Por favor, insira valores entre 1 e 99: \n");
                        scanf("%d" , &ID[linha][coluna]); //Leitura de ID.
                            if(ID[linha][coluna]>0 && ID[linha][coluna]<100){ //Condicoes adequadas de ID.
                                printf("ID cadastrado: %d\n" , ID[linha][coluna] );
                                check--;
                            }else{
                                printf("ID invalido,tente novamente. \n");
                                check++;
                            }
                }
        break;
        case 2 :
           printf("Ver turma \n");
            for(i=0;i<3;i++){
                for(ii=0;ii<3;ii++){
                    printf("%d " , ID[i][ii]);
                }
                    printf("\n");
            }
        break;
        case 3 :
            printf("\n");
            printf("SAIR...\n");
        break;
        default :
            printf("ERRO! Opcao de 1 a 3!\n");  //Caso seja inserido uma opcao menor que 1 ou maior que 3.
        }
}while(op!=3); //A opcao 3 sera de finalizacao do codigo.
printf("Obrigada! Tchauzinho :)");
    return 0;
}


