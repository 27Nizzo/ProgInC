#include <stdio.h>
#include <stdlib.h>

// Arrays Ordenados: 

//Ex1: Defina uma função int ordenado (int v[], int N) que testa se um array de inteiros está ordenado por ordem crescente:

int ordenado(int v[], int N) {
    char r = 1; 
    for(int i = 0; i < N - 1 && r; i++) {
        r = v[i] >= v[i-1];
    }
    return r; 
}

//Ex2: Defina uma função que recebe dois arrays ordenados 'a' e 'b' com tamanhos 'na' e 'nb' e os funde num só array ordenado r. Assumindo que o array r tem capacidade para armanezar os na+nb elementos:

void merge(int a[], int na, int b[], int nb, int r[]) {
    int N = na + nb; 
    int pA = 0, pB = 0; 

    for(int total = 0; total < N; total++) {
        if(pB >= nb) {
            r[total] = a[pA++];
        } else if (pA >= na) {
            r[total] = b[pB++]; 
        } else if(b[pB] > a[pA]) {
            r[total] = a[pA++];
        } else {
            r[total] = b[pB++];
        }
    }
}

//Ex3: Defina uma função que, dado um array v de tamanho N e um inteiro x, reorganiza o array de forma a que começam por aparecer todos os elementos menores ou iguais a x seguidos dos restantes elementos. 
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j]; 
    v[j] = temp;
}

int partition (int v[], int N, int x) {
    int pos = 0;

    for(int i = 0; i < N; i++) {
        if(v[i] <= x){
            swap(v, i, pos++);
        }
    }
    return pos;
}




int main () {
    //Ex1:
    int list1[] = {1,2,3,4,5,6};
    int list2[] = {2,4,6,1,56};

    int res1 = ordenado(list1, 6);
    int res2 = ordenado(list2, 6);

    printf("Resultado: %d\n", res1);
    printf("Resultado: %d\n", res2);

    //Ex2: 

    int list3[] = {1,2,3};
    int list4[] = {4,5,6};

    int merged[6];
    merge(list3, 3, list4, 4, merged);

    printf("Array junto: ");
    for(int i = 0; i < 6; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    //Ex3: 

    int list5[] = {1,2,3,4,5};
    int pos = partition(list5, 5, 1);

    printf("Array após partition: ");
    for(int i = 0; i < 5; i++) {
        printf("%d" , list5[i]);
    }
    printf("\n");
    printf("Poisição da separação: %d\n", pos);

    return 0; 
}