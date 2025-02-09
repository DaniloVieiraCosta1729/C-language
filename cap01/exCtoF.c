#include <stdio.h>

void espaco(int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void tableFtoC()
{
    // Criar tabela entre °F e °C, começando com 20 °F e indo, de 20 em 20, até 300 °F.

    float lowestTemperature, highestTemperature, rate;
    float C, F;
    
    rate = 20;
    lowestTemperature = 20;
    highestTemperature = 300;

    for (F = lowestTemperature; F <= highestTemperature; F += rate)
    {
        C = (5*(F-32))/9;
        printf("%f F", F);
        espaco(5);
        printf("%f C \n", C);
    }
}

int tableFtoCRecursively(float initial, float final, float rate)
{
    if (initial > final)
    {
        return 0;
    }

    float C = 5*(initial-32)/9;

    printf("%f F", initial);
    printf("\t\t\t"); // só pra ficar diferente do anterior, vou usar o caractere \t.
    printf("%f C\n", C);

    return tableFtoCRecursively(initial + rate, final, rate);   
}

int main()
{
    //tableFtoC();
    tableFtoCRecursively(20, 300, 20);
    return 0;
}