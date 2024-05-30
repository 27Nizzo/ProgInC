#include <stdio.h>
#include <stdlib.h>

// Ex2: 
void swapM(int *x, int *y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
    printf("x = %d e y = %d\n", *x, *y);
}

// Ex3:
void swapInList(int v[], int i, int j){
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}

// Ex4:
void soma(int v[], int N){
    int soma = 0;

    for(int i = 0; i < N; i++){  
        soma += v[i];
    }
    printf("Soma: %d\n", soma);
}

// Ex5:
void inverteArray(int v[], int N){
    for(int i = 0; i < N/2; i++) swapInList(v, i, N-1-i);
}

void inverteArray2(int b[], int N){
    for(int i = 0; i < N/2; i++) swapM(b+i, b+N-1-i);
}

//Ex6:
int maximum(int v[], int N, int *m){
    if(N < 1) return -1;
    *m = v[0];
    for(int i = 0; i < N; i++){
        if(*m < v[i]){
            *m = v[i];
        }
        else {
            return *m;
        }
    }
}

//Ex7:
void quadrados(int q[], int N){
    q[0] = 0;
    for(int i = 0; i < N-1; i++){
        q[i+1] = q[i] + 2*i+1;
    }
}

//Ex8 a):
void pascal(int v[], int N){
    for(int n = 1; n <= N; n++){
        v[n-1] = 1;
        for(int i = n-2; i > 0; i--){
            v[i] = v[i] + v[i-1];
        }
    }
}

//Ex8 b):
void desenhaTriangulo(int N){
    int v[N];
    for(int i = 1; i < N; i++){
        v[i-1] = 1;
    
    for(int j = 0; j < i; j--){
        v[j] += v[j-1];   
    }
    for(int n = 0; n < i; n++) printf("%d ", v[n]);
    putchar('\n');
    }
}



int main(){
    return 0;
}