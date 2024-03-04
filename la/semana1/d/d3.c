#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define NUM_LETTERS 26

// Frequências esperadas para cada letra em inglês
double expected_frequencies[NUM_LETTERS] = {8.4966, 2.0720, 4.5388, 3.3844, 11.1607, 1.8121, 2.4705, 3.0034, 7.5448, 0.1965, 1.1016, 5.4893, 3.0129, 6.6544, 7.1635, 3.1671, 0.1962, 7.5809, 5.7351, 6.9509, 3.6308, 1.0074, 1.2899, 0.2902, 1.7779, 0.2722};

void decifrar_cesar(char* texto_cifrado, int deslocamento, char* texto_plano) {
    int i = 0;
    while (texto_cifrado[i] != '\0') {
        char caractere_atual = texto_cifrado[i];
        if (isalpha(caractere_atual)) {
            int deslocamento_ajustado = (caractere_atual - (islower(caractere_atual) ? 'a' : 'A') - deslocamento + 26) % 26;
            texto_plano[i] = deslocamento_ajustado + (islower(caractere_atual) ? 'a' : 'A');
        } else {
            texto_plano[i] = caractere_atual;
        }
        i++;
    }
    texto_plano[strlen(texto_cifrado)] = '\0';
}

double calcular_soma_das_diferencas_quadradas(char* texto) {
  // Cria um dicionário para armazenar as frequências das letras
  int letter_counts[NUM_LETTERS] = {0};
  int total_letters = 0;
  for (int i = 0; texto[i] != '\0'; i++) {
    char char_atual = texto[i];
    if (isalpha(char_atual)) {
      letter_counts[tolower(char_atual) - 'a']++;
      total_letters++;
    }
  }

  // Calcula a soma das diferenças quadradas
  double soma_das_diferencas_quadradas = 0.0;
  for (int i = 0; i < NUM_LETTERS; i++) {
    double observed_frequency = (double)letter_counts[i] / total_letters * 100;
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
  int melhor_deslocamento = 0;

  // Encontra o melhor deslocamento
  for (int deslocamento = 0; deslocamento < NUM_LETTERS; deslocamento++) {
    decifrar_cesar(ciphertext, deslocamento,plaintext);
    double soma_diferencas = calcular_soma_das_diferencas_quadradas(plaintext);

    if (soma_diferencas < min_soma_das_diferencas_quadradas) {
      min_soma_das_diferencas_quadradas = soma_diferencas;
      melhor_deslocamento = deslocamento;
    }
  }

  // Imprime o resultado
  decifrar_cesar(ciphertext, melhor_deslocamento, plaintext);
  printf("Melhor deslocamento: %d\nTexto decifrado: %s\n", melhor_deslocamento, plaintext);

  return 0;
}
