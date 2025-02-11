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

// Vamos modificar a função table() para usarmos o #define para lidar com esses números soltos (step, initial e final). 

void tableWithDefine()
{
    #define step 20
    #define lowest 0
    #define highest 300  // não tem ; por algum motivo....

    float F, C;

    printf("C\t\tF");

    for(F = highest; F >= lowest; F -= step)
    {
        C = (5.0/9.0)*(F-32);
        printf("\n%6.2f\t\t%6.2f", F, C);
    }
    
}

int main()
{
    //table();
    tableWithDefine();

    return 0;
}