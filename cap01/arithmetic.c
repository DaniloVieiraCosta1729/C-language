#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <complex.h>

int main()
{

    // Vamos testar a soma que é feita pelo computador.

    long int a = INT_MAX;

    long double b = LDBL_MAX;

    printf("%ld \n",a + 4000);
    printf("b = %Lg \n", b);

    double _Complex c = 0.0 + 1.0*I;
    double _Complex d = 2.0 + 1.0*I;
    double _Complex e = c*d;

    printf("c = %.2f + %.2fi\n", creal(c), cimag(c));
    printf("d = %.2f + %.2fi\n", creal(d), cimag(d));
    printf("A rotacao do vetor (2, 1) em 90 graus eh (%.2f , %.2f)", creal(e), cimag(e));

    // O resultado mostrado foi -2147479649
    // Ou seja, a soma de dois números positivos é igual à um número negativo!
    // Isso acontece porque a soma que é realizada por um computador não é a soma sobre os reais com a qual estamos acostumados, mas sim uma soma
    // sobre o anel de inteiros módulo 2^n, em que n é o tamanho do tipo de dado que estamos usando, 
    // ex.: a soma de int de 32 bits é sobre o anel de inteiros mod 2^32

    return 0;
}