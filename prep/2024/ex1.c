#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/*
1. Adapte a função fizzbuzz definida abaixo por forma a devolver quantos números são impressos entre
a primeira linha do tipo FizzBuzz e a primeira linha do tipo Buzz que se lhe segue? Se não aparecer
nenhuma linha do tipo Buzz depois de uma linha do tipo FizzBuzz deve devolver -1.
int fizz(int n) {...}
int buzz(int n) {...}
int fizzbuzz(int n) {
for (int i = 0; i < n; i++) {
if (fizz(i) && buzz(i)) printf("FizzBuzz\n");
else if (fizz(i)) printf("Fizz\n");
else if (buzz(i)) printf("Buzz\n");
else printf("%d\n", i);
}
return 0;
}

*/


int fizz(int n) {
    return 0;
}

int buzz(int n){
    return 0;
}

int fizzbuzz(int n){
    int count = 0;
    bool fizzBuzzPrinted = false;
    bool buzzPrinted = false;

    for(int i = 0; i < n; i++){
        if(fizz(i) && buzz(i)){
            printf("FizzBuzz\n");
            fizzBuzzPrinted = true;
            count = 0;
        }
        else if(fizz(i)){
            printf("Fizz\n");
            count++;
        }
        else if(buzz(i)){
            printf("Buzz\n");
            buzzPrinted = true;
            break;
        }  
        else {
            printf("%d\n", i);
            count++;
        }
        if(fizzBuzzPrinted) {
            return count;
        }
        else {
            return -1;
        }
    }
    return 0;
}