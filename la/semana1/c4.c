#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BINARIO_SIZE 15  

int main() {
  int n;
  scanf("%d", &n);

  double *resultados = (double *)malloc(n * sizeof(double));
  if (resultados == NULL) {
    return 1; 
  }

  for (int i = 0; i < n; i++) {
    int e, m;
    char binario[BINARIO_SIZE];  

    scanf("%d %d %s", &e, &m, binario);

    // Cálculo do expoente
    int expoente = 0;
    for (int j = 1; j < e + 1; j++) {
      expoente += (binario[j] - '0') * pow(2, e - j);
    }
    expoente -= (1 << (e - 1)) - 1; 

    // Cálculo da mantissa
    double mantissa = 0.0;
    for (int j = e + 1; j < e + m + 1; j++) {
      mantissa += (binario[j] - '0') * pow(2, -(j - e));
    }
    mantissa += 1.0;

    // Cálculo do valor final
    if (expoente == (1 << (e - 1)) - 1) {
      if (mantissa > 1.0) {
        // NaN
        resultados[i] = NAN;
      } else if (binario[0] == '1') {
        // -Infinity
        resultados[i] = -INFINITY;
      } else {
        // +Infinity
        resultados[i] = +INFINITY;
      }
    } else {
      resultados[i] = pow(-1, binario[0] - '0') * mantissa * pow(2, expoente);
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%lg\n", resultados[i]);
  }

  free(resultados); 
  return 0;
}
