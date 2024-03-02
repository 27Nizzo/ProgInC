#include <stdio.h>


void replicate (int n, char c) {
    for (int i = 0; i < n; i++) {
        putchar(c);
    }
}

void quadrado(int l) {

    for(int i = 0; i < l; i++) {
        replicate(l, '#');
        putchar('\n');
    }
}


int main() {

    quadrado(4);

    return 0;
}

