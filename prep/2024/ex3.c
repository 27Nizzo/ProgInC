#include<stdio.h>
#include<stdlib.h>


/*
Implemente de forma iterativa a função int delete(int n, LInt *l) que apaga o n-ésimo elemento
de uma lista ligada (para n == 0 a função deverá remover o primeiro elemento). Se tal não for possível a
função deverá devolver um código de erro.
*/

typedef struct lint_nodo{
    int valor;
    struct lint_nodo *prox;
} *LInt;

int delete(int n, LInt *l){
    if(*l == NULL){
        return -1;
    }

    if(n == 0){
        LInt tmp = *l;
        *l = (*l)->prox;
        free(tmp);
        return 0;
        //Remoção do primeiro elemento caso o n == 0
    }
    LInt current = *l;
    for(int i = 0; i < n - 1; i++){
        if(current->prox == NULL){
            return -1;
        }
        current = current->prox;
    }

    LInt tmp = current->prox;
    if(tmp != NULL){
        current->prox = tmp->prox;
        free(tmp);
        return 0;
    }
    else {
        return -1;
    }
}
