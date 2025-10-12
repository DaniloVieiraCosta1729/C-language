#include <stdio.h>

// write a program that counts blanks, tabs and new lines.

int main()
{
    int generalCounting = 0, blankCounting = 0, tabCounting = 0, linesCounting = 0;

    char state;

    while ((state = getchar()) != EOF)
    {
        if (state == 32) // in the ASCII, the blank character is 32
        {
            generalCounting++;
            blankCounting++;
        }
        if (state == '\n')
        {
            generalCounting++;
            linesCounting++;
        }
        if (state == '\t')
        {
            generalCounting++;
            tabCounting++;
        }     
        
    }

    printf("Voce digitou %d caracteres observados, a saber:\n", generalCounting);
    printf("%d espacos;\n", blankCounting);
    printf("%d tabs;\n", tabCounting);    
    printf("%d linhas.\n", linesCounting);

    return 0;
}