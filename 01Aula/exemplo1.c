#include <stdio.h>

int main(){
    int val1, val2;

    // printf("Digite os dois valores: ");
    // scanf("%d %d", &val1, &val2);
    // printf("Você digitou: %d e %d\n", val1, val2 );

    //%zu é utilizado para tratar de valores em bits ou bytes

    printf("Short short int: %zu\n ", sizeof(short int));
    printf("Short int: %zu\n ", sizeof(int));
    printf("Short long int: %zu\n ", sizeof(long int));
    printf("Short long long int: %zu\n ", sizeof(long long int));

    printf("----------------------------------------------\n");
    
    printf("Short short int in bits: %zu\n ", sizeof(short int)*8);
    printf("Short int in bits: %zu\n ", sizeof(int)*8);
    printf("Short long int in bits: %zu\n ", sizeof(long int)*8);
    printf("Short long long int in bits: %zu\n ", sizeof(long long int)*8);

    return 0;
}