#include <stdint.h>
#include <stdio.h>
#include <string.h>

enum CERTO {OK, ERRO};

enum CERTO testaFGETS();

int main(int argc, char const *argv[])
{
    char tensor[] = {
        tensor[0] = 4,
        1[tensor] = 2,
        *(tensor + 3) = 9,
        tensor[2] = 6,
        tensor[4] = 10
    };

    char avoid[] = {10, 6, '\0'};

    int resultado = strcspn(tensor, avoid);

    printf(">>> %d\n", resultado);


    testaFGETS();

    return 0;
}

enum CERTO testaFGETS()
{
    char texto[50];

    printf("Digite um texto: ");

    if (fgets(texto, sizeof(texto), stdin))
    {
        strcspn(texto, "\n")[texto] = '\0';

        printf("texto: %s\n", texto);
        return OK;
    }

    return ERRO;
}

