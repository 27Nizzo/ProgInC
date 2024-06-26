#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct dinStack
{
    int size;
    int sp;
    int *values;
} *DStack;

int dupStack(DStack s){
    int r = 0, i;
    int *t = malloc(2*s->size*sizeof(int));

    if(t == NULL) {
        r = 1;
    }
    else{
        for(i = 0; i < s->size; i++){
            t[i] = s->values[i];
        }
        free(s->values);
        s->values = t;
        s->size *= 2;
    }
    return r;
}

void DinitStack(DStack s){
    s->size = 5;
    s->sp = 0;
    s->values = malloc(sizeof(int) * s->size);
}

int DisEmpty(DStack s){
    if(s->size == 0){
        return true;
    }
    else{
        return false;
    }
}

int Dpush(DStack s, int x){
    int r = 0;
    if(s->sp == s->size){
        dupStack(s);
    }
    s->values[(s->sp)++] = x;
}

int Dpop(DStack s, int *x){
    int r = 0; 
    if(s->size == 0) {
        r = 1;
    }
    else{
        *x = s->values[--(s->sp)];
    }
    return r;
}

int Dtop(DStack s, int *x) {
    int r = 0;

    if(s->sp == 0){
        r = 1;
    }
    else{
        *x = s->values[s->sp-1];
    }
    return r;
}