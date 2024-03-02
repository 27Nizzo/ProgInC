#include <stdio.h>
#include <locale.h>
#include <wchar.h>

//#define MAX_NUM 20

// #define NUM_BASE64 64

int main()
{
    int nums[20] = {0}, s = 0;
// Array de 20 elementos onde todos os seus elementos começam por 0 e s é para o indice atual do array nums
    unsigned long long int n;    

setlocale(LC_CTYPE, "C.UTF-8");
    wchar_t simb64[64] = {      
  0x4DC0, 0x4DC1, 0x4DC2, 0x4DC3, 0x4DC4, 0x4DC5, 0x4DC6, 0x4DC7, 
  0x4DC8, 0x4DC9, 0x4DCA, 0x4DCB, 0x4DCC, 0x4DCD, 0x4DCE, 0x4DCF, 
  0x4DD0, 0x4DD1, 0x4DD2, 0x4DD3, 0x4DD4, 0x4DD5, 0x4DD6, 0x4DD7, 
  0x4DD8, 0x4DD9, 0x4DDA, 0x4DDB, 0x4DDC, 0x4DDD, 0x4DDE, 0x4DDF, 
  0x4DE0, 0x4DE1, 0x4DE2, 0x4DE3, 0x4DE4, 0x4DE5, 0x4DE6, 0x4DE7, 
  0x4DE8, 0x4DE9, 0x4DEA, 0x4DEB, 0x4DEC, 0x4DED, 0x4DEE, 0x4DEF, 
  0x4DF0, 0x4DF1, 0x4DF2, 0x4DF3, 0x4DF4, 0x4DF5, 0x4DF6, 0x4DF7, 
  0x4DF8, 0x4DF9, 0x4DFA, 0x4DFB, 0x4DFC, 0x4DFD, 0x4DFE, 0x4DFF
                            }; // lista de 64 valores 5x5 para guardar os valores dos simbolos



    if (scanf("%llu", &n) != 1) {
        wprintf(L"\n");
    // se o input for diferente de decimal dá invalido, senão passa para o proximo bloco 
    }

    while (n >= 64)
    {
        nums[s++] = n % 64;
        n /= 64;
        // loop para converter o decimal em base-64, ao calcular o resto adiciona ao array nums iterando s uma vez
        //enquanto n é maior ou igual a 64 n continua a ser divido por 64 
        
    }


    if (n > 0) 
    {
        nums[s] = n; // Isto trata do caso em que o ultimo digito é menor que 64 e ainda precisa de ser amanezado 
    
    }

    for(int i = s; i >= 0; i--) {
        wprintf(L"%lc", simb64[nums[i]]); // para ter acesso a um elemento especifico da lista simb64
          /* Este loop imprime os simboplos associados aos digitos que foram convertidos no loop do bloco
        de codigo acima
        */

        if (i > 0) {
            wprintf(L" "); // Este loop é utilizado para nao criar um espaço no ultimo simbolo gerado
        }
    }
    wprintf(L"\n");

    return 0;
}
