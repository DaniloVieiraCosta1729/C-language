#include <stdio.h>
#include <immintrin.h>

extern int stringLength(char * texto); // "\Exploration\stringSize.o"

int main(int argc, char const *argv[])
{
    int x = 2;
    int y = stringLength(argv[1]);

    __m256 a = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
    __m256 b = _mm256_set_ps(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0);

    __m256 c = _mm256_sub_ps(a,b);

    double * d = (double *)&c;

    printf(">>> 2 + %d = %d\n", y, y + x);

    printf("A subtracao dos 16 primeiros impares pelos 16 pares eh:\n");

    return 0;
}
