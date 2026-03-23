#include "fila.h"

t_fila * constroi_fila(int capacidade){
    t_fila * f = (t_fila *) malloc (sizeof(t_fila));

    if(f != NULL){
        f->v = (int *) malloc (capacidade * sizeof(int));

        if(f->v == NULL){
            return NULL;
        }

        f->capacidade = capacidade;
        f->tamanho = 0;
        f->primeiro = 0;
        f->ultimo = 0;
    }
    return f;
}


int estavazia(t_fila *f){
    return f->tamanho == 0;
}

int esta_cheia(t_fila *f){
    return f->tamanho == f->capacidade;
}

int proxima_posicao(int posicao, t_fila *f){
    return (posicao +1) % f->capacidade;
}


int enfileira(int i, t_fila *f){
    if(esta_cheia(f)){
        return 0;
    }
    else{
        f->v[f->ultimo] = i;
        f->ultimo = proxima_posicao(f->ultimo, f);
        f->tamanho++;
        return 1;
    }
}

int desenfileira(int *pont_item_desenf, t_fila *f){
    if(estavazia(f)){
        return 0;
    }
    else{
        *pont_item_desenf = f->v[f->primeiro];
        f->primeiro = proxima_posicao(f->primeiro, f);
        f->tamanho--;
        return 1;
    }
}


void mostra_fila(t_fila *f){
    if(estavazia(f)){
        printf("esta vazia\n");
    }
    else{
        int i = f->primeiro;
        do{
            printf("%d ", f->v[i]);
            i = proxima_posicao(i, f);
        } while(i!=f->ultimo);
        printf("\n"); 
    }
}

void mostra_vetor(t_fila *f){
    int i;

    // Se a fila circular esta cheia
    if(esta_cheia(f)){
        for(i=0; i<f->capacidade; i++){
            printf("%d ", f->v[i]);
        }
    }

    // Se o "primeiro" for menor que o "ultimo" (não foi dado uma volta)
    // Esse condição tambem engloba o situação em que a fila está vazia (primeiro == ultimo)
    else if(f->primeiro <= f->ultimo){
        for(i=0; i<f->primeiro; i++){
            printf("_ ");
        }
        for(i=f->primeiro; i<f->ultimo; i++){
            printf("%d ", f->v[i]);
        }
        for(i=f->ultimo; i<f->capacidade; i++){
            printf("_ ");
        }

    }

    // Se o "primeiro" for maior que o "ultimo" (já foi dado uma volta)
    else{
        for(i=0;i<f->ultimo; i++){
            printf("%d ", f->v[i]);
        }
        for(i=f->ultimo; i<f->primeiro; i++){
            printf("_ ");
        }
        for(i=f->primeiro; i<f->capacidade; i++){
            printf("%d ", f->v[i]);
        }

    }

    printf("\n");
}


