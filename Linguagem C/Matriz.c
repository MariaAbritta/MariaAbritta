#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void regras();
void menu();
int caso_1 (int quantidade, float media, int menor, int maior);
int caso_2 (int i, int quantidade, int idade[]);
int case_6 (int pesquisar, int i, int quantidade, int idade[], int erro);


int main(){
    
int idade[1000], i = -1, op, maior = 0, menor = 1000, count, quantidade = 0, soma, NM = 0, remove_idade;
char disciplina;
float media;
int idade_edit, nova_idade;
char option;
int menorM[100], maiorM[100], op2, conta_total = -1, erro = 0, pesquisar;
    
   
    printf("Seja bem vindo!\n"); //Início.
    printf("----------------\n");
    printf("Qual a disciplina?\n"); //Pergunta da disciplina em que esses alunos se encontram.
    scanf("%s", &disciplina);
    printf("Inisra a idade dos alunos da disciplina %s \n", &disciplina); //Retorno do nome da disciplina.
    regras();
    
    do{
        for(i=0 ; i<1000; i++){
            printf("Insira a idade do aluno(a) na posição %d: ", i); //Inserir a idade na posição 0 - posição inicial do meu vetor idade.
            scanf("%d", &idade[i]); //Recebimento da idade.
            if(idade[i]>150 || idade[i]<1){ //Averiguar se a idade entra dentro das regras.
                printf("Valor incorreto para idade, tente novamente com um NUMERO CORRETO: \n"); //Mensagem caso a idade esteja errada.
                scanf(" %d", &idade[i]); //Leitura da idade novamente.
            }
            if(idade[i] == 150){ //Para não contar o 150 no meu quantidade.
                break;
            }
            quantidade++;
            if(idade[i]>maior){ //Leitura para maior idade.
                maior=idade[i];
            }
            if(idade[i]<menor && idade[i]!=0){ //Leitura para menor idade.
                menor=idade[i];
            }
            soma = soma + idade[i]; //Soma das idades para a média.
        }
        conta_total++; //Total.
    }while(idade[i]!=150); //Saída do looping.
    
    media = soma/quantidade; //Média.
   
    menu();
    do{ //Repetição tipo looping do menu.
        scanf(" %d", &op); //Leitura da opção.
        switch (op){
            case 1: //informações gerais.
                caso_1 (quantidade, media, menor, maior);
            break;
            case 2: //Listar idades.
                caso_2 (i, quantidade, idade);
            break;
            case 3: //Listar Maiores/Menores que a média
                printf("........................................................\n");
                printf("Listar maior/menor que a media:\n");
                for(i = 0; i < quantidade; i++){ //passear pelo vetor de idades
                    for(int maior_media = 0; maior_media < i; maior_media++){ //Comparação da idade com a media.
                        if(idade[i] < media){
                            break;                        
                        } else{
                            maiorM[maior_media] = idade[i];
                        }
                        printf("Idades maiores que a media: %d \n", maiorM[maior_media]); //Mensaegm com a maior que a media.
                        break;
                    }
                }

                for(i = 0; i < quantidade; i++){ //passear pelo vetor de idades
                    for(int menor_media = 0; menor_media < i; menor_media++){ //Comparação da idade com a media.
                        if(idade[i] > media){
                            break;                        
                        } else{
                            menorM[menor_media] = idade[i];
                        }
                        printf("Idades menores que a media: %d \n", menorM[menor_media]);//Mensaegm com a menor que a media.
                        break;
                    }
                }
                printf("........................................................\n");
            break;
            case 4: //Editar idade
                printf("........................................................\n");
                printf("Editar idade:\n");
                printf("Qual posicao deseja editar? ");
                scanf("%d", &idade_edit); //Inserir a idade que deseja editar
                printf("Posicao %d do vetor: %d \n", idade_edit, idade[idade_edit]); //Mostrar a posição em que está a idade.
                printf("Deseja editar essa posicao? \n");
                scanf("%c", &option);
                if(option = "S"){ /*|| option = "s"*/
                    printf("Digite a nova idade: ");
                    scanf("%d", &nova_idade);
                    while (nova_idade<1 || nova_idade>149){
                        printf("Idade invalida\n");
                        printf("Digite a nova idade: ");
                        scanf("%d", &nova_idade);
                    }
                    idade[idade_edit] = nova_idade;
                }   else if(option = "N"){ /* || option = "n"*/
                        break;
                    }else{
                        printf("Opcao invalida!! Tente novamente!! \n");
                        break;
                    }
                printf("........................................................\n");
            break;
            case 5: //Excluir idade:
                printf("........................................................\n");
                printf("Excluir idade: \n");
                printf("Informe a idade que deseja excluir: ");
                scanf("%d", &remove_idade); //Leitura  da idade que quer remover
                idade[i]=remove_idade;
                printf("Deseja excluir (1- sim // 2- nao): ");
                scanf("%d", &op2);
                switch(op2){
                    case 1:
                        for(i=0;i<=quantidade-1;i++){
                            if(idade[i]==remove_idade){
                                for(int x=i; x<=quantidade; x++){
                                    idade[x]=idade[x+1];
                                }
                                quantidade--;
                            }
                        }
                    break;
                    case 2:
                        printf("Ok\n");
                    break;
                }
                printf("........................................................\n");
            break;
            case 6:
                case_6 (pesquisar, i, quantidade, idade, erro);
            break;
        }menu(); //repetição do menu.
    }while (op != 7); //Saída da repetição do menu.
    printf("Tchauzinho :)"); //FIM.

    return 0;
}

