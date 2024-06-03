#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;


ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc(sizeof(struct nodo));
    if(a != NULL){
        a->valor = r;
        a->esq = e;
        a->dir = d;
    }
    return a;
}

//Ex1:
//a)
int altura(ABin a){
    int c = 0;
    if(a == NULL) {
        return 0;
    }
    else {
        c = 1 + altura(a->esq) + altura(a->dir);
    }
    return c;
}

//b) 
int nFolhas(ABin a){
    int c = 0;
    if(a == NULL) {
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    else {
        c = nFolhas(a->esq) + nFolhas(a->dir);
    }
    return c;
}

//c)
ABin maisEsquerda(ABin a){
    if(a == NULL) {
        return NULL;
    }
    while(a->esq != NULL){
            a = a->esq;
            }
    return a; 
}


//d) 
void imprimeNivel(ABin a, int l){
    if(a == NULL){
        return 1;
    }

    if(l == 0){
        printf("%d\n", a->valor);
    } else {
        imprimeNivel(a->esq, l - 1);
        imprimeNivel(a->dir, l - 1);
    }
}

//e) 
int procuraE (ABin a, int x) {

    if(a == NULL){
        return false;
    }
    if(a->valor == x){
        return true;
    } else if(a->valor > x){
       procuraE(a->esq, x);
    } else {
       procuraE(a->dir, x);
    }
}

//EX2:
//a)
    struct nodo *procura(ABin a, int x){
        if(a == NULL){
            return NULL;
        }
        if(a->valor == x){
            return a->valor;
        }
        else if(a->valor > x){
            procura(a->esq, x);
        }
        else {
            procura(a->dir, x);
        }
    }

//b) 
int nivel(ABin a, int x){
    int n = 0;

    while (a != NULL)
    {
        if(a->valor == x){
            return n;
        }
        if(a->valor > x){
            a = a->esq;
        }
        else {
            a = a->dir;
        }
        n++;
    }
    return -1;
}

/* c) void imprimeAte (ABin a, int x) que imprime no ecran, por ordem crescente, todos os
      elementos da ´arvore que s˜ao (estritamente) menores do que um dado valor */

void imprimeAte(ABin a, int x){
    if(a == NULL){
        return NULL;
    }
    
    imprimeAte(a->esq, x);
    if(a->valor > x){
        printf("%d\n", a->valor);
    }
    imprimeAte(a->dir, x);

}

int main() {
    ABin a = newABin(3, newABin(1, NULL, NULL), newABin(5, NULL, newABin(8, NULL, NULL)));
    printf("Altura: %d\n", altura(a));
    printf("Número de folhas: %d\n", nFolhas(a));
    printf("Mais à esquerda: %d\n", maisEsquerda(a)->valor);
    printf("Imprime nível 1:\n");
    imprimeNivel(a, 1);
    printf("Procura 5: %s\n", procuraE(a, 5) ? "Encontrado" : "Não encontrado");
    printf("Imprime até 5:\n");
    imprimeAte(a, 5);
    return 0;
}