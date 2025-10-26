// Para fazermos a multiplexação de I/O com select, precisamos entender sobre bitmask.
// basicamente, quando queremos lidar com multiplos file descriptors, podemos usar uma estrutura chada fd_set que é implementada em sys/select.h;
// o nome é autoexplicativo, ele funciona como um conjunto de file descriptors, porém, diferente de conjuntos, os fd dessa estrutura se dispõem em uma ordem.
// Para manipularmos essa estrutura, usamos algumas macros que estão definidas em sys/select.h.

#include <sys/select.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    fd_set conjunto;

    FD_ZERO(&conjunto);
    FD_SET(4, &conjunto);
    FD_SET(7, &conjunto);

    printf("O tamanho do conjunto de fd é\n>>> %d\n", FD_SETSIZE);

    for (size_t i = 0; i < 10; i++)
    {
        printf("%zuº FD: %d\n", i + 1, FD_ISSET(i, &conjunto));
    }

    FD_CLR(4, &conjunto);

    printf("4º FD: %d\n", FD_ISSET(4, &conjunto));  


    return 0;
}
