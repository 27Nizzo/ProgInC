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
/*3) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran o segundo maior elemento.*/
int ex3() {

    int maior, segundoMaior, num;
    scanf("%d", &num);
    maior = num; 
    if(num > maior) {
        segundoMaior = maior;
        maior = num; 
    } else {
        segundoMaior = num;
    }

    while (num != 0)
    {
        scanf("%d", &num);
        if(num != 0 && num > segundoMaior) {
            if(num > maior) {
                segundoMaior = maior;
                maior = num;
            } else {
                segundoMaior = num;
            }
        }
    }

        printf("%d\n", segundoMaior);
        return segundoMaior;
}

/*4) Defina uma fun¸c˜ao int bitsUm (unsigned int n) que calcula o n´umero de bits iguais a 1
usados na representa¸c˜ao bin´aria de um dado n´umero n.*/

int bistUm(unsigned int n) {
    int uns = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            uns++;
        }
    }
    return uns;
}

/*5) Defina uma fun¸c˜ao int trailingZ (unsigned int n) que calcula o n´umero de bits a 0 no
final da representa¸c˜ao bin´aria de um n´umero*/

int trailingZ(unsigned int n) {
    int zeros = 0;

    for(int i = n; i > 0; i /= 2) {
        if(i % 2 == 0) {
            zeros++;
        }
    }

    return zeros; 
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

    case 3:
        ex3();
        break;
    
    case 4:
        bistUm(5);
        break;
    
    case 5:
        trailingZ(5);
        break;

    default:
        break;
    }

    return 0;
}