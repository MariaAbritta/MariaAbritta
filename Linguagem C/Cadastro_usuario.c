#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

    void entrada();
    void verifica_email(char email[], int i, int quantidade);
    void verifica_username(char username[], int i, int quantidade, int check);
    void verifica_password (char password[], int i, int quantidade, int check);
    void verifica_frase_sinistra(char frase_sinistra[], int i, int quantidade, int check);
    void final(char email[], char username[], char password[], char frase_sinistra[]);

int main(){
    
char email[100];
char username[100];
char password[100];
char frase_sinistra[100];
int i = 0, quantidade = 0, check = 0, quantidade_password = 0;

    entrada();
    verifica_email(email, i, quantidade);
    verifica_username(username, i, quantidade, check);
    verifica_password (password, i, quantidade, check);
    verifica_frase_sinistra(frase_sinistra, i, quantidade, check);
    
    final( email, username, password, frase_sinistra);
    
    return 0;
}

void entrada(){
    printf("Seja bem vindo(a)!\n");
    printf("---------------------------------------------\n");
    printf("Iremos efeturar o seu login e ele é feito utilizando um email, um username e um password.\n");
}

void verifica_email(char email[], int i, int quantidade){
    printf("Vamos começar com o seu E-mail de login.\n");
    printf("Regras: Só deve possuir letras minúsculas e os únicos caracteres especiais que são aceitos são: @ e . (ponto).\n");
    printf("Por favor, insira um email de login: ");
    scanf(" %[^\n]s", email);

    quantidade = strlen(email);
    
    for(i=0; i<=quantidade; i++){
        for(int i = 0; email[i]; i++){
            email[i] = tolower(email[i]);
            getchar();
            printf("Esse é o e-mail cadastrado: %s \n", email);
            break;
        }
        for(i = 0; i <= quantidade; i++){
            if(strchr(email, '@')!=NULL && strchr(email, '.')!=NULL){ //Verificação se usou o @ e .
                printf("E-mail cadastrado! \n");
                break;
            }else{
                printf("ERRO! E-mail incorreto! \n");
                printf("Por favor, insira um E-mail correto: ");
                scanf(" %[^\n]s", email);
                break;
            }
            break;
        }
        break;
    }
}

void verifica_username(char username[], int i, int quantidade, int check){
    printf("Vamos começar com o seu username de login.\n");
    printf("Regras: So deve possuir letras minusculas, NÃO são aceitos numeros nem caracteres especiais, maximo de 10 caracteres, minimo de 5.\n");
    printf("Por favor, insira um username de login: ");
    scanf(" %[^\n]s", username);
    for(i=0; i<=quantidade; i++){
        for(int i = 0; username[i]; i++){
            username[i] = tolower(username[i]);
            getchar();
            printf("Esse é o username cadastrado: %s \n", username);
            break;
        }
        if(strlen(username)>=5 && strlen(username)<=10){
            printf("Username cadastrado!\n");
            check=0;
            break;
        }
        if(strlen(username)<5 || strlen(username)>10){
            check++;
        }
        while(check!=0){
            if(strlen(username)<5 || strlen(username)>10){
                printf("ERRO! Username invalido!\n");
                printf("Por favor, insira um username correto: ");
                scanf(" %[^\n]s", username);
                break;
            }
        }
    }
}

void verifica_password (char password[], int i, int quantidade, int check){
    printf("Vamos começar com o seu password de login.\n");
    printf("Regras: Caracteres livres. Tamanho mínimo: 8. Tamanho máximo: 40.\n");
    printf("Por favor, insira um password de login: ");
    scanf(" %[^\n]s", password);
    for(i=0; i<=quantidade; i++){
        if(strlen(password)>=8 && strlen(password)<=40){
            printf("Password cadastrada!\n");
            check=0;
            break;
        }
        if(strlen(password)<8 || strlen(password)>40){
            check++;
        }
        while(strlen(password)<8 || strlen(password)>40){
            printf("ERRO! password invalido!\n");
            printf("Por favor, insira um password correto: ");
            scanf(" %[^\n]s", password);
            break;
        }
    }
}
 
void verifica_frase_sinistra(char frase_sinistra[], int i, int quantidade, int check){
    printf("ULTIMA ETAPA!\n");
    printf("Frase SINISTRA:\n");
    printf("É aquela que possui pelo menos 70 caracteres, com estes formando, pelo menos, 5 palavras. Além disso, a frase precisa começar\ncom letra maiúscula e terminar com ponto final.");
    printf("Por favor, insira a sua frase sinistra para terminar o seu login: ");
    scanf(" %[^\n]s", frase_sinistra);
    for(i=0; i<=quantidade; i++){
        if(strlen(frase_sinistra)>=70){
            printf("Frase sinistra cadastrada!\n");
            printf("Cadastro finalizado!");
            check=0;
            break;
        }
        if(strlen(frase_sinistra)<70){
            check++;
        }
        while(strlen(frase_sinistra)<70){
            printf("ERRO! Frase sinistra invalida!\n");
            printf("Por favor, insira um frase sinistra correta: ");
            scanf(" %[^\n]s", frase_sinistra);
            break;
        }
        if(isupper(frase_sinistra[0]!=0)){
            check=0;
        }
        if(isupper(frase_sinistra[0]==0)){
            check++;
        }
        while(isupper(frase_sinistra[0]==0)){
            printf("ERRO! Frase sinistra invalida!\n");
            printf("Por favor, insira um frase sinistra correta: ");
            scanf(" %[^\n]s", frase_sinistra);
            break;
        }
    }
}

void final(char email[], char username[], char password[], char frase_sinistra[]){
    printf("---------------------------------------------\n");
    printf("              Seu cadastrado:                \n");
    printf("- Esse é o e-mail cadastrado: %s \n", email);
    printf("- Esse é o username cadastrado: %s \n", username);
    printf("- Esse é o password cadastrado: %s \n", password);
    printf("- Esse é a sua frase sinistra cadastrada: %s \n", frase_sinistra);
    printf("---------------------------------------------\n");
    printf("LOGIN CONCLUIDO\nObrigada pelos seus dados!\n");
    printf("Tchauzinho :)\n");
}
