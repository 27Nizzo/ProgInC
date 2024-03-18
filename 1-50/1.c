#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros 
inteiros terminada com o n´umero 0 e imprime no ecran o maior elemento da sequˆencia.
*/

int ex1 () {
    int n; 
    scanf("%d", &n);
    int max = n;

    while (n != 0)
    {
        scanf("%d", &n);
        if(n > max) {
            max = n;
        } 
    }
    printf("%d\n", max);
    return max; 
}

/*2) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros
 inteiros terminada com o n´umero 0 e imprime no ecran a m´edia da sequˆencia.
*/

float ex2() {
    float num, soma;
    int numElems = 0;
    float media;

    scanf("%f", &num);
    soma = num;

     do {
        scanf("%f", &num);
        numElems++;
        soma += num;
    } while(num != 0);

    media = soma/numElems;
    printf("%f", media);
    return media;
}
/*3) Defina um programa que lˆe (usando a fun¸c˜ao scanf uma sequˆencia de n´umeros inteiros ter-
minada com o n´umero 0 e imprime no ecran o segundo maior elemento.*/
int ex3() {

    int maior, segundoMaior, num;
    scanf("%d", &num);
    maior = num; 
    if(num > maior) {
        segundoMaior = maior;
        maior = num; 
    } else {
        segundoMaior = num;
    }

    while (num != 0)
    {
        scanf("%d", &num);
        if(num != 0 && num > segundoMaior) {
            if(num > maior) {
                segundoMaior = maior;
                maior = num;
            } else {
                segundoMaior = num;
            }
        }
    }

        printf("%d\n", segundoMaior);
        return segundoMaior;
}

/*4) Defina uma fun¸c˜ao int bitsUm (unsigned int n) que calcula o n´umero de bits iguais a 1
usados na representa¸c˜ao bin´aria de um dado n´umero n.*/

int bistUm(unsigned int n) {
    int uns = 0;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            uns++;
        }
    }
    return uns;
}

/*5) Defina uma fun¸c˜ao int trailingZ (unsigned int n) que calcula o n´umero de bits a 0 no
final da representa¸c˜ao bin´aria de um n´umero*/

int trailingZ(unsigned int n) {
    int zeros = 0;

    for(int i = n; i > 0; i /= 2) {
        if(i % 2 == 0) {
            zeros++;
        }
    }

    return zeros; 
}

/*6) Definir a funçao qDig(unsigned int n) que calcula o numero de digitos necessarios para escrever o inteiro n em base decimal
Exemplo: qDig(440) deve retornar 3:*/

int qDig(unsigned int n) {
    int x = 0; 
    int resto = 0;

    for(int i = 1; resto != n; i *= 10) {
        resto = n % i;
        if(resto != n) {
            x++;
        }
    }
    return x;
}

/*7) Apresente a definiç~ao da funçao pre-defenida em C char *strcat(char s1[], char s2[]) que concatena a string s2 a s1, retornanado o endereço da primeira*/

char *mystrcat(char s1[], char s2[]) {
    int p;
    for (p = 0; s1[p] != '\0'; p++); // Encontra o final de s1
    
    int i;
    for (i = 0; s2[i] != '\0'; i++) { // Concatena s2 em s1
        s1[p + i] = s2[i];
    }
    s1[p + i] = '\0'; // Adiciona o caractere nulo ao final de s1
    
    return s1;
}

/*8) Definiçao da funçao pre-definida strcpy que copia a string source para dest retornando o valor da ultima*/

char *mystrcpy(char *dest, char *source[]) {
    for(int i = 0; source[i] != '\0'; i++) {
        dest[i] = '\0';
    }
    return dest;
}

/*9) Definiçao da funçao pre-definida strcmp que compara duas strigs*/
char *mystrcmp(char s1[], char s2[]) {
    int i;
    for(i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return s1[i] - s2[i]; 
}

/*10) Definiçao da funçao pre-definida strstr que determina a posiçao onde a string s2 ocorre na string s1. Retorna NULL caso s2 nao exista em s1 */

int *mystrstr(char s1[], char s2[]) {
    char *res = NULL; 
    int i, j;
    if(s2[0] == '\0') {
        return s1;
    }
    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0' && s1[j] == s1[i+j]; j++);
        if(s2[j] == '\0')
        res = s1 + i;
    }
    return res;
    
}

/*11) Definiçao da funçao strrev que inverte uma string*/

void strrev(char s[]) {
    int size;
    char tmp;
    for(size = 0; s[size] != '\0'; size++);
    for(int i = 0; i < size/2; i++) {
        tmp = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = tmp;
    }
}

/*12) Definiçao de strnoV que retira todas as vogais de uma string  */

void strnoV(char t[]) {
    int pos = 0; 
    for(int i = 0; t[i] !='\0'; i++) {
        if(strchr("aeiouAEIOU", t[i]) == NULL) {
            t[pos++] = t [i];
        }
    }
    t[pos] = '\0';
}

/*13) Definiçao da funçao truncW que dado um texto t com varias palavras  e um inteiro n, trunca todas as palavras de forma a terem o maximo n caracteres. */

void truncW(char t[], int n) {
    int i, adi, pos;
    for(i = 0, pos = 0, adi = 0; t[i] != '\0'; i++) {
        if(t[i] == ' ') {
            adi = 0; 
            t[pos++] == t[i];
            adi++;
        }
    }
    t[pos] = '\0';
}

/*14) Definiçao da funcao charMaisFreq que determina o char mais frequente em uma string*/

char maisMaisFreq(char s[]) {
    char maisFreq = '0';
    int i, j, freq = 0, f;
    for(i = 0; s[i] != '\0'; i++) {
        f = 0;
        for(j = 0; s[j] != '\0'; j++) {
            if(s[j] == s[i]) f++;
        }
        if(f > freq) {
            freq = f;
            maisFreq = s[i];
        }
    }
    return maisFreq;
}

/*15) Definiçao da funçao iguaisConsecutivos que dada uma string s calcula o comprimento da maior sub-string com caracteres iguais. */

int iguaisConsecutivos(char s[]) {
    int i, j;
    int seq = 0, n;

    for(i = 0, n = 0; s[i] != '\0'; i++, n = 0) {
        for(j = i; s[j] == s[i] && s[j] != '\0'; j++) n++;
        if (n > seq) {
            seq = n;
        }
    } 
    return seq;  
}


int main() {
    char texto[] = "Hello WOrld";
    strnoV(texto);
    printf("%s\n", texto);
    
    return 0;
}

