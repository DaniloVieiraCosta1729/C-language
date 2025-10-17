#include <stdio.h>

int main()
{
    printf("Digite algo: ");

    char input[10];

    fgets(input, 10, stdin);

    printf("Voce digitou: %s", input);

    return 0;
}