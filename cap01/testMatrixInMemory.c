#include <stdio.h>
int main(int argc, char const *argv[])
{
    int matrix[3][3] = {{1,4,6},{8,10,12},{14,16,18}};

    int * ptr = &matrix[0][0];

    printf("*ptr = %d\n", *ptr);
    printf("*ptr + 1 = %d\n", *(ptr + 1));
    printf("*ptr + 2 = %d\n", *(ptr + 2));
    printf("*ptr + 3 = %d\n", *(ptr + 3));

    printf("*ptr + 8 = %d\n", *(ptr + 8)); // Então é isso. Uma matrix é guardada exatamente como um array em memória. Existe uma distância de 4 bytes entre o início de um elemento e o início do outro. A ordem é m[0][0], m[1,0], ..., m[8,9], m[9,9]

    return 0;
}
