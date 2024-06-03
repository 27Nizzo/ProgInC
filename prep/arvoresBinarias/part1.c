#include<stdio.h>
#include<stdlib.h>


typedef struct abin_no{
    int valor;
    struct abin_no *esq, *dir;
} *abin;


//Criação de uma raiz:

abin mkroot(int x, abin e, abin d){
    abin new = malloc(sizeof(struct abin_no));
    new->valor = x;
    new->dir = d;
    new ->esq = e;
    return new;
}

//Tamanho de uma arvore binaria:

int size(abin a){
    int r = 0;
    if(a == NULL){
        return r;
    }
    else{
        r = 1 + size(a->esq) + size(a->dir);
    }
    return r;
}

// Criação de uma arvore binária por um array:

abin fromArray(int v[], int N){
    abin a = NULL;
    for(int i = 0; i < N; i++){
        a = mkroot(v[i], a, NULL);
    }
    return a;
}


// Criação de uma arvore binária por um array(melhor forma,  arvore binaria balanceada):

abin fromArray2(int v[], int N){
    abin a;
    if(N == 0){
        a = NULL;
    }
    else{
        int m = N/2;
        abin l = fromArray2(v,m);
        abin r = fromArray2(v+m+1, N-m-1);
        a = mkroot(v[m], l, r);
    }
    return a;
}

// Travessia inOrder:

void inOrder(abin a){
    if(a == NULL){
        return;
    }
    else{
        inOrder(a->esq);
        printf("%d\n", a->valor);
        inOrder(a->dir);
    }
}

// Travessia preOrder:

void preOrder(abin a){
    if(a == NULL){
        return;
    }
    else{
        printf("%d\n", a->valor);
        preOrder(a->esq);
        preOrder(a->dir);
    }
}

// Travessia postOrder:

void postOrder(abin a){
    if(a == NULL){
        return;
    }
    else{
        postOrder(a->esq);
        postOrder(a->dir);
        printf("%d\n", a->valor);
    }
}

// Copiar para array inOrder:

int toArrayInOrder(abin a, int v[]){
    int l, r;
    if(a == NULL){
        return 0;
    }
    else{
        l = toArrayInOrder(a->esq, v);
        v[l] = a->valor;
        r = toArrayInOrder(a->dir, v);
    }
    return 1+l+r;
}

// Copiar para array preOrder:

int toArrayPreOrder(abin a, int v[]){
    int l, r;
    if(a == NULL){
        return 0;
    }
    else{
        v[0] = a->valor;
        l = toArrayPreOrder(a->esq, v);
        r = toArrayPreOrder(a->dir, v);
    }
    return 1+l+r;
}

// Copiar para array postOrder:

int toArrayPostOrder(abin a, int v[]){
    int l, r;
    if(a == NULL){
        return 0;
    }
    else{
        l = toArrayPostOrder(a->esq, v);
        r = toArrayPostOrder(a->dir, v);
        v[l+r] = a->valor;
    }
    return 1+l+r;
}


// Pesquisa de um valor em uma árvore binária:

abin search(int x, abin a) {
    abin r;
    if (a == NULL) {
        return NULL;
    }
    if (a->valor == x) {
        printf("Encontrei\n");
        return a;
    }
    r = search(x, a->esq);
    if (r == NULL) {
        r = search(x, a->dir);
    }
    return r;
}

// Pesquisa Ordenada em uma árvore binária:

abin searchOrd(int x, abin a) {
    if(a == NULL){
        return NULL;
    }
    if(a->valor == x){
        return a;
    }
    if(a->valor > x){
        return searchOrd(x, a->esq);
    }
    else{
        return searchOrd(x, a->dir);
    }
}


// Inserção de um valor em uma árvore binária:

abin insert(int x, abin a){
    abin *aux = &a, new = mkroot(x, NULL, NULL);
    while (*aux != NULL)
    {
        if((*aux)->valor > x){
            aux = &(*aux)->esq;
        }
        else {
            aux = &(*aux)->dir;
        }
    }
    *aux = new;
    return a;
}

// Eliminação de um node de uma arvore binária:

abin delete(int x, abin a) {
    if (a == NULL) {
        return NULL;
    }
    if (x < a->valor) {
        a->esq = delete(x, a->esq);
    } else if (x > a->valor) {
        a->dir = delete(x, a->dir);
    } else {
        if (a->esq == NULL) {
            abin aux = a->dir;
            free(a);
            return aux;
        } else if (a->dir == NULL) {
            abin aux = a->esq;
            free(a);
            return aux;
        }
        abin temp = a->dir;
        while (temp && temp->esq != NULL) {
            temp = temp->esq;
        }
        a->valor = temp->valor;
        a->dir = delete(temp->valor, a->dir);
    }
    return a;
}


int main(){
    abin a = mkroot(3, mkroot(5, NULL, NULL), mkroot(8, NULL, NULL));
    size(a);
    printf("%d\n", size(a));
    printf("InOrder:\n");
    inOrder(a);
    printf("PreOrder:\n");
    preOrder(a);
    search(8, a);
    delete(5,a);
    inOrder(a);
    return 0;
}