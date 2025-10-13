#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>     // <- importante para htons() e struct in_addr
#include <sys/socket.h>
#include <netinet/in.h> 

int main(int argc, char const *argv[])
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr = { AF_INET, 0X901f, 0};


    // agora vamos amarrar um nome ao socket
    bind(sfd, &addr, sizeof(addr));

    // aqui a gente inicializa o socket
    listen(sfd, 10);

    int cfd = accept(sfd, 0, 0);

    char buffer[100];

    recv(cfd, buffer, sizeof(buffer), 0);

    buffer[99] = '\0';

    printf("Mensagem recebida: %s", buffer);
    
    return 0;
}
