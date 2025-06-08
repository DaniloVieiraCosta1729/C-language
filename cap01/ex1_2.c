#include <stdio.h>

int main()
{
    printf("Testando o caractere");
    return 0;
}

// Ao compilar, recebi um warning dizendo que \c é um "unknown escape sequence"... Mas o código compilou mesmo assim e interpretou \c como c (com o compilador gcc).