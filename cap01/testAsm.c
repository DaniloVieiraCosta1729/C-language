#include <stdio.h>

int soma(int x, int y)
{
    return x + y;
}

int main(int argc, char const *argv[])
{
    int a = 10000, b = 3000;

    printf("Soma: %d\n", soma(a, b));
    return 0;
}
