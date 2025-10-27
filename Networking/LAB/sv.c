/*
Vou tentar descrever como criar um server, talvez assim eu consiga fazer o meu cerebro destravar aqui.

1 - iniciar um socket (int file_descriptor =  socket(familia, tipo, protocolo));
2 - criar uma instância da estrutura sockaddr_in para o servidor e outra para o cliente
3 - preencher os campos da struct do servidor
4 - "nomear o socket" (amarrar o socket à struct com o bind)
5 - começar a escutar com listen
6 - iniciar um file descriptor para o cliente com accept usando a estrutura feito para o cliente

Aqui começa a aplicação real, onde se pode ler e escrever através do socket. 
Existe uma certa variedade de opções para ler e escrever.

7 - Talvez, fazer um while loop que lê os dados enviados pelo cliente
8 - coloca eles em um buffer e então faz o tratamento desse buffer.
9 - quando for terminar a aplicação, sair do while, fechar os sockets.
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>

#define BUFFER_SIZE 1024

int main(int argc, char const *argv[])
{
    int sfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in addrS, addrC;
    addrS.sin_family = AF_INET;
    addrS.sin_port = htons(8080);
    addrS.sin_addr.s_addr = INADDR_ANY;

    if (bind(sfd, (struct sockaddr*)&addrS, sizeof(addrS)) < 0)
    {
        perror("bind");
        close(sfd);
        return 0;
    }
    
    if (listen(sfd, 5) < 0)
    {
        perror("listen");
        close(sfd);
        return 0;
    }

    int cfd;
    socklen_t addrlen = sizeof(addrC);
    
    if ((cfd = accept(sfd, (struct sockaddr*)&addrC, (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        close(cfd);
        return 0;
    }

    // Se chegamos até aqui sem erros, é porque deu certo, eu acho.
    char buffer[BUFFER_SIZE];
    read(cfd, buffer, BUFFER_SIZE - 1); // -1 para deixar um espaço para o '\0', caso o cliente seja muito comunicativo.
    printf("requisicao: %s", buffer);

    char * req = buffer + 5; // pulamos o GET da string
    req[strcspn(req, " ")] = '\0';

    int pagefd = open(req, O_RDONLY); // legal, a flag aqui é um dos usos que o OS faz do bitmask.

    // Aqui vamos precisar fazer algum trabalho para conseguir enviar o html para o browser.
    /*
    Para que o browser aceite o html que enviaremos com sendfile(), precisamos antes enviar uma mensagem com send. Tal mensagem é o cabeçalho HTTP dizendo o que queremos fazer. Basicamente, serão 3 linhas:
    HTTP 1.1 200 OK
    Content-Type: text/html
    Content-Length: tamanho em bytes do arquivo que estamos enviando (fácil de obter com a estrutura stat e com a função fstat).
    */
   
    struct stat page;
    fstat(pagefd, &page);

    char cabecalho[256];
    sprintf(cabecalho, "HTTP 1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", page.st_size);

    send(cfd, cabecalho, strlen(cabecalho), 0);
    sendfile(cfd, pagefd, 0, page.st_size);

    close(cfd);
    close(pagefd);
    close(sfd);
    
    return 0;
}
