#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


//Arrays Ordenados:
//Ex4:
int ordenado(int v[], int N){
    for(int i = 0; i < N; i++){
        if(v[i] < v[i+1]){
            printf("A lista está ordenada por ordem crescente");
        } else {
            printf("A lista não está ordenada por ordem crescente");
        }
    }
    return v;
}

//Ex5:
void merge(int a[], int na, int b[], int nb, int r[]){
    int N = na + nb;
    int pA = 0, pB = 0;

    for(int total = 0; total < N; total++){
        if(pB >= nb){
            r[total] = a[pA++];
        } 
        else if(pA >= na){
            r[total] = b[pB++];
        }
        else if(b[pB] > a[pA]){
            r[total] = a[pA++];
        }
        else {
            r[total] = b[pB++];
        }
    }

}
//Ex6:
void swap(int v[], int i, int j){
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int partition(int v[], int N, int x){
    int pos = 0;

    for(int i = 0; i < N; i++){
        if(v[i] <= x){
            swap(v, i, pos++);
        }
    }
    return pos;
}






int main(){
    return 0;
}