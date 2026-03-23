#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * v;
    int primeiro;
    int ultimo;
    int tamanho;
    int capacidade;
} t_fila;

t_fila * constroi_fila (int);       // Capacidade é o parametro
int estavazia(t_fila *);
int esta_cheia(t_fila *);

int enfileira(int, t_fila *);       // O retorno é sucesso (1) ou fracasso(0)
int desenfileira(int *, t_fila *);  // O "int *" é um ponteiro que vai apontar para o item desenfileirado

void mostra_fila(t_fila *);         // Mostra os valores contidos na Fila Circular
void mostra_vetor(t_fila *);        // Mostra todas as posições da Fila Circular, inclusive aquelas "sem valores (vazias)"