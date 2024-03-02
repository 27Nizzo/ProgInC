#include <stdio.h>

void replicate (int n, char c) {
    for(int i = 0; i < n; i++){
        putchar(c);
    }
}


void trianguloHoriz(int n) {
    for (int i = 1; i <= n; i++) {
        replicate(i, '#');
        putchar('\n');
    }
    for (int j = n - 1; j >= 1; j--) {
        replicate(j, '#');
        putchar('\n');
    }
}


int main () {
    trianguloHoriz(5);
    return 0;
    
}



/* Output: 

#
##
###
####
#####
####
###
##
#

*/



