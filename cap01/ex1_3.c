#include <stdio.h>

// Exercise 1-3 Modifythe temperature converter to print a header above the table.

void tableFtoC()
{
    // Como já fizemos esse conversor com o "for" e de forma recursiva também, vamos fazê-lo usando o while dessa vez.

    float lowest, highest, step; // chamei de step o que antes eu estava chamando de rate. 

    lowest = 0;
    highest = 300;
    step = 20;

    float F, C;

    F = lowest;

    printf("\t F \t");
    printf("C \t\n");

    while (F <= highest)
    {

        C = (5.0/9)*(F - 32.0);
        printf("\t %4.1f \t %4.1f\n", F, C);

        F += step;

    }
}

int main()
{
    tableFtoC();
    return 0;
}
