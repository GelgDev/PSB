#include <stdio.h>

int fatorial(int n){
    if (n == 1){
        return 1;
    }
    return n * fatorial(n-1);
}

double soma(int n){
    if (n == 1){
        return 1;
    }
    return ((double)1/fatorial(n)) + soma(n-1);
}

int main(){

    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    

    printf("Fatorial de %d: %d\n", n, fatorial(n));

    printf("Soma de %d: %lf\n", n, soma(n));
    



    return 0;
}