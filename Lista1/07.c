#include <stdio.h>

int main(){


    int notas[] = {100, 50, 10, 5, 1};
    //int quantidade[] = {0, 0, 0, 0, 0};
    int valor;
    size_t length = sizeof(notas) / sizeof(notas[0]);

    printf("Digite o valor desejado: ");
    scanf("%d", &valor);


    // for (int i =0; i < length; i++){
    //     quantidade[i] = valor / notas[i];
    //     valor = valor % notas[i];
    //     printf("Notas de %d: %d\n", notas[i], quantidade[i]);
    // }

    for (int i =0; i < length; i++){
        printf("Notas de %d: %d\n", notas[i], (valor/notas[i]));
        valor = valor % notas[i];
    }



    return 0;
}