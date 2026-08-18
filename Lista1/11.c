#include <stdio.h>




int main(){

    long int bacterias = 5, lixo;
    long int days[60]; 
    
    
    for(int i = 1; i <= 60; i++){

        days[i-1] = bacterias;
        if(i > 5){
            bacterias -= days[i-6];
            printf("%ld morreram no dia %d.\n", days[i-6], i);
            //printf("%ld", bacterias);
            // nao estava claro se morriam antes ou depois de se dividirem
        }

        printf("Dia %d: %ld bacterias.\n", i, bacterias);
        bacterias *= 2;

    }





    return 0;
}