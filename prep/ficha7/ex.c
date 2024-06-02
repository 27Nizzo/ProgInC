#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct celula
{
    char *palavra;
    int ocorr;
    struct celula *prox;
} * Palavras;


//Ex1: Função que liberta todo o espaço da heap ocupado pela lista de palavras
void libertaPalavras(Palavras p){
    while (p)
    {
        Palavras tmp = p;
        p = p->prox;
        free(tmp);
    }
}

//Ex2: Função que calcula quantas palavras diferentes existem armanezadas
int quantasP(Palavras l){
    int count = 0;
    while (l)
    {
        l = l->prox;
        count++;
    }
    return count;
}


//Ex3: 
void listaPal(Palavras l){
   while (l != NULL)
   {
    printf("Palavra %s, Ocorrencias: %d\n", l->palavra, l->ocorr);
    l = l->prox;
   }
   
}


//Ex4: Função que escreve no ecra, uma por linha, todas as palvras armanezadas, bem como o seu número de ocorrências

char * ultima(Palavras l){
    while(l){
        if(!(l->prox)){
            printf("%s\n", l->palavra);
        }
        l = l->prox;
    }
}

//Ex5: Função que acrescenta uma palavra no início da lista (com 1 como número de ocorrencias)

Palavras acrescentaInicio(Palavras l, char *p){
    Palavras tmp = malloc(sizeof(struct celula));
    tmp->palavra = p;
    tmp->ocorr = 1;
    tmp->prox = l;
    return tmp;
}

//Ex6: Função que acrescenta uma palavra no final da lista (com 1 como número de ocorrencias)

Palavras acrescentaFim(Palavras l, char *p) {
    Palavras tmp = malloc(sizeof(struct celula));
    tmp->palavra = p;
    tmp->ocorr = 1;
    tmp->prox = NULL;
    Palavras t = l;

    if(l == NULL){
        return t;
    }

    while (t->prox != NULL)
    {
        t = t->prox;
    }
    t->prox = tmp;
    return l;
}

//Ex7: Função que regista mais que uma ocorrência da palavra p. Se a palavra existir, o numero de ocorrências deve ser incrementado. No outro caso de ve ser inserida uma noiva celula

Palavras acrescenta(Palavras l, char *p) {
    Palavras nova = novaCelula(p,1);
    Palavras move = l;
    Palavras anterior = l;

    if(l == NULL){
        l = nova;
    }
    else {
        while(move->prox != NULL && strcmp(p, move->palavra) < 0){
            anterior = move;
            move = move->prox;
        }
        if(strcmp(p, move->palavra) == 0){
            move->ocorr++;
        }
        else if(move->prox == NULL){
            move->prox = nova;
        }
        else {
            nova->prox = move;
            anterior->prox = nova;
        }
    }
    return l;
}

struct celula * maisFreq(Palavras l){
    int max = 0;
    Palavras maisFreq = malloc(sizeof(struct celula));

    while (l)
    {
        if(l->ocorr > max){
            max = l->ocorr;
            maisFreq = l;
        }
        l = l->prox;
    }
    return maisFreq;
}


int main(){
 
    // Criação de exemplo de nós para testar a função listaPal
    struct celula celula3 = {"exemplo3", 1, NULL};
    struct celula celula2 = {"exemplo2", 2, &celula3};
    struct celula celula1 = {"exemplo1", 3, &celula2};

    // A cabeça da lista aponta para o primeiro nó
    Palavras lista = &celula1;

    // Chama a função para listar as palavras e suas ocorrências
    listaPal(lista);


    return 0;
}