#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

extern int32_t stringLength(char * texto);

int main(int argc, char const *argv[])
{
    int32_t n = stringLength(argv[1]);

    printf("A string [%s] tem comprimento: %d\n", argv[1], n);
    
    return 0;
}
