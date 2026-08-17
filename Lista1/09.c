#include <stdio.h>

double Raiz(int num){

    double n = num, k = 1, raiz, lastK = num;

    for(int i = 0; i < 12; i++){

        k = (k + n/k)/2;

        if (lastK - k < 0.001 )
        {
            return k;
        }
        lastK = k;
    }

    return k;
}


int main(){

    int n;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if(n <= 1 || n % 2 == 0){
        printf("%d NÃO É primo.\n", n);
        return 0;
    }

    // for (int i = 2; i <= Raiz(n); i++){
    //     if( n % i == 0){
    //         printf("%d NÃO É primo, pois é divisivel por %d: %d/%d = %d\n", n, i, n, i, (n/i));
    //         return 0;
    //     }
    // } 
    // PRIMEIRA VERSAO -> aumenta i de 1 em 1 e começa em 2, i até raiz de n (ta calculando a cada iteração)

    //double raiz = Raiz(n); //calcula raiz de n uma vez só
    // for (int i = 3; i <= raiz; i+=2){
    //     if( n % i == 0){
    //         printf("%d NÃO É primo\n", n);
    //         return 0;
    //     }
    // }
    // SEGUNDA VERSAO -> usa a raiz para controlar até onde i cresce e aumenta i de 2 em 2 nos numeros impares

    for (int i = 3; i * i <= n; i+=2){
        if( n % i == 0){
            printf("%d NÃO É primo\n", n);
            return 0;
        }
    }
    // TERCEIRA VERSAO -> se i * i passa de n é pq ja passamos da raíz
    // não cai no problema de margem de erro minima do double Raiz()


    printf("%d É primo.\n", n); //12317467

    return 0;
}