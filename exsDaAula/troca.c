#include<stdio.h>

void troca(int *a, int *b) {
    int t;

    t = *a, *a = *b;
    *b = t;
}


int main() {
    int a = 4;
    int b = 7;

    int x;
    x = 42;
    x *= 2;

    troca(&a,&b);

    printf("a = %d e b = %d\n", a,b);
    printf("%d", sizeof(x));
    return 0;
}