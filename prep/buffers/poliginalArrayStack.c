#include <stdlib.h>
#include <stdio.h>

#define MAX 100
#define MIN 1


enum cor {RED, GREEN, BLUE};
typedef enum cor cor;

struct ponto {
    float x;
    float y;
};

typedef struct {
    int capacidade;
    int tamanho;
    struct ponto *pontos;
    cor cor;
} poligonal;

int aloca(poligonal *l, cor c) {
    l->capacidade = MIN;
    l->tamanho = 0;
    l->cor = c;
    l->pontos = (struct ponto *)malloc(l->capacidade * sizeof(struct ponto));
    if(l->pontos == NULL) {
        return 1;
    } 
    return 0;
}

void liberta(poligonal *l) {
    free(l->pontos);
    l->pontos = NULL;
}

int extende(poligonal *l, struct ponto p) {
    if(l->tamanho == l->capacidade) {
        struct ponto *new = (struct ponto *)malloc(2 * l->capacidade * sizeof(struct ponto));
        if(new == NULL) {
            return 1;
        }
        for(int i = 0; i < l->tamanho; i++) {
            new[i] = l->pontos[i];
        }
        free(l->pontos);
        l->pontos = new;
        l->capacidade *= 2;
    }
    l->pontos[l->tamanho] = p;
    l->tamanho++;
    return 0;
}

int main() {
    struct ponto a = {1, 5};
    struct ponto b = {2, 3};
    struct ponto c = {3, 4};
    poligonal l;

    if (aloca(&l, RED) != 0) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    extende(&l, a);
    extende(&l, b);
    extende(&l, c);

    // Imprimindo pontos para verificar
    for (int i = 0; i < l.tamanho; i++) {
        printf("Ponto %d: (%.1f, %.1f)\n", i + 1, l.pontos[i].x, l.pontos[i].y);
    }

    liberta(&l);
    
    return 0;
}
