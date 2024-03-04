#include <stdio.h>
#include <string.h>


int main() {
    char binario[100];
    int decimal = 0;

    scanf("%s", binario);

    int tamanho = strlen(binario);

    for (int i = 0; i < tamanho; i++) {
        decimal = decimal * 2 + (binario[i] - '0');
    }

    printf("%d\n", decimal);

    return 0;
}

