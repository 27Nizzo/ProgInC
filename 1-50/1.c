#include <stdio.h>
#include <stdlib.h>

/*1) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros 
inteiros terminada com o n´umero 0 e imprime no ecran o maior elemento da sequˆencia.
*/

int ex1 () {
    int n; 
    scanf("%d", &n);
    int max = n;

    while (n != 0)
    {
        scanf("%d", &n);
        if(n > max) {
            max = n;
        } 
    }
    printf("%d\n", max);
    return max; 
}

/*2) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros
 inteiros terminada com o n´umero 0 e imprime no ecran a m´edia da sequˆencia.
*/

float ex2() {
    float num, soma;
    int numElems = 0;
    float media;

    scanf("%f", &num);
    soma = num;

     do {
        scanf("%f", &num);
        numElems++;
        soma += num;
    } while(num != 0);

    media = soma/numElems;
    printf("%f", media);
    return media;
}

int ex3() {

        

    return 0;
}

int main() {

    int choice = 0;

    printf("Escolhe um exercicio de 1-50: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        ex1();
        break;

    case 2: 
        ex2();
        break; 

    default:
        break;
    }

    return 0;
}