#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int sFD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sFD, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        perror("bind");

        return 1;
    }
    
    listen(sFD, 5);

    struct sockaddr_in cliente;
    socklen_t cliente_len = sizeof(cliente);

    int cFD = accept(sFD, (struct sockaddr *)&cliente, &cliente_len);

    while (1)
    {
    char input[5000];

    if (recv(cFD, input, sizeof(input), 0) == -1)
    {
        perror("recv");

        return 1;
    }
    

    printf("%s\n\n", input);
    
    char * requisicao = input + 5;

    requisicao[strcspn(requisicao, " ")] = '\0';

    int htmlFD = open(requisicao, O_RDONLY);

    struct stat s;

    fstat(htmlFD, &s);

    char cabecalho[256];

    sprintf(cabecalho, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", s.st_size);

    printf("%s\n", input);

    send(cFD, cabecalho, strlen(cabecalho), 0);

    sendfile(cFD, htmlFD, 0, s.st_size);

    }
    
    close(cFD);
    close(sFD);

    return 0;
}