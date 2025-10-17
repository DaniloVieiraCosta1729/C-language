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
    // Nosso endpoint
    int sFD = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;


    // nomea o socket
    if (bind(sFD, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        perror("bind");

        return 1;
    }
    

    // inicializa o socket, permitindo 5 conexões
    listen(sFD, 5);

    struct sockaddr_in cliente;
    socklen_t cliente_len = sizeof(cliente);

    // a função accept nos fornece um file descriptor para um socket que o cliente usará. Ele faz isso assim que um cliente acessa a porta de escuta.
    int cFD = accept(sFD, (struct sockaddr *)&cliente, &cliente_len);

    // vamos criar um buffer para ler o que for enviado pelo cliente
    char input[5000];

    // recv vai ler o conteudo enviado e colocá-lo no buffer que criamos. Ele retorna a quantidade de caractéres lidos ou -1 em caso de erro.
    if (recv(cFD, input, sizeof(input), 0) == -1)
    {
        perror("recv");

        return 1;
    }
    

    printf("%s\n\n", input);

    // Vamos acessar com o chrome, então ele vai fazer uma requisição HTTP GET. Vamos abrir um HTML podrão quando isso acontecer.
    
    char * requisicao = input + 5;

    requisicao[strcspn(requisicao, " ")] = '\0';

    int htmlFD = open(requisicao, O_RDONLY);

    struct stat s;

    fstat(htmlFD, &s);

    char cabecalho[256];

    sprintf(cabecalho, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", s.st_size);

    send(cFD, cabecalho, strlen(cabecalho), 0);

    sendfile(cFD, htmlFD, 0, s.st_size);

    close(htmlFD);
    close(cFD);
    close(sFD);

    return 0;
}
