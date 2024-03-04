
// Ex2:
void swapM (int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;

}

//Ex3: 
void swap(int v[], int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = v[i];

}

//Ex4: 
int soma(int v[], int N) {
    int soma = 0;

    for(int i = 0; i < N; i++){
        soma += v[i];
    }
    return soma;
}

//Ex5: 
//(Swap)
void inverteArray1(int v[], int N, int *m) {
    for(int i = 0; i < N/2; i++) {
        swap(v,i, N - 1 - i);
    }
}
//(SwapM)
void inverteArray2(int v[], int N, int *m) {
    for (int i = 0; i < N; i++)
    {
        swapM(v+i, v + N - 1 - i);
    }    
}

//Ex6:
int maximum(int v[], int N, int *m){
    if (N < 1) {
        return -1;
    } else {
        *m = v[0];
        for(int i = 1; i < N; i++) {

            if(v[i] > *m) {
                *m = v[i];
            }
        }
    }
    return 0;
}

//Ex7: 
void quadrados(int q[], int N) {
    q[0] = 0;
    for (int i = 0; i < N; i++)
    {
        q[i+1] = q[i] + 2*i+1;
    }    
}

//Ex8: 
//a)
void pascal(int v[], int N) {
    for(int i = 1; i < N; i++) {
        v[i-1] = 1;
        for (int j = i - 2; j > 0; j--)
        {
            v[j] = v[j] + v[j-1];
        }   
    }
}
//b)
void desenhaTriangulo(int N) {
    int v[N];
    for(int i = 1; i <= N; i++) {
        v[i-1] = 1;
        for(int j = i - 2; j > 0; j--) {
            v[j] = v[j] + v[j-1];
        }
        for (int n = 0; n < i; n++)
        {
            printf("%d ", v[n]);
            putchar('\n');
        }   
    }
}