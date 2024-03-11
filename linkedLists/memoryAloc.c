#include <stdio.h>
#include <stdlib.h>

// malloc() -> reserva o bloco de memória de um específico número de bytes. E, o mesmo retorna o pointer do void, o qual pode ser chamado para pointers de qualquer forma.

// calloc() -> calloc significa alocação contínua, o malloc aloca memória e deixa a memória sem ser ser inicializada. O calloc() aloca memória e inicia todos os bits para zero.

// free() -> Aloca memória dinamicamente criado pelo calloc() ou pelo malloc() e não se solta por si só. Temos que usar explicitamente a função free() para soltar o espaço.

// realloc() -> Aloca memória dinamicamente se for insuficiente ou demasiado para o que é necessário, podemos mudar o tamanho da memória alocada anteriormente usando a função ralloc().

//Exemplo1:

void ex1() 
 {
    int n, i, *ptr, sum = 0;
    printf("Enter number of elements:\n");
    scanf("%d\n", &n);

    ptr = (int*) malloc(n * sizeof(int));

    // if para quando nao for possivel alocar a memoria
    if(ptr == NULL){
        printf("Error! Memory not alocated.");
        exit(0);
    }

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d\n", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum = %d\n", sum);

    // deslocando a memória
    free(ptr);

    return 0; 
}


//Exemplo2:

void ex2() {
    int n, i, *ptr, sum = 0; 
    printf("Enter a number of elements: ");
    scanf("%d\n", &n);

    ptr = (int*) calloc(n, sizeof(int));
    if(ptr == NULL) {
        printf("Error! Memory not alocated!");
        exit(0);
    }

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d\n", ptr + 1);
        sum += *(ptr + 1);
    }

    printf("Sum = %d\n", sum);
    free(ptr);
    return 0; 
}

//Exemplo3: 
void ex3() {
    int* ptr, i, n1, n2;
    printf("Enter size: ");
    scanf("%d\n", &n1);


    ptr = (int*) malloc(n1 * sizeof(int));

    printf("Addresses of previously allocated memory:\n");
    for(i = 0; i < n1; i++) 
        printf("%pc\n", ptr + i);
    
    printf("\nEnter the new size: ");
    scanf("%d", &n2);

    ptr = realloc(ptr, n2 * sizeof(int));

    printf("Adresses of newly allocated memory:\n");
    for(i = 0; i < n2; i++) {
        printf("%pc\n", ptr + i);
    }

    free(ptr);

    return 0;

}