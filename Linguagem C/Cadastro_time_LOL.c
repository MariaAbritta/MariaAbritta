//Aluna: Maria Eduarda Dos Santos Abritta Ferreira.
//Matrícula: 202016945.

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

void menu();
void jogador_posicao();
void id_jogador ();
void editar_jogador();
void editar_jogador2();
void torres_destruidas_equipe();
void torres_destruidas_adversaria();
void imprime_caso_10();
//Sinalizadores de funcao.

typedef struct {
    int id, idade, kills, deaths, assistencias, total_pontos, id_destaque;
    char nome_jogador[100], posicao[4];
}Jogador;

typedef struct {
    char nome_time[100], nome_tecnico[100];
    Jogador jogador[5];
    int kills_time, deaths_time, assistencias_time, torres_destruidas;
    int kills_adversario, torres_adversario;
}Time;

typedef struct{
    Time equipe;
    Time time_desafiante[2];
    char resultado_partida[10];
}partidas;

partidas partida[100];
Time equipe;

int opcao_menu = 0, i = 0, j = 0, edita, posicao_time, posicao_jogador, global = 1;
int jogador_maior = 0, jogador_menor = 0, total_assistencia[1000], total_kills[1000];
int total_deaths[1000], total_pontos[1000], melhor = 0, maior_kill, menor_kill;

char posicoes[19], escolha, resposta[4], resposta2[4], nome_melhor[100];


