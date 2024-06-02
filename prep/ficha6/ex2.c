#include<stdio.h>   
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 10

struct staticQueue
{
    int front;
    int length;
    int values[MAX];
} QUEUE, *SQueue;
 
//a) Função que inicializa uma queue

void SinitQueue(SQueue q){
    q->length = 0;
    q->front = 0;
}


//b) Função que testa se uma queue está vazia

typedef struct staticQueue* SQueue;

int SisEmptyQ(SQueue q){
    if(q->length == 0){
        return true;
    }
    else {
        return false;
    }
}

//c) Função que acrescenta x ao fim de q, a função deve retornar 0 se for a operação for feita, caso contrário retorna 1

int Senqueue(SQueue q, int x){
    int r = 0;
    if(q->length == MAX){
        r = 1;
    }
    else {
        q->values[(q->front + (q->length)++) % MAX] = x;
    }
    return r;
}

//d) Função que remove de uma queue o elemento que está no início. A função deverá colocar no endereço x o elemento removido. A função deverá retornar 0 se a operação for possível

int Sdequeue(SQueue q, int *x){
    int r = 0;

    if(q->length == 0){
        r = 1;
    }
    else {
        *x = q->values[(q->front)++];
        (q->length)--;
    }
    return r;
}

//e) Função que coloca no endereço x o elemento que está no início da queue. A função deve retornar 0 se a operação for possível e 1 em caso de erro, quando a queue estiver vazia
int Sfront(SQueue q, int *x){
    int r = 0;
    if(q->length == 0){
        r = 1;
    }
    else{
        *x = q->values[(q->front)];
    }
    return r;
}