#include <stdio.h>

// Exercise 1-4: Write a program to print the corresponding Celsius to Fahrenheit table.

// É um exercício muito parecido, praticamente a mesma coisa, então vamos usar a abordagem da recursão novamente. 

int CtoF(float lowest, float highest, float step)
{
    if (lowest > highest)
    {
        return 0;
    }

    float F = (9.0/5)*lowest + 32; // parece uma péssima ideia. Eu imagino que o compilador vai criar uma stack para guardar o estado de cada chamada recursiva e vai gerar um valor para F em cada uma das chamadas.

    printf("\t %6.1f C\t\t %6.1f\n", lowest, F);

    return CtoF(lowest + step, highest, step);
}

int main()
{
    printf("\t Celsius \t\t Fahrenheit\n");
    CtoF(0, 300, 20);

    return 0;
}