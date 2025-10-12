#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double numeros[5] = {
        [0] = 9.0,
        [3] = 0.00007,
        [1] = 2.9,
        [4] =3.E+25 
    };

    for (size_t i = 0; i < 5; ++i)
    {
        printf("O elemento %zu eh %g, \tseu quadrado eh %g\n", i, *(numeros + i), i[numeros] * numeros[i]);
    }
    
    
    return EXIT_SUCCESS; // EXIT_SUCCESS = 0, é definido em stdlib.h
}
