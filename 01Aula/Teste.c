#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Teste de sanidade do ambiente: stdio, laco, ponteiro, malloc/free. */

int soma_ate(int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += i;
    return total;
}

int main(void)
{
    printf("Ambiente C funcionando.\n");
    printf("Compilador: gcc %d.%d.%d\n", __GNUC__, __GNUC_MINOR__,
           __GNUC_PATCHLEVEL__);
    printf("Tamanho de int: %zu bytes | ponteiro: %zu bytes\n",
           sizeof(int), sizeof(void *));

    printf("Soma de 1 a 10 = %d (esperado 55)\n", soma_ate(10));

    char *msg = malloc(32);
    if (msg == NULL) {
        fprintf(stderr, "Falha ao alocar memoria.\n");
        return 1;
    }
    strcpy(msg, "malloc e free ok");
    printf("%s\n", msg);
    free(msg);

    return 0;
}
