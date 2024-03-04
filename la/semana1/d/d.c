#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define NUM_LETTERS 26

// Frequências esperadas para cada letra em inglês
double expected_frequencies[NUM_LETTERS] = {8.4966, 2.0720, 4.5388, 3.3844, 11.1607, 1.8121, 2.4705, 3.0034, 7.5448, 0.1965, 1.1016, 5.4893, 3.0129, 6.6544, 7.1635, 3.1671, 0.1962, 7.5809, 5.7351, 6.9509, 3.6308, 1.0074, 1.2899, 0.2902, 1.7779, 0.2722};

void decifrar_cesar(char* ciphertext, int deslocamento, char* plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char char_atual = ciphertext[i];
        if (isalpha(char_atual)) {
            char ascii_offset = islower(char_atual) ? 'a' : 'A';
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
    for (int i = 0; texto[i] != '\0'; i++) {
        char char_atual = texto[i];
        if (isalpha(char_atual)) {
            char_atual = tolower(char_atual);
            contagem_de_letras[char_atual - 'a']++;
            total_de_letras++;
        }
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
    char ciphertext[1000];
    fgets(ciphertext, 1000, stdin);

    char plaintext[1000];
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

    decifrar_cesar(ciphertext, melhor_deslocamento, plaintext);
    printf("Deslocamento: %d, Texto decifrado: %s\n", melhor_deslocamento, plaintext);

    return 0;
}