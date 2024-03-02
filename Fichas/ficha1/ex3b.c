#include <stdio.h>

void desenhar_triangulo(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for(int k = 0; k < 2 * i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
}

int main() {
    desenhar_triangulo(4);
    return 0;
}


/* Output: 

    #
   ###
  #####
 #######
#########

*/