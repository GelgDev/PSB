#include <stdio.h>

int main(){

    unsigned int hours, minutes, seconds;

    printf("Digite um horario no formato HH:MM:SS : ");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    if ( hours > 24 || minutes >= 60 || seconds >= 60){
        printf("Formato de horário inválido.\n");
        return 0;
    }

    int result = (hours * 3600) + (minutes * 60) + seconds;

    printf("Já se passaram %d segundos desde o inicio do dia.\n", result);

    result = 86400 - result;

    printf("Faltam %d segundos para o fim do dia.\n", result);



    return 0;
}