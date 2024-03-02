#include <stdio.h>

int soma(int v[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += v[i];
    }
    return s;
}

int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x;

    // Passando um ponteiro para o quarto elemento do array a e n = 5
    x = soma(a, 10);

    printf("A soma dos elementos é: %d\n", x);

    return 0;
}
