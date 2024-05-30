#include<stdio.h>
#include<stdlib.h>

void ex1a(){
    int x[15] = {1, 2, 3, 4, 5,
                 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15};
    int *y, *z, i;
    y = x;
    z = x + 3;
    for(i = 0; i < 5; i++){
        printf("%d %d %d\n", x[i], *y, *z);
        y = y + 1; z = z + 2;
    }
}
/*Explicaçaõ do código: */
// O y vai ser sempre 1 e itera sempre uma vez sempre que o loop recomeça, ou seja, quando i = 0 => y = 1, i = 1 => y = 2.
// O z é o valor inicial do array de x, que neste caso é 1 + 3 = 4, e itera sempre + 2 quando o loop recomeça assim como o y, ou seja, i = 0 => z = 1 + 3 = 4, i = 1 => z = 4 + 2 = 6.

void ex1b(){
    int i, j, *a, *b;
    i = 3; j = 5; // valores definidos para i e j
    a = b = 42; // valores definidos para a e b
    a = &i; b = &j; // redefine os valores de a e b para os endereços de i e de j
    
    i++; // incrementa 1 em i, i = 3 + 1 = 4
    j = i + *b; // redefine o valor de j com a soma de i = 4 e do endereço apontado por b que é o endereço j que é 5, logo j = 4 + 5 = 9
    b = a; // o valor de b fica igual ao de a, o endereço de b fica igual ao do a, neste caso o b = &i = 4
    j = j + *b; // redefine uma ultima vez o valor de j com uma soma do mesmo com o endereço apontado por b, logo j = 9 + 4 = 13
    printf("%d\n", j); // com os cálculos efetuados concluimos que o valor final de j vai ser 13

    return 0;
}