int main(){ //INÍCIO DO CÓDIGO.
    
strcpy(resposta, "sim");
strcpy(resposta2, "nao");
strcpy(posicoes, "TOP MID SUP ADC JG");
//Padrões de verificação.
    
do{
    menu();
    scanf("%d",&opcao_menu); //Opções do menu.
    
    switch (opcao_menu){
        case 1:
            printf("----------Cadastrar time---------- \n");
            printf("Qual o nome da equipe?\n");
            getchar();
            scanf("%[^\n]s" ,equipe.nome_time); //Nome da equipe.

            printf("Qual o nome do tecnico da equipe? \n");
            getchar();
            scanf("%[^\n]s" ,equipe.nome_tecnico); //Nome do time.

            for(j=1;j<6;j++){ //Laço de repetição para cadastro de jogadores (j).
                equipe.jogador[j].id=j; //Vou acatar a posição de cadastro do próprio looping como o propio id do jogador.
                printf("Qual o nome do jogador %d? \n",j);
                getchar();
                scanf("%[^\n]s" ,equipe.jogador[j].nome_jogador); //Nome do jogador.
                
                do{
                    printf("Qual a idade do jogador %d? \n" ,j);
                    printf("REGRA: A idade deve ser um valor entre 1 a 150.\n");
                    scanf("%d" ,&equipe.jogador[j].idade); //Idade.
                    if(equipe.jogador[j].idade < 0 || equipe.jogador[j].idade > 150){ //Verficiar se a idade está entre os valores aceitos.
                        printf("ERRO! Idade invalida, tente novamente: \n");
                    }
                }while(equipe.jogador[j].idade < 0 || equipe.jogador[j].idade > 150);
                
                do{
                    jogador_posicao();
                    scanf("%[^\n]s" , equipe.jogador[j].posicao); //Posição
                    if(strstr(posicoes,equipe.jogador[j].posicao)==NULL){
                        printf("ERRO! Dados invalidos, tente novamente. \n");
                    }
                }while(strstr(posicoes,equipe.jogador[j].posicao)==NULL);
            }
            printf("--------------------------------------------\n");
        break;
        case 2:
            printf("----------Listar time----------\n"); 
            printf("Time: %s \n" ,equipe.nome_time ); //Nome do time
            printf("Tecnico: %s \n" , equipe.nome_tecnico); //Nome do técnico.
            for(j=1;j<6;j++){ // Looping para listar os 5 jogadores.
                printf("ID: %d\nNome: %s\nPoiscao: %s \n" , equipe.jogador[j].id,equipe.jogador[j].nome_jogador,equipe.jogador[j].posicao);
                printf("\n");
            }
            printf("--------------------------------------------\n");
        break;
        case 3:
            printf("----------Editar time----------\n ");
            do{
                do{
                    id_jogador ();
                     scanf("%d" ,&posicao_jogador); //ID do jogador.
                        if(posicao_jogador < 1 || posicao_jogador > 5){ // Verificar se está entre 1 a 5.
                            printf("ERRO! ID invalido, tente novamente.\n");
                        }
                }while(posicao_jogador < 1 || posicao_jogador > 5);
                printf("ID: %d\nNome: %s\nPoiscao: %s\nTotal pontos: %d\n" ,equipe.jogador[posicao_jogador].id,equipe.jogador[posicao_jogador].nome_jogador,equipe.jogador[posicao_jogador].posicao,equipe.jogador[posicao_jogador].total_pontos);
                //Printar os dados do jogador pesquisado.
                    editar_jogador();
                    getchar();
                        scanf("%c" , &escolha); //Escolha do Sim ou Não.
                            if(escolha=='N'){
                                break;
                            }
            }while(escolha=='N');
            do{
                editar_jogador2();
                scanf("%d" , &edita); //Editar dados.
                switch(edita){
                    case(1):{
                        printf("Digite o NOVO nome para o jogador escolhido: \n");
                        getchar();
                        scanf("%[^\n]s" , equipe.jogador[posicao_jogador].nome_jogador); //Novo nome do jogador.
                    break;
                    }
                    case(2):{
                        do{
                            jogador_posicao();
                            getchar();
                            scanf("%[^\n]s" , equipe.jogador[posicao_jogador].posicao); //Nova posição do jogador.
                            if(strstr(posicoes,equipe.jogador[posicao_jogador].posicao)==NULL){ //Verificação da posição.
                                printf("ERRO! Posicao invalida, tente novamente. \n");
                            }
                        }while(strstr(posicoes,equipe.jogador[posicao_jogador].posicao)==NULL);
                    break;
                    }
                    case(3):{
                        printf("Voltando ao menu principal... \n"); //Voltando ao mneu principal.
                    break;
                    }
                    default:{
                        printf("ERRO! Opcao invalida, tente novamente digitando um valor entre 1 a 3. \n"); //Caso escolhar algum número fora de 1 a 3.
                    break;
                    }
                }
            }while(edita != 3);
            printf("--------------------------------------------\n");
        break;
        case 4 :
            do{ 
                printf("----------Cadastrar partida--------- \n ");
                for(i=global;i!=-1;){ //Laço de repetição para as structs.
                    for(j=1;j<6;j++){ //Laço de repeticao para os jogadores (j).
                        printf("Digite os dados dos jogadores para cadastrarmos a partida : \n");
                        printf("Qual o total de assistencias do jogador %d? \n" ,j);
                        //getchar();
                        scanf("%d" , &partida[i].equipe.jogador[j].assistencias); //Assistências de cada jogador.
                        getchar();
                        total_assistencia[j]=partida[i].equipe.jogador[j].assistencias; //Asistências * 1.
                        
                        printf("Qual o total de kills do jogador %d? \n" ,j); //Kills de cada jogador.
                        //getchar();
                        scanf("%d" , &partida[i].equipe.jogador[j].kills); 
                        
                        while(partida[i].equipe.jogador[j].kills > maior_kill){ //Maior jogador.
                            //maior_kill=total_pontos[j];
                            maior_kill = ((partida[i].equipe.jogador[j].kills*3) + (partida[i].equipe.jogador[j].assistencias)); //Conta para o maior jogador.
                            jogador_maior = equipe.jogador[j].id; //Leitura do ID do maior jogador.
                            strcpy(nome_melhor, equipe.jogador[j].nome_jogador); //Comparação dos nomes.
                            break;
                        }
                        
                        printf("Qual o total de Deaths do jogador %d?  \n" , j); //Deaths dos jogadores
                        scanf("%d" ,&partida[i].equipe.jogador[j].deaths);
                        total_deaths[j]=partida[i].equipe.jogador[j].deaths; //Total deaths = deaths feitas pelo jogador.
                        total_kills[j]=partida[i].equipe.jogador[j].kills; //Total kills = kills feitas pelos jogadores.
                        total_pontos[j]=(total_kills[j]*3)+(total_assistencia[j]); //Soma das kills * 3 e das assistências * 1.
                    }
                    partida[i].equipe.kills_time=total_kills[1]+total_kills[2]+total_kills[3]+total_kills[4]+total_kills[5]; // Soma de todas as kill feitas por todos os jogadores do time.
                    partida[i].equipe.kills_adversario=total_deaths[1]+total_deaths[2]+total_deaths[3]+total_deaths[4]+total_deaths[5]; //Soma de todas as detahs dos jogadores.
                    partida[i].equipe.deaths_time=total_deaths[1]+total_deaths[2]+total_deaths[3]+total_deaths[4]+total_deaths[5]; //Soma de todas as deaths dos jogadores.
                    partida[i].equipe.assistencias_time=total_assistencia[1]+total_assistencia[2]+total_assistencia[3]+total_assistencia[4]+total_assistencia[5]; //Soma de todas as assistências feitas pelos jogadores.
                    
                    do{
                        torres_destruidas_equipe();
                        getchar();
                        scanf("%d" , &partida[i].equipe.torres_destruidas); //Torres destruidas pela equipe.
                        if(equipe.torres_destruidas < 0|| equipe.torres_destruidas > 11){ //Verificação se o número inserido está entre 0 a 11.
                            printf("ERRO! Dados invalidos, tente novamente.\n");
                        }
                    }while(equipe.torres_destruidas < 0|| equipe.torres_destruidas > 11);
                    
                    do{
                        torres_destruidas_adversaria();
                        getchar();
                        scanf("%d" , &partida[i].equipe.torres_adversario); //Torres destruidas pela equipe.
                        if(equipe.torres_adversario < 0|| equipe.torres_adversario > 11){ //Verificação se o número inserido está entre 0 a 11.
                            printf("ERRO! Dados invalidos, tente novamente.\n");
                        }
                    }while(equipe.torres_adversario < 0|| equipe.torres_adversario > 11);
                    
                    printf("Resultado da partida? (Vitoria / Derrota) \n");
                    getchar();
                    scanf(" %[^\n]s \n" , partida[i].resultado_partida); //Leitura de resultado da partida = Vitoria / Derrota.
                    global++;
                    
                    printf("Deseja cadastrar outra partida?\n");
                    printf("Insira S para sim ou N para nao. (S/N) \n");
                    getchar();
                    scanf("%c" ,&escolha);
                    getchar();
                    if(escolha=='S'){
                        i++;
                    }else{
                        i=-1;
                    }
                    
                }
                }while(escolha == 'S');
                printf("--------------------------------------------\n");
        break;
        case 5 :
            printf("----------Listar partidas----------\n ");
            printf("Dados sobre a equipe:\n");
            getchar();
            for(i=1;i!=global;i++){
                printf("Resultado da partida: %s\nTotal de kills: %d\n" ,partida[i].resultado_partida, partida[i].equipe.kills_time); //Resultado da equipe.
                printf("Total de deaths: %d\nTotal de torres destruids: %d\n", partida[i].equipe.deaths_time, partida[i].equipe.torres_destruidas); //Resultados da equipe.
                printf("--------------------------------------------\n");
                printf("O jogador de maior pontuacao: \n");
                printf("ID: %d\nNome: %s\nPontuacao: %d\n" ,jogador_maior, nome_melhor, maior_kill); //Resultados do melhor jogador.
                printf("--------------------------------------------\n");
                printf("Dados da equipe adversaria: \n");
                printf("Torres destruidas: %d\nTotal de kills: %d\nTotal de deaths: %d \n" ,partida[i].equipe.torres_adversario, partida[i].equipe.deaths_time, partida[i].equipe.kills_time); 
                //Resultado equipe adversária.
                printf("--------------------------------------------\n");
            }
        break;
        case 6 :
            printf("----------Pesquisar jogador---------\n ");
            printf("Qual o ID do jogador desejado? \n");
            getchar();
            scanf("%d" , &posicao_jogador); //ID do jogador.
                if(posicao_jogador < 1 || posicao_jogador > 5){ //Verificação se o ID está entre 1 a 5.
                    printf("ERRO! Jogador inexistente.\n");
                }else{
                    for(i=1;i!=global;i++){
                            posicao_jogador==j; //A posição do jogador condiz com seu ID.
                            total_deaths[j]=partida[i].equipe.jogador[j].deaths;
                            total_kills[j]=partida[i].equipe.jogador[j].kills;
                            total_pontos[j]=(total_kills[j]*3)+(total_assistencia[j]);
                            printf("O jogador pequisado e: \n");
                            printf("ID: %d\nNome: %s\nPoiscao: %s\nTotal de pontos: %d\n" , equipe.jogador[posicao_jogador].id,equipe.jogador[posicao_jogador].nome_jogador,equipe.jogador[posicao_jogador].posicao, total_pontos[posicao_jogador]);
                            //Resultado do jogador pesquisado.
                    }
                }
            printf("--------------------------------------------\n");
        break;
        case 7 :
            printf("----------Mostrar o total de kills e assistencias---------\n ");
            getchar();
            for(i=1;i!=global;i++){ //Laço de repetição para as structs.
                printf("As kills e assistencias registradas para a equipe sao: \n");
                printf("Total kills: %d\nTotal assistencias: %d\n", partida[i].equipe.kills_time,partida[i].equipe.assistencias_time); //Kilss e assistências da equipe.
            }
            printf("--------------------------------------------\n");
        break;
        case 8 :
            printf("Mostrar jogador com menor pontuacao \n ");
            printf("Caso que eu escolhi nao fazer, entre o 7 ao 9.\n"); //Caso que eu escolhi não fazer.
            break;
        break;
        case 9 :
            printf("---------Mostrar jogador com maior pontuacao---------\n ");
            for(i=1;i!=global;i++){ //Laço de repetição para as structs.
                printf("O jogador com maior pontuacao e: \n");
                printf("ID: %d\nNome: %s\nTotal de pontos: %d\n" ,jogador_maior, nome_melhor, maior_kill); //Dados do melhor jogador.
            }
            break;
            printf("--------------------------------------------\n");
        break;
        case 10 :
            imprime_caso_10();
        break;
        default:
            printf("ERRO! Opcao invalida, tente novamente com um valor entre 1 e 10!\n "); //Opcao invalida
    }
}while(opcao_menu!=10); //FIM DO CÓDIGO.
    return 0;
}