void regras(){
    printf("Temos aglumas regras: \n");
    printf("1 - Apenas numeros inteiros.\n");
    printf("2 - Apenas numeros entre 1 e 149.\n");
    printf("3 - A entrada de números termina quando digitar o número 150.\n");
}

void menu(){ //Função que imprime o menu.
    printf("-----------------------------------------------------\n");
    printf("1 -> Informacoes gerais. \n");
    printf("2 -> Listar idades. \n");
    printf("3 -> Listar idades maiores/menores que a media. \n");
    printf("4 -> Editar idade. \n");
    printf("5 -> Excluir idade. \n");
    printf("6 -> Pesquisar posição. \n");
    printf("7 -> Sair \n");
    printf("Escolha uma opcao!\n");
    printf("-----------------------------------------------------\n");

}

int caso_1 (int quantidade, float media, int menor, int maior){ //Função para as informações gerais.
    printf("........................................................\n");
    printf("Infomracoes gerais:\n");
    printf("A quantidade de idades inseridas foi: %d\n", quantidade);
    printf("A media das idades inseridas e: %f\n", media); 
    printf("A MENOR idade inserida foi: %d\n", menor); 
    printf("A MAIOR idade inserida foi: %d\n", maior);
    printf("........................................................\n");
    
    return 0;
}

int caso_2 (int i, int quantidade, int idade[]){
    printf("........................................................\n");
    printf("Lista das idades inseridas: \n");
        for (int i = 0; i<=quantidade-1; i++){ //For para mostrar todas as idades inseridas.
            printf(" %d\n", idade[i]);
        }
    printf("........................................................\n");
    return 0;
}

int case_6 (int pesquisar, int i, int quantidade, int idade[], int erro){
    printf("........................................................\n");
    printf("Pesquisar posicao: \n");
    printf("Informe a idade que para saber que posicao ela se encontra: "); //Informar a idade para encontrar a posição
    scanf("%d", &pesquisar); //Leitura da idade
        for(i=0; i<=quantidade-1; i++){
            if(pesquisar==idade[i]){
                printf("Na posicao %d encontra-se a idade %d\n", i, idade[i]);
                erro = 0;
                break;
            }else{
                erro++;
            }
            if(erro!=0){
                erro = 0;
                printf("NAO TEM\n");
            }
        }
    printf("........................................................\n");
}







