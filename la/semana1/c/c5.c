#include <stdio.h>
#include <math.h>

/* Função calculo, calcula: 
- Calcula o valor de excesso usando a fórmula (int)(pow(2, E-1)) - 1.
- Calcula o valor de frac e expoente com base na string str.
- Com base nos valores de expoente e frac, calcula o valor de num e imprime o resultado.
*/
void calculo(int numBitsExpoente, int numBitsMantissa, char* cadeiaStr) {
    // claculo do execesso do expoente 
    int excesso = pow(2, numBitsExpoente) / 2 - 1;
    double frac = 0, num = 0;
    int expoente = 0;

    // Calcula a parte fracionária:
    for (int j = numBitsExpoente+numBitsMantissa; j >= numBitsExpoente+1; j--){
        if (cadeiaStr[j] == '1') frac += pow(2,numBitsExpoente-j);
    }
    // calcula o expoente 
    for (int k = numBitsExpoente; k > 0; k--){
        if (cadeiaStr[k] == '1') expoente += pow(2,numBitsExpoente-k);
    }
     expoente = expoente - excesso;

// Verifica casos especiais: 
    if (expoente == -excesso) {
        expoente += 1;
        if (frac == 0) {
            num = 0;
            if (cadeiaStr[0] == '1') printf("-0\n");
            else printf("0\n");
        }
        else {
            num = frac * pow(2, expoente);
            if (cadeiaStr[0] == '1') num *= -1;
            printf("%lg\n",num);
        }
    } 

    else if (expoente == pow(2, numBitsExpoente - 1)) {
        if (frac == 0){
            if (cadeiaStr[0] == '1') printf("-Infinity\n");
            else printf("+Infinity\n");
        }
        else printf("NaN\n");
    } 

    else {
        num = (1 + frac)*pow(2,expoente);
        if (cadeiaStr[0] == '1') num *= -1;
        printf("%lg\n",num);
    }
}

int main() {
    int n = 0;
    if (scanf("%d",&n) == 1){
        for (int i = 0;i < n;i++){
            int numBitsMantissa = 0;
            int numBitsExpoente = 0;
            char cadeiaStr[15];
            
            if (scanf("%d %d %s", &numBitsExpoente, &numBitsMantissa, cadeiaStr) == 3){
                if ((numBitsExpoente >= 1 && numBitsExpoente <= 5) && (numBitsMantissa >= 1 && numBitsMantissa <= 7)) {
                    calculo(numBitsExpoente, numBitsMantissa, cadeiaStr);
                }
            } else {
                return 1;
            }
        }
    }
    return 0;
}
