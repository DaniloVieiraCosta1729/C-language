#include <stdio.h>

int main()
{
    int caracter, i, whiteSpace, others;
    int digits[10];

    whiteSpace = others = 0;

    for(i = 0; i < 10; i++)
    {
        digits[i] = 0;
    }

    while((caracter = getchar()) != EOF)
    {
        if(caracter >= '0' && caracter <= '9')
        {
            ++digits[caracter - '0']; // o que esse ++ faz? Ele soma 1 ao número presente na posição caracter - '0'.
        }
        else if(caracter == ' ' || caracter == '\t' || caracter == '\n')
        {
            whiteSpace++;
        }
        else
        {
            others++;
        }
    }

    printf("digits = ");
    for(i = 0; i < 10; i++)
    {
        printf(" %d", digits[i]);
    }
    printf(", white spaces = %d, other = %d\n", whiteSpace, others);

    return 0;
}