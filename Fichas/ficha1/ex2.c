#include <stdio.h>

void chess (int s);

int main() {

    chess(5);

    return 0;
}

void chess (int s){

    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            if ((i + j) % 2 == 0) {
                putchar('#');    
            } else {
                putchar('_');
            }
        }
        putchar('\n');
    }
}