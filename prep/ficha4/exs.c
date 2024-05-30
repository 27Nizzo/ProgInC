#include<stdio.h>
#include<stdlib.h>

/*Funções a usar:
-> isdigit(c) -> para verificar se é um número;
-> toupper(c) -> mete o caractere em maiúscula;
-> tolower(c) -> mete o caractere em minúscula;
*/

// Ex1
int contaVogais(char *s){
    int contador = 0;

    while (*s != '\0')
    {
        if(*s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U' ||
           *s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u') {
            contador++;
           }
           s++;
    }
    return contador;
}

//Ex2:
int retiraVogaisRep(char *s){
    int vogaisRemovidas = 0; 
    int pos = 0;

    for(int i = 0; i *s[i] != '\0'; pos++){
        s[pos] = s[i++];
        int min = (s[pos] == 'a'|| s[pos] == 'e'|| s[pos] == 'i'|| s[pos] == 'o'|| s[pos] == 'u');
        int mai = (s[pos] == 'A'|| s[pos] == 'E'|| s[pos] == 'I'|| s[pos] == 'O'|| s[pos] == 'U');

        if(min || mai){
            while (s[pos] == s[i])
            {
                i++;
                vogaisRemovidas++;
            }
        }
    }
    s[pos] = '\0';
    return vogaisRemovidas;
}

//Ex3:

int duplicaVogais(char *s){
    int len = 0, vogaisAdd = 0;

    while (s[len] != '\0'){
        len++;
    }

    for(; *s != '\0'; s++){
        int mai = (*s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U');
        int min = (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u');
    if(min || mai){
        for(int i = len++; i > 0; i--){
            s[i] = s[i-1];
            }
        vogaisAdd++;
        s++;
        }
        len++;
    }
    return vogaisAdd;
}


int main() {
    char str1[] = "Hello World";
    char str2[] = "Heeeelloo Woorld";
    char str3[] = "Hello World!";

    printf("Número de vogais em \"%s\": %d\n", str1, contaVogais(str1));
    printf("Número de vogais removidas em \"%s\": %d\n", str2, retiraVogaisRep(str2));
    printf("String após remover vogais repetidas: \"%s\"\n", str2);

    printf("Número de vogais duplicadas em \"%s\": %d\n", str3, duplicaVogais(str3));
    printf("String após duplicar vogais: \"%s\"\n", str3);

    return 0;
}