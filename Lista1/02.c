#include <stdio.h>

int main(){

    double fahreinheit;
    double conversion;
    printf("Digite a temperatura em fareinheit: ");
    scanf("%lf", &fahreinheit);

    conversion = ((double)5/9) * (fahreinheit - 32);
    //cast da divisão de 5/9 para double. Se for feito direto resultado sempre é 0
    // 0 * qualquer coisa retorna 0
    printf("Conversão de fareinheit para celsius: %f\n" , conversion);

    printf("---------------------------------------------\n");

    double fConversion;
    double celsius;
    printf("Digite a temperatura em celsius: ");
    scanf("%lf", &celsius);

    fConversion = celsius * 1.8 + 32;
    printf("Conversão de celsius para fahreinheint: %f\n" , fConversion);

    printf("---------------------------------------------\n");

    fahreinheit = 100;
    conversion = ((double)5/9) * (fahreinheit - 32);

    while (fahreinheit <= 100 && fahreinheit >= -100 && fahreinheit != conversion){
        fahreinheit--;
        conversion = ((double)5/9) * (fahreinheit - 32);
    }

    printf("Both degrees are the same in: %f\n" , conversion);


    return 0;
}