void menu() //MENU
{
    printf("__________MENU__________\n");
    printf("1 - Cadastrar time.\n");
    printf("2 - Listar time.\n");
    printf("3 - Editar time.\n");
    printf("4 - Cadastrar partida.\n");
    printf("5 - Listar partidas.\n");
    printf("6 - Pesquisar jogador.\n");
    printf("7 - Mostrar numero total de kills e assistencias.\n");
    printf("8 - Mostrar jogador com menor pontuacao.\n");
    printf("9 - Mostrar jogador com maior pontuacao.\n");
    printf("10 - Sair.\n");
    printf("Escolha uma opcao.\n");
    printf("________________________\n");

}

void jogador_posicao(){ //As psoições dos jogadores.
    printf("Insira uma posicao entre:\n . TOP\n . MID\n . JG\n . ADC\n . SUP\n");
    printf("REGRA: Insira as posicoes da forma em que foram escritas anteriormente (CapsLk).\n");
    getchar();
}

void id_jogador(){ //IDs dos jogadores.
    printf("Insira o ID do jogador que deseja editar os dados: \n");
    printf("REGRA: O ID e um valor entre 1 e 5. \n");
    getchar();
}

void editar_jogador(){ //Edição dos jogadores.
    printf("Este e o jogador desejado?\n");
    printf("Insira S para sim ou N para nao: (S/N)\n");
}

void editar_jogador2(){ //Menu de edição dos jogadores.
    printf("..........Menu de edicao.......... \n");
    printf("1 - Nome do jogador:\n");
    printf("2 - Posicao do jogador:\n");
    printf("3 - Sair:\n");
    printf("Escolha qual informacao deseja editar : \n");
    printf(".................................. \n");
}

void torres_destruidas_equipe(){ //Quantas torres a equipe conseguiu destruir.
    printf("Quantas torres a equipe destruiu na partida? \n");
    printf("REGRA: O maior numero possivel de torres destruidas e 11. \n");
}

void torres_destruidas_adversaria(){ //Quantas torres a equipe adversaria conseguiu destruir.
    printf("Quantas torres a equipe adversaria destruiu na partida?\n");
    printf("REGRA: O maior numero possivel de torres destruidas e 11. \n");
}

void imprime_caso_10(){ //Sair do código.
    printf("Saindo do programa...\n ");
    printf("Tchauzinho :)\n "); //Saida do codigo
}
