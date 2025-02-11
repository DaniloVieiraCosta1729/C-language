#include <stdio.h>

// Modify the temperature conversion program to print the table in reverse order, that is, from 300 all the way down to 0.

// Vamos usar o while dessa vez.

void table()
{
    float step = 20, initial = 300, final = 0;

    float F = initial;
    float C;

    printf("F\t\tC");

    while (F >= 0)
    {
        C = (5.0 / 9)*(F - 32.0);
        printf("\n%6.1f\t\t%6.1f", F, C);
        F -= step;
    }
}

int main()
{
    table();

    return 0;
}