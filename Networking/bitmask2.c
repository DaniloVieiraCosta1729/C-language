#include <stdio.h>

#define VISIVEL (1 << 0)
#define SOBMIRA (1 << 1)
#define ATIRANDO (1 << 2)


struct alvo
{
    int estado;
};


int main(int argc, char const *argv[])
{
    struct alvo x;
    x.estado = 0;

    printf("Select:  [a] Visible  [b] OnTarget  [c] Shooting  [s] exit and see results\n>>> ");
    char c;

    while (1)
    {        
        if ((c = getchar()) != EOF && c != '\n')
        {
            if (c == 's' || c == 'S')
            {
                break;
            }
            
            switch (c)
            {
            case 'a':
            case 'A':
                x.estado = x.estado | VISIVEL;
                printf("Spoted\n");
                printf("state: %d\n", x.estado);
                continue;
            
            case 'b':
            case 'B':
                x.estado = x.estado | SOBMIRA;
                printf("On target\n");
                printf("state: %d\n", x.estado);
                continue;
            
            case 'c':
            case 'C':
                x.estado = x.estado | ATIRANDO;
                printf("Shooting\n");
                printf("state: %d\n", x.estado);
                continue;

            default:
                continue;
            }
        }        
    }

    if (x.estado == 0b111)
    {
        printf("acertou\n");
        printf("%d\n", x.estado);
        return 0;
    }
     
    printf("Errou\n");
    return 0;
}
