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


void decifrar_cesar(char* textoCifrado, int deslocamento, char* texto) {

    for (int i = 0; textoCifrado[i] != '\0'; i++) {
  // este loop vai iterar sobre cada caractere no texto cifrado até o final da string
      
        char char_atual = textoCifrado[i];
        // Obtem o char atual no texto cifrado

        // Este if verifica se o char é uma letra do alfabeto
        if (isalpha(char_atual)) {
            char ascii_offset;
            // Este if define o offset ASCII com base em se o caracter é inusculo ou maiúsculo 
            if (islower(char_atual)) {
                ascii_offset = 'a';
            } else {
                ascii_offset = 'A';
            }
            // decifra o char usando a citra de césar com o deslocamento fornecido
            char charDecriptado = ((char_atual - ascii_offset - deslocamento + NUM_LETTERS) % NUM_LETTERS) + ascii_offset;
            // armaneza o char decriptado no array 'texto'
            texto[i] = charDecriptado;
        } else {
          // Se o char não for uma letra, mantém o mesmo char no array 'texto'
            texto[i] = char_atual;
        }
    }
    
    texto[strlen(textoCifrado)] = '\0';  // termina a string
}

double calcular_soma_das_diferencas_quadradas(char* texto) {
  // Inicializa um array para armanezar a contagem de cada letra do alfabeto 
    int contagem_de_letras[NUM_LETTERS] = {0};
  
  // Inici a variável para armanezar o total de letras no texto
    int letrasTotal = 0;

    // Conta a frequência de cada letra no texto
    char* p = texto;
    while (*p != '\0') {
      // Este if verifica se o char é uma letra do alfabeto 
        if (isalpha(*p)) {
          // Converte o char para minusculo e incrementa na contagem
            char char_atual = tolower(*p);
            contagem_de_letras[char_atual - 'a']++;
            letrasTotal++;
        }
        // o pointer muda para o proximo char
        p++;
    }
    
    // Calcula a soma dos quadrados das diferenças
    double soma_das_diferencas_quadradas = 0.0;
    
    for (int i = 0; i < NUM_LETTERS; i++) {
        double observed_frequency = (double)contagem_de_letras[i] / letrasTotal * 100;
        double diff = expected_frequencies[i] - observed_frequency;
        soma_das_diferencas_quadradas += diff * diff / expected_frequencies[i];
    }

    return soma_das_diferencas_quadradas;
}

int main() {
    char textoCifrado[10000];


   if (fgets(textoCifrado, 10000, stdin) == NULL) {
        return 1;
    }

    if (textoCifrado[strlen(textoCifrado) - 1] == '\n') {
    textoCifrado[strlen(textoCifrado) - 1] = '\0';
    }



    char texto[10000];
    double min_soma_das_diferencas_quadradas = INFINITY;
    int bestDeslocamento = 0;

    for (int deslocamento = 0; deslocamento < NUM_LETTERS; deslocamento++) {
        decifrar_cesar(textoCifrado, deslocamento, texto);
        double soma_das_diferencas_quadradas = calcular_soma_das_diferencas_quadradas(texto);
        if (soma_das_diferencas_quadradas < min_soma_das_diferencas_quadradas) {
            min_soma_das_diferencas_quadradas = soma_das_diferencas_quadradas;
            bestDeslocamento = deslocamento;
        }
    }

    int mDesloca = (NUM_LETTERS - bestDeslocamento) % NUM_LETTERS;
    decifrar_cesar(textoCifrado, bestDeslocamento, texto);
    printf("%d %s\n", mDesloca, texto);

    return 0;
}

