#include<stdio.h>
#include<stdlib.h>

/*
2. Implemente a função void rodaEsq(int a[], int N, int r) por forma a rodar os elementos de um
array com N inteiros r posições para a esquerda (assuma que r < N). Por exemplo, se o array tiver o
conteúdo {1,2,3,4,5,6} e se r == 2 então o array deverá ficar com os valores {3,4,5,6,1,2}. Tente
minimizar o número de escritas no array.

*/

void rodaEsq(int a[], int N, int r){
   if(a == NULL) return;

   for(int i = 0; i < N; i++){
     int aux = a[0];
     for(int j = 0; j < N-1; j++){
        a[j] = a[j+1];
     }
     a[N-1] = aux;
   }
}

int main(){
  
    int a[] = {1, 2, 3, 4, 5, 6};
    int N = sizeof(a)/sizeof(a[0]);
    int r = 2;

    printf("Array original: ");
    for(int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    rodaEsq(a, N, r);

    printf("Array após rotação de %d posições para a esquerda: ", r);
    for(int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}