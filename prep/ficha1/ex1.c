#include<stdio.h>
#include<stdlib.h>

//Ex 1:
float multInt1(int n, float m) {

    for(int r = 0; r <= n; r++){
        int final;
        final = r * m;
        printf("%d * %f = %d\n", r, m, final);
    }

}

// Ex2:
float multInt2(int n, float m){
    float r = 0;
        printf("Dentro do LOOP:\n");

    for(; n > 1; n /= 2) {
        if(n % 2 != 0){
            r += m;
            printf("r = %f\n", r);
            m *= 2;
            printf("%f\n", m);
            printf("---------\n");
        }
    }
    printf("Fora do LOOP: \n");
     printf("r = %f\n", r);
     printf("m = %f\n", m);
}

//Ex3:
int mdc1(int a, int b){
    int min = 0;
    if(a < b){
        min = a; 
    } else {
        min = b;
    }
    while(min != 0){
        if(a % min == 0 && b % min == 0){
            printf("O mdc de a = %d e de b = %d é %d\n", a,b,min);
            return min;
        } else {
            min--;
        }
    }
}

//Ex4: Algoritmo de Euclides
int mdc2(int a, int b){
    int newA = a;
    int newB = b;
    while (newA != 0 && newB != 0)
    {
        if(newA > newB){
            newA -= newB;
        } else {
             newB -= newA;
        }
    }
    int r = newA + newB;
    printf("O mdc de a = %d e b = %d é %d\n", a, b, r);
    return r;
}

// Ex5: Algoritmo de Euclides mas com o resto da divisão inteira
int mdc3(int a, int b){
    int newA = a;
    int newB = b;

    while (newA != 0 && newB != 0)
    {
        if(newA > newB){
            newA %= newB;
        } else {
            newB %= newA;
        }
    }
    int r = newA + newB;
    printf("O mdc de a = %d e b = %d é %d\n", a, b, r);
    return r;    
}

// Ex6:
//a)

int fib1(int n){
    int r;
    if(n < 2){
        r = 1;
    } else{
        r = (fib1(n-1) + fib1(n-2));
    }
    printf("Result is %d\n", r);
    return r;
}
//b)

int fib2(int n) {
    if (n < 2) {
        return 1;
    }
    
    int a = 1; // F(n-2)
    int b = 1; // F(n-1)
    int result = 1; // F(n)
    
    for (int i = 2; i <= n; i++) {
        result = a + b; // F(n) = F(n-1) + F(n-2)
        a = b; // Atualiza F(n-2)
        b = result; // Atualiza F(n-1)
    }
    
    return result;
}


int main(){

    int exercicio;

    printf("Enter a exercise: \n");
    scanf("%d", &exercicio);

    switch (exercicio)
    {
    case 1:
        printf("Exercicio 1:\n");
        float result1 = multInt1(12,2.5);    
        break;

    case 2:
        printf("Exercicio 2:\n");
        float result2 = multInt2(1101,5.0);
        break;

    
    case 3:
        printf("Exercicio 3:\n");
        int result3 = mdc1(12,30);
        break;


    case 4:
        printf("Exercicio 4:\n");
        int result4 = mdc2(12,30);
        break;
        
    
    case 5:
        printf("Exercicio 5:\n");
        int result5 = mdc3(12,30);
        break;

    case 6:
        printf("Exercicio 6 a):\n");
        int result6 = fib1(5);
        break;

    case 7:
        printf("Exercicio 6 b):\n");
        int result7 = fib2(1);
        break;
    }

}