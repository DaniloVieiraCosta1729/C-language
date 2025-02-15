#include <stdio.h>

//write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.


// let's do it, but i'll only be replacing multiple blanks. 

int main()
{
    char blankstatus = 0, currentTextLength = 0;

    int currentCharacter;

    char fullText[100];

    while (((currentCharacter = getchar()) != EOF))
    {
        if (currentTextLength >= 99)
        {
            break;
        }
        
        if (currentCharacter == 32)
        {
            if (blankstatus)
            {
                continue;
            }
            blankstatus = 1;
        }
        else
        {
            blankstatus = 0;
        }
        
        fullText[currentTextLength++] = currentCharacter; // atribui currentCharacter à posição currentTextLength e depois soma 1 ao currentTextLength.
        

        /*
        if ((currentCharacter == 32) && (blankstatus == 0))
        {
            blankstatus = 1;
        } else if ((currentCharacter != 32) && (blankstatus == 1))
        {
            blankstatus = 0;
        } else if ((currentCharacter == 32) && (blankstatus == 1))
        {
            continue;
        }
        */
        

        /*
        if ((currentCharacter == 32) && (blankstatus == 1))
        {
            continue;
        } else if ((currentCharacter != 32) && (blankstatus == 1))
        {
            blankstatus = 0;
        } else if ((currentCharacter == 32) && (blankstatus == 0))
        {
            blankstatus = 1;
        }
        */
    }
    
    fullText[currentTextLength] = '\0';
    printf("A copia, sem mostrar espacos repetidos, do seu texto eh: \n \" %s\"", fullText);

    return 0;
}