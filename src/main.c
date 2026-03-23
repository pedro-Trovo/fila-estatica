#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

int main() {
    printf("\n\n=== FILA ESTÁTICA CIRCULAR ===\n\n");


    printf("1. Criando fila com capacidade 5:\n");
    t_fila *fila = constroi_fila(5);

    if (estavazia(fila)) {
        printf("Fila vazia!\n");
    }


    printf("\n2. Enfileirando elementos: 10, 20, 30, 40, 50\n");
    enfileira(10, fila);
    enfileira(20, fila);
    enfileira(30, fila);
    enfileira(40, fila);
    enfileira(50, fila);

    printf("   Fila: ");
    mostra_fila(fila);
    printf("   Vetor: ");
    mostra_vetor(fila);

    if (esta_cheia(fila)) {
        printf("Fila cheia!\n");
    }

    printf("\n3. Tentando enfileirar 60 (fila cheia):\n");
    if (enfileira(60, fila)) {
        printf("   Inserido!\n");
    } else {
        printf("Falha: fila cheia!\n");
    }

    printf("\n4. Desenfileirando elementos:\n");
    int valor;
    desenfileira(&valor, fila);
    printf("   Removido: %d\n", valor);
    desenfileira(&valor, fila);
    printf("   Removido: %d\n", valor);

    printf("   Fila: ");
    mostra_fila(fila);
    printf("   Vetor: ");
    mostra_vetor(fila);

    printf("\n5. Enfileirando 60 e 70:\n");
    enfileira(60, fila);
    enfileira(70, fila);

    printf("   Fila: ");
    mostra_fila(fila);
    printf("   Vetor: ");
    mostra_vetor(fila);

    printf("\n6. Esvaziando a fila:\n");
    while (desenfileira(&valor, fila)) {
        printf("   Removido: %d\n", valor);
    }

    if (estavazia(fila)) {
        printf("Fila vazia!\n");
    }

    printf("\n=== FIM ===\n\n");
    return 0;
}