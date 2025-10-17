#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int descriptor = open("computer.png", O_RDONLY);

    struct stat s;

    fstat(descriptor, &s);

    int tamanhoImagem = s.st_size;

    printf("O tamanho da imagem eh: %d\n", tamanhoImagem);

    close(descriptor);

    return 0;
}
