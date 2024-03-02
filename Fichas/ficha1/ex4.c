#include <stdio.h>



int main() {
    int radius;
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);

    // Draw the upper half of the circle
    for (int i = radius; i >= -radius; i--) {
        for (int j = -radius; j <= radius; j++) {
            if (j * j + i * i <= radius * radius) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}

/*
      #
    #####
   #######
   #######
  #########
   #######
   #######
    #####
      #

*/
