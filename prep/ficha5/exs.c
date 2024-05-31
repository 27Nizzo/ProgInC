#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXCHARPARANOME 100
#define TOTALDEMINITESTES 6

typedef struct aluno 
{
    int numero;
    char nome[MAXCHARPARANOME];
    int miniT[TOTALDEMINITESTES];
    float teste;
} Aluno;

/*Funções a utilizar:
-> strcpy(): copia a string dada de uma locazição para outra
-> strcmp(): compara o valor de duas strings e retorna um 
valor que indica a relação entre as mesmas
*/

//Ex1:
int nota(Aluno a){
    int total = 0;
    for(int i = 0; i < 6; i++){
        total += a.miniT[i];
    }
    total /= 2;
    total += a.teste * 0.7;
    return total;
}


//Ex2:
int procuraNum(int num, Aluno t[], int N){
    for(int i = 0; i < N; i++){
        if(num == t[i].numero){
            return i;
        } 
        else {
            return -1;
        }
    }
}

//Ex3:

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void ordenaPorNum(Aluno t[], int N){
   for(int i = 0; i < N - 1; i++){
    for(int j = i + 1; j < N - i - 1; j++){
        if(t[j].numero > t[j + 1].numero){
            swap(&t[j], &t[j + 1]);
            }   
        }
    }
}

//Ex4:

void criaIndPorNum(Aluno t[], int N, int ind[]){
  //  int ind[N];

    for(int i = 0; i < N; i++){
        ind[i] = i;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(t[ind[j]].numero < t[ind[i]].numero){
                swap(ind+i, ind+j);
            }
            ind[ind[i]] = i;
        }
    }
}

//Ex5:

void imprimeTurma(int ind[], Aluno t[], int N){
    int next = 0, i;
    for(; next < N; next++){
        for(int i = 0; ind[i] != next; i++);
            printf("%d %s\n", t[i].numero, t[i].nome);
        } 
    }

//Ex6:

int procuraNumInd(int num, int ind[], Aluno t[], int N){
    for(int i = 0; i < N; i++){
        if(i < N && t[i].numero == num){
            return ind[i];
        }
        else {
            return -1;
        }
    }
}

//Ex7:

void criaIndPorNome(Aluno t[], int N, int ind[]){
    for(int i = 0; i < N; i++){
        ind[i] = i;
    } 
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            if(strcmp(t[ind[j]].nome, t[ind[i]].nome) < 0){
                swap(ind + i, ind + j);
            }
        }
        ind[ind[i]] = i;
    }
}



int main(){
    return 0;
}