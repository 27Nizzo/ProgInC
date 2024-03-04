#include <stdio.h>
#include <locale.h>
#include <wchar.h> 

/*
Zodíaco:
Escreva um programa que leia uma data (dia e mês) e que imprima o símbolo do Zodíaco correspondente a essa data.

Use os símbolos do Zodíaco presentes na codificação UTF8 para a impressão. Na tabela abaixo:

Hex corresponde ao valor em hexadecimal correspondente ao signo;
O primeiro par Mês/Dia corresponde à data inicial desse signo;
O segundo par Mês/Dia corresponde à data final desse signo.
*/

int main() {
    int dia, mes;

    setlocale(LC_CTYPE, "C.UTF-8");


    if (scanf("%d%d", &dia, &mes) && ((dia >= 21 && mes == 3) && (dia <= 31 && mes == 3)))  {
            wchar_t a1 = 0x2648;
            wprintf(L"%lc\n", a1);

        } else if ((dia >= 1 && mes == 4) && (dia <= 20 && mes == 4)) {
            wchar_t a2 = 0x2648;
            wprintf(L"%lc\n", a2);
            // aries
            
        } else 
        if ((dia >= 21 && mes == 4) || (dia <= 30 && mes == 4)) {
            wchar_t b1 = 0x2649;
            wprintf(L"%lc\n", b1);

        } else if ((dia >= 1 && mes == 5) && (dia <= 20 && mes == 5)) {
            wchar_t b2 = 0x2649;
            wprintf(L"%lc\n", b2);
            // touro

        } else 
        if ((dia >= 21 && mes == 5) || (dia <= 31 && mes == 5)) {
            wchar_t c1 = 0x264a;
            wprintf(L"%lc\n", c1);

        } else if ((dia >= 1 && mes == 6) && (dia <= 20 && mes == 6)) {
            wchar_t c2 = 0x264a;
            wprintf(L"%lc\n", c2);
            // gemeos

        } else 
        if ((dia >= 21 && mes == 6) || (dia <= 30 && mes == 6)) {
            wchar_t d1 = 0x264b;
            wprintf(L"%lc\n", d1);

        } else if ((dia >= 1 && mes == 7) && (dia <= 22 && mes == 7)) {
            wchar_t d2 = 0x264b;
            wprintf(L"%lc\n", d2);
            // cancer
        } else 
        if ((dia >= 23 && mes == 7) || (dia <= 31 && mes == 7)) {
            wchar_t e1 = 0x264c;
            wprintf(L"%lc\n", e1);

        } else if ((dia >= 1 && mes == 8) && (dia <= 22 && mes == 8)) {
            wchar_t e2 = 0x264c;
            wprintf(L"%lc\n", e2);
            // leao

        } else 
        if ((dia >= 23 && mes == 8) || (dia <= 31 && mes == 8)) {
            wchar_t f1 = 0x264d;
            wprintf(L"%lc\n", f1);

        } else if ((dia >= 1 && mes == 9) && (dia <= 22 && mes == 9)) {
            wchar_t f2 = 0x264d;
            wprintf(L"%lc\n", f2);
            // virgem

        } else 
        if ((dia >= 23 && mes == 9) || (dia <= 30 && mes == 9)) {
            wchar_t g1 = 0x264e;
            wprintf(L"%lc\n", g1);

        } else if ((dia >= 1 && mes == 10) && (dia <= 22 && mes == 10)) {
            wchar_t g2 = 0x264e;
            wprintf(L"%lc\n", g2);
            // libra
        
        } else 
        if ((dia >= 23 && mes == 10) || (dia <= 31 && mes == 10)) {
            wchar_t h1 = 0x264f;
            wprintf(L"%lc\n", h1);

        } else if ((dia >= 1 && mes == 11) && (dia <= 21 && mes == 11)) {
            wchar_t h2 = 0x264f;
            wprintf(L"%lc\n", h2);
            // escorpiao
        } else 
        if ((dia >= 22 && mes == 11) || (dia <= 30 && mes == 11)) {
            wchar_t i1 = 0x2650;
            wprintf(L"%lc\n", i1);

        } else if ((dia >= 1 && mes == 12) && (dia <= 21 && mes == 12)) {
            wchar_t i2 = 0x2650;
            wprintf(L"%lc\n", i2);
            // sagitario
        } else 
        if ((dia >= 23 && mes == 12) || (dia <= 31 && mes == 12)) {
            wchar_t j1 = 0x2651;
            wprintf(L"%lc\n", j1);

        } else if ((dia >= 1 && mes == 1) && (dia <= 19 && mes == 1)) {
            wchar_t j2 = 0x2651;
            wprintf(L"%lc\n", j2);
            // capricornio
        } else 
        if ((dia >= 20 && mes == 1) || (dia <= 31 && mes == 1)) {
            wchar_t k1 = 0x2652;
            wprintf(L"%lc\n", k1);

        } else if ((dia >= 1 && mes == 2) && (dia <= 18 && mes == 2)) {
            wchar_t k2 = 0x2652;
            wprintf(L"%lc\n", k2);
            // aquario
        } else 
        if ((dia >= 19 && mes == 2) || (dia <= 28 && mes == 2)) {
            wchar_t m1 = 0x2653;
            wprintf(L"%lc\n", m1);

        } else if ((dia >= 1 && mes == 3) && (dia <= 20 && mes == 3)) {
            wchar_t m2 = 0x2653;
            wprintf(L"%lc\n", m2);
            // peixes
        } 
    
     else {
        printf("Erro.\n");
        }

    return 0;
}


