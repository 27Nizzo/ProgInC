#include<stdio.h>
#include<stdlib.h>

typedef struct abin_nodo{
    int valor;
    struct abin_nodo *esq, *dir;
} *ABin;


ABin folhaEsq(ABin a){
    if(a == NULL){
        return -1;
    } 
    else{
        while(a->esq != NULL) {
            a = a->esq;
        }
    }
    return a;
}