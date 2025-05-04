#include <stdio.h>
#include <limits.h>

int main()
{

    // Vamos testar a soma que é feita pelo computador.

    long int a = INT_MAX;

    printf("%ld",a + 4000);

    // O resultado mostrado foi -2147479649
    // Ou seja, a soma de dois números positivos é igual à um número negativo!
    // Isso acontece porque a soma que é realizada por um computador não é a soma sobre os reais com a qual estamos acostumados, mas sim uma soma
    // sobre o anel de inteiros módulo 2^n, em que n é o tamanho do tipo de dado que estamos usando, 
    // ex.: a soma de int de 32 bits é sobre o anel de inteiros mod 2^32

    return 0;
}