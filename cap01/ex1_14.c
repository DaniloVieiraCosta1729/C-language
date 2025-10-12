#include <stdio.h>

#define QTDCARACTERES 94

int main()
{
    int charsInput[QTDCARACTERES];
    int character;
    
    for (int i = 0; i < 94; i++)
    {
        charsInput[i] = 0;
    }
    
    while ((character = getchar()) != EOF)
    {
        if (character >= 32 || character <= 126)
        {
            charsInput[character - 32]++;
        }
    }
    

    printf("histograma de caracteres digitados:\n");

    for (int i = 32; i < 126; i++) // it seems like the printable characters are in between 32 and 126. (according to the ascii table)
    {
        printf("%c: %d\n", i, charsInput[i - 32]);
    }
    
}