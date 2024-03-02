#include <stdio.h>


void replicate(int n, char c) {
    for (int i = 0; i < n; i++) {
        putchar(c);
    }
}


void triangV (int n) {

    int espaço = n - 1;
    int card = 1;

    for (int i = 0; i < n; i++) {
        replicate(espaço, ' ');
        replicate(card, '#');
        espaço -= 1;
        card += 2;
        putchar('\n');
    }
}

int main () {

    triangV(5);

    return 0;
}