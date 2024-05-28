#include <stdio.h>
#include <wchar.h>
#include <locale.h>

wchar_t highestCard(wchar_t hand[]){
    size_t i; 
    wchar_t maior = hand[0];
    for (i = 1; i < wcslen(hand); i++){
        if (hand[i] % 16 > maior % 16){
            maior = hand[i];
        }
        else if (hand[i] % 16 == maior % 16){
            if (hand[i]  > maior){
                maior = hand[i];
            }
        }
    }
    return maior;
}

int isNext(wchar_t carta1, wchar_t carta2){
    int r = 0;
    if (carta1 % 16 + 1 == carta2 % 16){
        r = 1;
    }
    return r; 
}

int combination(wchar_t mao[]){
    int r = 0, i;
    int length = wcslen(mao);
    for (i = 0; i < length - 1; i++){
        if (mao[i] % 16 != mao[i+1] % 16){
            if (isNext(mao[i],mao[i+1])) {
                if (r == 0 || r == 2) {
                    r = 2;
                } else {
                    r = -1;
                }
            }
        }
        else {
            if (i < length - 2 && isNext(mao[i+1],mao[i+2])) {
                if (r == 0 || r == 3) {
                    r = 3;
                } else {
                    r = -1;
                }
            }
            else {
                if (r == 0 || r == 1) {
                    r = 1;
                } else {
                    r = -1;
                }
            }
        } 
    }
    return r;    
}

void sortHand(wchar_t hand[], int length)  {
    int i, j;
    wchar_t temp;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (hand[i] % 16 > hand[j] % 16 || (hand[i] % 16 == hand[j] % 16 && hand[i] > hand[j])) {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int main(){
    setlocale(LC_CTYPE, "");
    
    int j=0,n=0;
    wchar_t hand[14] = {0};
    wscanf(L"%ld",&n);
    while (j < n){
        wscanf(L"%ls", &hand);
        int length = wcslen(hand); 
        sortHand(hand, length); 
        int tipo_combinacao = combination(hand);
        int highest = highestCard(hand);
        wprintf(L"\n");
        switch (tipo_combinacao){   
        case -1:
            wprintf(L"Nada!\0");
            break;
        case 0:
            wprintf(L"Nada!\0");
            break;
        case 1:
            wprintf(L"conjunto com %d cartas onde a carta mais alta é %lc\0",length,highest);
            break;
        case 2:
            wprintf(L"sequencia com %d cartas onde a carta mais alta é %lc\0",length,highest);
            break;
        case 3:
            wprintf(L"dupla sequencia com %d cartas onde a carta mais alta é %lc\0",length,highest);
            break;
        default:
            wprintf(L"Tipo de combinacao desconhecido.\0");
            break;
        }
        j++;
    }

    return 0;
}
