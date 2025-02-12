#include <stdio.h>

int main()
{
    int caractere;

    while (caractere != ';')
    {
        caractere = getchar();
        putchar(caractere);
    }
    
    
    return 0;
}