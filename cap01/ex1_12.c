#include <stdio.h>
#define BLANK 32

//write a program that prints its input one word per line.

int main()
{
    int currentCharacter, limit;
    limit = 0;

    char response[100];

    while ((currentCharacter = getchar()) != EOF)
    {
        if (limit >= 99)
        {
            break;
        }
        
        response[limit++] = currentCharacter;

        if (currentCharacter == BLANK)
        {
            response[limit++] = '\n';
        }
    }

    printf("%s\n",response);

    return 0;
}