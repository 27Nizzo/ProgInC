#include <stdio.h>
#include <math.h>

#define BINARIO_SIZE 15

double todob(const char *b) {
  double decimal = 0.0;
  double potencia = 0.5;

  for (int i = 0; b[i] != '\0'; i++) {
    if (b[i] == '1') {
      decimal += potencia;
    }
    potencia *= 0.5;
  }

  return decimal;
}

int main() {
  int linhas;

  // Leitura segura do número de linhas
  if (scanf("%d", &linhas) != 1) {
    return 1;
  }

  // Loop para processar cada linha
  for (int j = 0; j < linhas; j++) {
    char binario[BINARIO_SIZE];
    int e, m;

    // Leitura segura dos dados
    if (scanf("%d %d %s", &e, &m, binario) != 3) {
      return 1;
    }

    // Validação dos valores de e e m
    if (!(1 <= e && e <= 5 && m <= 7 && 1 <= m)) {
      printf("Valores de e e m inválidos.\n");
      continue; // Pular para a próxima iteração
    }

    // Cálculo do expoente
    int expoente = 0;
    for (int j = 1; j < e + 1; j++) {
      expoente += (binario[j] - '0') * (int)pow(2, e - j);
    }
    expoente -= (int)pow(2, e - 1) - 1; // Correção do viés

    // Cálculo da mantissa
    double mantissa = todob(binario + e + 1);

    // Cálculo do valor final
    if (expoente == (int)pow(2, e - 1) - 1) {
      if (mantissa > 1.0) {
        // NaN
        printf("NaN\n");
      } else if (binario[0] == '1') {
        // -Infinity
        printf("-Infinity\n");
      } else {
        // +Infinity
        printf("+Infinity\n");
      }
    } else {
      double resultado = pow(-1, binario[0] - '0') * mantissa * pow(2, expoente);
      printf("%lg\n", resultado);
    }
  }

  return 0;
}
