#include <stdio.h>
#include <math.h>

long int fatorial(long int n){
    if (n <= 1){ // correção de == para <= assim 0 retorna 1 também.
        return 1;
    }
    return n * fatorial(n-1);
}

long double power(double base, int exp){ // funcão de potencia na mão. Em c x^2 não é potencia, mas sim um um logical XOR
    if (exp < 0){
        return -1;
    }

    long double result = 1;
    while (exp > 0)
    {
        result *= base;
        exp--;
    }

    return result;
}

long double cosseno(double x, int termos){
    //return 1 - (double)(x^2)/fatorial(2) + (double)(x^4)/fatorial(4) - (double)(x^6)/fatorial(6) + (double)(x^8)/fatorial(8) - (double)(x^10)/fatorial(10);
    long double result = 1;

    for (int i = 1; i < termos; i++){
        if (i%2 != 0){
            result -= (long double)(power(x, i*2))/fatorial(i*2);
        }else{
            result += (long double)(power(x, i*2))/fatorial(i*2);
        }
    } //acho que da pra tirar uns long double aqui mas fiquei com preguiça

    return result;
}

int main(){
    int termos;
    double x;
    printf("Numero que será obtido cosseno(x): ");
    scanf("%lf", &x);
    printf("Numero de termos que serão usados: ");
    scanf("%d", &termos);


    printf("Cos de x: %Lf (meu metodo)\n", cosseno(x, termos));

    printf("Cos de x: %lf (math.h library)\n", cos(x));

    return 0;
}