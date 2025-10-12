#include <stdio.h>

int main()
{
    int character, size;
    size = 0;
    int words[100];

    for (int i = 0; i < 99; i++)
    {
        words[i] = 0;
    }

    while ((character = getchar()) != EOF)
    {
        if (size >= 98)
        {
            break;
        }

        if (character == 32 || character == '\t' || character == '\n' || character == ',' || character == '.' || character == '(' || character == ')')
        {
            size++;
            continue;
        }

        words[size]++;       

    }
    
    printf("The size of each word was:\n");
    for (int i = 0; i < 99; i++)
    {
        if (words[i] == 0)
        {
            continue;
        }
        
        printf("%d-th: %d\n", (i + 1), words[i]);
    }
    

    return 0;
}