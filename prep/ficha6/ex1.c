#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 100

struct staticStack
{
    int sp;
    int values[MAX];
};

typedef struct staticStack *SStack; 

//a) Função que inicializa uma Stack

void SinitStack(SStack s){
    s->sp = 0;
}

//b) Função que testa se uma stack é vazia ou não

int SisEmpty(SStack s){
    if(s->sp == 0){
        return s;
    }
}

//c) Função que acrescenta x ao topo de s, a função deve retornar 0 se a operação for feita com sucesso e 1 caso contrário

int Spush(SStack s, int x){
    int r = 0;
    if(s->sp == MAX){
        r = 1;
    }
    else {
        s->values[(s->sp)++] = x;
        r = 0;
    }
    return r;
}

//d) Função que remove de uma stack o elemnto que está no topo. A função deve retornar 0 se a operação for possível e 1 em caso de erro

int Spop(SStack s, int *x){
    int r = 0;

    if(s->sp == 0){
        r = 1;
    }
    else {
        *x = s->values[--(s->sp)];
    }
    return r;
}

//e) Função que coloca no endereço de x o elemento que está no topo da stack. A função deve retornar 0 caso possível, caso contrário retorna 1

int Stop(SStack s, int *x){
    int r = 0;
    if(s->sp == 0){
        r = 1;
    }
    else {
        *x = s->values[s->sp-1];
    }
    return r;
}