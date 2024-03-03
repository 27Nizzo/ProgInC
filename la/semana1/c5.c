#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída
#include <string.h> // Inclui a biblioteca de manipulação de strings
#include <math.h> // Inclui a biblioteca matemática

#define MAXN 100 // Define o número máximo de entradas que o programa pode manipular

int main() { // Início da função principal
    int n; // Declaração da variável que armazena o número de entradas
    if(scanf("%d", &n) != 1) { return 1; } // Lê o número de entradas do usuário

    char bin[MAXN][15]; // Declaração do array que armazena as strings binárias
    int e[MAXN], m[MAXN]; // Declaração dos arrays que armazenam os valores de 'e' e 'm'
    double results[MAXN]; // Declaração do array que armazena os resultados
    char types[MAXN][10]; // Declaração do array que armazena os tipos de resultados

    for(int j = 0; j < n; j++) { // Loop para ler as entradas do usuário
        if(scanf("%d%d%s", &e[j], &m[j], bin[j]) != 3) { return 1; } // Lê 'e', 'm' e a string binária do usuário
    }

    for(int j = 0; j < n; j++) { // Loop para processar cada entrada
        if(1 <= e[j] && e[j] <=5 && m[j] <= 7 && 1 <= m[j]) { // Verifica se 'e' e 'm' estão dentro dos limites especificados
            int excesso = pow(2, e[j]-1) - 1; // Calcula o excesso
            int expp = 0; // Inicializa a variável que armazena o expoente
            for(int i = e[j]+1; i >= 1; i--) { // Loop para calcular o expoente
                if(bin[j][i] == '1')  { expp = expp + pow(2, e[j]-i); } // Se o caractere na posição 'i' é '1', adiciona 2^(e[j]-i) ao expoente
            }

            int r = -1; // Inicializa a variável que armazena o expoente para o cálculo da mantissa
            double man = 0; // Inicializa a variável que armazena a mantissa
            for(int i = 0; i < m[j]; i++) { // Loop para calcular a mantissa
                if(bin[j][1+e[j]+i] == '1') man = man + pow(2, r); // Se o caractere na posição '1+e[j]+i' é '1', adiciona 2^r à mantissa
                r--; // Decrementa o expoente
            }

            int allOne = 1; // Inicializa a variável que verifica se todos os caracteres são '1'
            for(int i = 1; i <= e[j]; i++) { // Loop para verificar se todos os caracteres são '1'
                if(bin[j][i] != '1') { allOne = 0; break; } // Se o caractere na posição 'i' não é '1', define allOne como 0 e sai do loop
            }

            int allZero = 1; // Inicializa a variável que verifica se todos os caracteres são '0'
            for(int i = e[j]+1; i <= e[j]+m[j]; i++) { // Loop para verificar se todos os caracteres são '0'
                if(bin[j][i] != '0') { allZero = 0; break; } // Se o caractere na posição 'i' não é '0', define allZero como 0 e sai do loop
            }

            if(allOne) { // Se todos os caracteres são '1'
                if(allZero) { // Se todos os caracteres são '0'
                    strcpy(types[j], bin[j][0] == '0' ? "+Infinity" : "-Infinity"); // Se o primeiro caractere é '0', define o tipo como "+Infinity", caso contrário, define como "-Infinity"
                } else {
                    strcpy(types[j], "NaN"); // Se nem todos os caracteres são '0', define o tipo como "NaN"
                }
            } else if(bin[j][1] == '0') { // Se o segundo caractere é '0'
                if(allZero) { // Se todos os caracteres são '0'
                    strcpy(types[j], bin[j][0] == '0' ? "0" : "-0"); // Se o primeiro caractere é '0', define o tipo como "0", caso contrário, define como "-0"
                } else {
                    results[j] = pow(-1, bin[j][0]) * man * pow(2, 1-excesso); // Se nem todos os caracteres são '0', calcula o resultado e define o tipo como "number"
                    strcpy(types[j], "number");
                }
            } else {
                results[j] = pow(-1, bin[j][0]) * (1+man) * pow(2, expp-excesso); // Calcula o resultado e define o tipo como "number"
                strcpy(types[j], "number");
            }
        }
    }

    for(int j = 0; j < n; j++) { // Loop para imprimir os resultados
        if(strcmp(types[j], "number") == 0) { // Se o tipo é "number"
            printf("%lg\n", results[j]); // Imprime o resultado
        } else {
            printf("%s\n", types[j]); // Se o tipo não é "number", imprime o tipo
        }
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
