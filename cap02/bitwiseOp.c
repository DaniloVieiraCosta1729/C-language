/*
&   bitwise AND
|   bitwise OR
^   bitwise XOR
<<  left shift
>>  right shift
~   complement (negação)
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

extern int randomD(int intervalo);

#define PEDRA       0b001
#define PAPEL       0b010
#define TESOURA     0b100

enum saisho_gu {VENCEU, PERDEU};

enum saisho_gu jokenpo(int x);

int main(int argc, char const *argv[])
{
    printf("----------- Pedra, Papel e Tesoura -----------\n\n");
    
    char input[2];

    while (1)
    {
        printf("[1]Pedra\t\t[2]Papel\t\t[3]Tesoura\t\t\t\t [4]sair_do_jogo\n");
        printf(">>> ");
        scanf("%s", &input);
        0[input] -= '0';
    
        int v = randomD(3);

        int maquina = 0b001 << v;

        if (*input == 4)
        {
            printf("-- [Jogo terminado] --\n");
            break;
        }
        

        switch (*input)
        {
        case 1:
            printf("\nmaquina: %d\nusuario: %d\nresultado: %d\n", v + 1, *input, maquina & (PEDRA | TESOURA));
            jokenpo(maquina & (PEDRA | TESOURA));
            break;

        case 2:
            printf("\nmaquina: %d\nusuario: %d\nresultado: %d\n", v + 1, *input, maquina & (PEDRA | PAPEL));
            jokenpo(maquina & (PEDRA | PAPEL));
            break;

        case 3:
            printf("\nmaquina: %d\nusuario: %d\nresultado: %d\n", v + 1, *input, maquina & (PAPEL | TESOURA));
            jokenpo(maquina & (PAPEL | TESOURA));
            break;

        default:
            break;
        }
        sleep(2);
    }

    return 0;
}

enum saisho_gu jokenpo(int x)
{
    if (x)
    {
        printf("Ok!\n");
        return VENCEU;
    }

    printf("Você perdeu.\n");
    return PERDEU;        
}    
