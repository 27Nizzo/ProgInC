#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct slist
{
    int valor;
    struct slist *prox;
} *LInt;

typedef LInt Stack;

typedef struct {
    LInt inicio, fim;
} Queue;


LInt newLInt (int x, LInt xs){
    LInt r = malloc(sizeof(struct slist));
    if(r != NULL) {
    r->valor = x;
    r->prox = xs;
    }
    return r;
}

/* EX1: */

void initStack(Stack s){
    s->prox = 0;
    s->valor = 0;
}

int isEmpty(Stack s){
    int r = 0;
    if(s->prox == 0){
        r = 0;
    }
    else {
        r = 1;
    }
    return r;
}

int push(Stack *s, int *x){
    int r = 0;
    int add = newLInt(x, *s);
    if(add) {
        *s = add;
    }
    else {
        r = 1;
    }
    return r;
}

int pop(Stack *s, int *x){
    int r = 0;
    if(!isEmpty(s)){
        LInt ant = *s;
        *x = ant->valor;
        *s = (*s)->prox;
        free(ant);
    }
    else{
        r = 1;
    }
    return r;
}

int top(Stack s, int *x){
    int r = 0;
    if(!isEmpty(s)){
        while(s->prox){
            s = s->prox;
        }
        *x = s->valor;
    }
    else {
        r = 1;
    }
    return r;
}


/* EX2: */

void initQueue(Queue *q){
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty(Queue q){
    int r = 0;
    if(q.inicio == 0 || q.fim == 0){
        r = 0;
    }
    else {
        r = 1;
    }
    return r;
}

int enqueue(Queue *q, int x){
    LInt new = newLInt(x, NULL);
    int r = 1;
    if(new){
        r = 0;
        if(QisEmpty(*q)){
            q->inicio = q->fim = new;
        }
        else {
            q->fim = q->fim->prox = new;
        }
    }
    return r;
}

int dequeue(Queue *q, int *x){
    int r = 1;
    if(q->inicio){
        LInt temp = q->inicio;
        r = 0;
        *x = q->inicio->valor;
        if(q->inicio == q->fim){
            q->inicio = q->fim = NULL;
        }
        else{
            q->inicio = q->inicio->prox;
        }
        free(temp);
    }
    return r;
}

int front(Queue q, int *x){

}