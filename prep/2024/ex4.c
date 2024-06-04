#include<stdio.h>
#include<stdlib.h>

/*
 Defina uma função int maxCresc(LInt l) que calcula o comprimento da maior sequência crescente
de elementos consecutivos numa lista. Por exemplo, se a lista for [ 1, 2, 3, 2, 1, 4, 10, 12, 5, 4], a função
deverá retornar 4. Serão desvalorizadas soluções que consultem cada nodo da lista mais do que uma vez
*/

typedef struct lint_nodo{
    int valor;
    struct lint_nodo *prox;
} *LInt;

int maxCresc(LInt l){
    if(l == NULL) return;

    int lenMax = 1;
    int currLen = 1;
    LInt curr = l;

    while(curr->prox != NULL){
        if(curr->prox->valor > curr->valor){
            currLen++;
        }
        else {
            if(currLen > lenMax){
                lenMax = currLen;
            }
            currLen = 1;
        }
        curr = curr->prox;
    } 

    if(currLen > lenMax){
        lenMax = currLen;
    }
    return lenMax;
}