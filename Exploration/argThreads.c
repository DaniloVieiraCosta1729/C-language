#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

extern int32_t stringLength(char * texto);

int main(int argc, char const *argv[])
{
    int32_t n = stringLength(argv[1]);

    printf("A string [%s] tem comprimento: %d\n", argv[1], n);

    int32_t m = 0;

    for (size_t i = 0; i < n; i++)
    {
        m *= 10;

        m += argv[1][i] - '0';
    }

    printf("O valor eh: %d\n", m);    
    
    return 0;
}
