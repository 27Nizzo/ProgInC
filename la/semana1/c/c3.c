#include <stdio.h>
#include <math.h>

/*

Números de vírgula flutuante

Escreva um programa que converta números na norma de vírgula flutuante para decimal.

Consulte a informação sobre a representação de informação em vírgula flutuante:

Na página 36 do livro editado pela Uminho (Tabela 3.4 e eqs. 3.6 e 3.8);
Na página 9 dos apontamentos em Português sobre a representação de números (veja com atenção a página 11).
Restrições
Input
O seu programa deverá ler:

Uma linha com um número N que corresponde ao número de linhas que deverá ler
N linhas com:
Um inteiro com o número de bits do expoente E
Um inteiro com o número de bits da mantissa M
Uma string com 1 + E + M caracteres com a codificação do número em binário
Output
O seu programa deverá imprimir o valor usando o formato %lg. Deverá efetuar os cálculos para a conversão usando double.

Exemplo de input
10
3 4 01110000
3 4 11110000
3 4 11111111
3 4 11111011
3 4 11101011
3 4 11100000
3 4 10000000
3 4 00000000
3 4 00000001
3 4 00001011
Exemplo de output
+Infinity
-Infinity
NaN
NaN
-13.5
-8
-0
0
0.015625
0.171875

*/



int main() {

    int n,e,m, bias = 127, r[n];
    char binario[100];

    // e -> Expoente; m -> Mantissa; bin -> nº Binário

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d %s", &e, &m, binario);
        
        if ((e < 1 || e > 5) || (m < 1 || m > 7)){
            return 1;
        } else {

    char sinal = binario[0];
    double mantissa = 0.0;

    for (int j = 2; j <= 24; j++){
        mantissa += (binario[j] - '0') * pow(2, 1 - j);
    }

    // calculo da formula: (-1)^S * 1.M * 2^(E-bias)

    if(sinal == '0') {
        r[i] = pow(-1, 0) * (1 + mantissa) * pow(2, e - bias);

    } else if(sinal == '1') {
        r[i] = pow(-1, -1) * (1 + mantissa) * pow(2, e - bias);

    } else {
        return 1;
    }

        }

// bloco para dar print a aos valores : (check)
   
    }
     for(int i = 0; i < n; i++) {
        printf("Resultado: %d\n", r[i]);
    }
    

    return 0;
}