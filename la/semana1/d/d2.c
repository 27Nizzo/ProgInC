#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define NUM_LETTERS 26

// Frequências esperadas para cada letra em inglês
double expected_frequencies[NUM_LETTERS] = {         8.4966, 2.0720, 4.5388, 3.3844, 
                                                     11.1607, 1.8121, 2.4705, 3.0034, 
/*A - Z*/                                            7.5448, 0.1965, 1.1016, 5.4893, 
                                                     3.0129, 6.6544, 7.1635, 3.1671, 
                                                     0.1962, 7.5809, 5.7351, 6.9509, 
                                                     3.6308, 1.0074, 1.2899, 0.2902, 
                                                     1.7779, 0.2722                     };


void decifrar_cesar(char* ciphertext, int deslocamento, char* plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char char_atual = ciphertext[i];
        if (isalpha(char_atual)) {
            char ascii_offset;
            if (islower(char_atual)) {
                ascii_offset = 'a';
            } else {
                ascii_offset = 'A';
            }
            char decrypted_char = ((char_atual - ascii_offset - deslocamento + NUM_LETTERS) % NUM_LETTERS) + ascii_offset;
            plaintext[i] = decrypted_char;
        } else {
            plaintext[i] = char_atual;
        }
    }
    plaintext[strlen(ciphertext)] = '\0';  // termina a string
}

double calcular_soma_das_diferencas_quadradas(char* texto) {
    int contagem_de_letras[NUM_LETTERS] = {0};
    int total_de_letras = 0;

    // Conta a frequência de cada letra no texto
    char* ptr = texto;
    while (*ptr != '\0') {
        if (isalpha(*ptr)) {
            char char_atual = tolower(*ptr);
            contagem_de_letras[char_atual - 'a']++;
            total_de_letras++;
        }
        ptr++;
    }
    
    // Calcula a soma dos quadrados das diferenças
    double soma_das_diferencas_quadradas = 0.0;
    for (int i = 0; i < NUM_LETTERS; i++) {
        double observed_frequency = (double)contagem_de_letras[i] / total_de_letras * 100;
        double difference = expected_frequencies[i] - observed_frequency;
        soma_das_diferencas_quadradas += difference * difference / expected_frequencies[i];
    }

    return soma_das_diferencas_quadradas;
}

int main() {
    char ciphertext[10000];
    fgets(ciphertext, 10000, stdin);
    if (ciphertext[strlen(ciphertext) - 1] == '\n') {
    ciphertext[strlen(ciphertext) - 1] = '\0';
    }



    char plaintext[10000];
    double min_soma_das_diferencas_quadradas = INFINITY;
    int melhor_deslocamento;

    for (int deslocamento = 0; deslocamento < NUM_LETTERS; deslocamento++) {
        decifrar_cesar(ciphertext, deslocamento, plaintext);
        double soma_das_diferencas_quadradas = calcular_soma_das_diferencas_quadradas(plaintext);
        if (soma_das_diferencas_quadradas < min_soma_das_diferencas_quadradas) {
            min_soma_das_diferencas_quadradas = soma_das_diferencas_quadradas;
            melhor_deslocamento = deslocamento;
        }
    }

    int deslocamento_correto = (NUM_LETTERS - melhor_deslocamento) % NUM_LETTERS;
    decifrar_cesar(ciphertext, melhor_deslocamento, plaintext);
    printf("%d %s\n", deslocamento_correto, plaintext);

    return 0;
}

