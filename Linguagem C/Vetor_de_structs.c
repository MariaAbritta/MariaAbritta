#include <stdio.h>

int main(){

 struct horario{ //Eu escolho o que está dentro.
     int horas;
     int minutos;
     int segundos;
 };
 
 struct horario teste[5]=
 {{10, 20, 30}, {20, 30, 40}, {30, 40, 50},
 {40, 50, 60}, {50, 60, 70}};
    
    int i;
    for(i=0; i<5; i++){
        printf("%i: %i: %i\n", teste[i].horas, teste[i].minutos, teste[i].segundos);
        
    }

 
 return 0;
 
}