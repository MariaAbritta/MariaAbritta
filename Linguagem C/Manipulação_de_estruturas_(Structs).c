#include <stdio.h>

int main(){

 struct horario{ //Eu escolho o que está dentro.
     int horas;
     int minutos;
     int segundos;
     double teste;
     char letra;
 };

 struct horario agora; // ESTRUTURA - NOME
    agora.horas=15;
    agora.minutos=17;
    agora.segundos= 30;
 
 struct horario depois;
    depois.horas = agora.horas +10;
    agora.minutos= agora.minutos;;
    depois.teste = 50.55/123;
    depois.letra = 'a';
    
    printf ("%i\n", depois.horas);
    printf ("%i\n", depois.minutos);
    printf ("%f\n", depois.teste);
    printf ("%c\n", depois.letra);

    return 0;
}
