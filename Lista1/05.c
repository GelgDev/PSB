#include <stdio.h>
#include <math.h>

int main(){

    double n, k = 1, raiz, lastK;
    printf("Digite o valor de n: ");
    scanf("%lf", &n);
    lastK = n;

    for(int i = 0; i < 12; i++){

        k = (k + n/k)/2;
        printf("%d. Valor de k: %f\n", i+1, k);

        if (lastK - k < 0.001 )
        {
            printf("O valor já está muito próximo.\n");
            break;
        }
        lastK = k;
    }
    
    raiz = sqrt(n);

    printf("Raiz de %lf: %lf\n", n, raiz);


    return 0;
}