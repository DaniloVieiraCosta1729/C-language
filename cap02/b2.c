#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FREE 1
#define NOTFREE 0

static volatile int freeState = FREE;

char * binario(int n);

int main(int argc, char const *argv[])
{
    int8_t x = 0b10101;
    int8_t y = 0b01010;

    char* a = binario(x^y);
    printf("x^y = %s\n", a);
    char* b = binario(x | y);
    printf("x | y = %s\n", b);

    char * z;
    z = binario(0b10110);
    printf("%d em binario é %s\n", 0b10110, z);

    if (freeState)
    {
        free(z);
    }
    
    free(a);
    free(b);

    return 0;
}

char * binario(int n)
{
    // vamos fazer de um jeito diferente do convencional
    char * binario = (char *)malloc(64);
    float log_prep = (float)n;
    int b_signed = (*(int *)&log_prep) >> 23;
    int sinal = b_signed >> 8;
    int integer_log = b_signed & 0b011111111;
    integer_log -= 127;

    if (integer_log > 64)
    {
        freeState = NOTFREE;
        return "erro, log > 64\n";
    }

    if (sinal)
    {
        0[binario] = '-';
        for (size_t i = 0; i <= integer_log; i++)
        {
            *(binario + i + 1) = ((n & (1 << (integer_log - i))) >> (integer_log - i)) + '0';
        }

        binario[integer_log + 2] = '\0';

        return binario;
    }

    for (size_t i = 0; i <= integer_log; i++)
    {
        *(binario + i) = ((n & (1 << (integer_log - i))) >> (integer_log - i)) + '0';
    }

    (integer_log + 1)[binario] = '\0';
    
    return binario;

}
