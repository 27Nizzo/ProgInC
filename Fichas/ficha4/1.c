#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções Sobre Strings: 

//Ex1: Defina uma função que conta vogais: 

int contaVogais(char *s) {
    int numDeVogais = 0;
    
    for(int i = 0; s[i] != '\0'; i++) {
        if(
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
           s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
        ) {
            numDeVogais++;
        }
    }
    return numDeVogais;
}
//Ex2: Definir uma função que retira vogais repetidas em uma string, por exemplo "Estaa e umaa string coom duuuplicadoos" -> "Esta e uma string com duplicados"

int retiraVogaisRep(char *s) {
    int removidas = 0, pos = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        s[pos] = s[i];
        int min = (s[pos] == 'a' || s[pos] == 'e' || s[pos] == 'i' || s[pos] == 'o' || s[pos] == 'u');
        int mai = (s[pos] == 'A' || s[pos] == 'E' || s[pos] == 'I' || s[pos] == 'O' || s[pos] == 'U');
        
        if (min || mai) {
            while (s[pos] == s[i]) {
                i++;
                removidas++;
            }
        }

        pos++;
    }
    s[pos] = '\0';
    return removidas;
}


//Ex3: Defina uma função int duplicaVogais(char *s) que duplica todas as vogais de uma string. A função deve retornar o número de caracteres acrescentados

int duplicaVogais(char *s) {
    int vogaisAd = 0;
    int comprimento = 0; 

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
           s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            vogaisAd++;
           }
           comprimento++;
    }
    char *novaStr = malloc((comprimento + vogaisAd + 1) * sizeof(char));
    if(novaStr == NULL) {
        printf("Erro a alocar memória.\n"); 
        return -1;
    }
    int j = 0;
    for(int i = 0; i < comprimento; i++) {
        novaStr[j] = s[i];
        j++;
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || 
           s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            novaStr[j] = s[i];
            j++;
           }
    }
    novaStr[j] = '\0';

    strcpy(s, novaStr);
    free(novaStr);
    return vogaisAd;
}


int main() {
    char str[] = "Estaa e umaa string coom duuuplicadoos";
    int qVogais = contaVogais(str);
    printf("Existem %d vogais nesta string: (%s)\n", qVogais, str);

    int vRemovidas = retiraVogaisRep(str);
    printf("Quantidade de vogais removidas: %d\n", vRemovidas);

    int vogaisAdicionadas = duplicaVogais(str);
    printf("Vogais duplicadas: %d\n", vogaisAdicionadas);
    
    
    return 0;
}

