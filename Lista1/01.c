#include <stdio.h>

int main(){
    int val1, val2;

    // printf("Digite os dois valores: ");
    // scanf("%d %d", &val1, &val2);
    // printf("Você digitou: %d e %d\n", val1, val2 );

    //%zu é utilizado para tratar de valores em bits ou bytes

    printf("short int: %zu\n", sizeof(short int));
    printf("int: %zu\n", sizeof(int));
    printf("long int: %zu\n", sizeof(long int));
    printf("long long int: %zu\n", sizeof(long long int));

    printf("----------------------------------------------\n");
    
    printf("short int in bits: %zu\n", sizeof(short int)*8);
    printf("int in bits: %zu\n", sizeof(int)*8);
    printf("long int in bits: %zu\n", sizeof(long int)*8);
    printf("long long int in bits: %zu\n", sizeof(long long int)*8);

    printf("----------------------------------------------\n");
    printf("Usando *__CHAR_BIT__ no lugar de *8\n");
    
    printf("short int in bits: %zu\n", sizeof(short int)*__CHAR_BIT__);
    printf("int in bits: %zu\n", sizeof(int)*__CHAR_BIT__);
    printf("long int in bits: %zu\n", sizeof(long int)*__CHAR_BIT__);
    printf("long long int in bits: %zu\n", sizeof(long long int)*__CHAR_BIT__);

    return 0;
}