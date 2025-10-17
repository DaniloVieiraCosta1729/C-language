#include <stdio.h>

int main()
{
    int caractere; // todo caractere é armazenado como um binário, então podemos usar int como o tipo que guarda o valor desse caractere.

    /*
    while (caractere != ';')
    {
        caractere = getchar();
        putchar(caractere);
    }
    */

    //Refatorando o while. Vamos usar uma condição que é sempre verdadeira até que o programa chegue em EOF, ou seja, no fim do arquivo (no terminal isso acontece quando pressionamos ctrl + c, ou quando fechamos a aplicação).
    // A vantagem de fazer isso é que o getchar fica contido apenas no condicional do while.

    while ((caractere = getchar()) != EOF)
    {
        putchar(caractere);
    }
    
    
    
    return 0;
}