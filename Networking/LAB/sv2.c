#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/sendfile.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int s = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in saddr, caddr;

    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8080);
    saddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(s, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
    {
        perror("Erro no bind.");
    }

    if (listen(s, 5) < 0)
    {
        perror("Erro no listen.");
    }   

    socklen_t addrlen = sizeof(caddr);

    int c = accept(s, (struct sockaddr*)&caddr, (socklen_t *)&addrlen);

    char buffer[1000];

    read(c, buffer, 999);

    buffer[1000] = '\0';

    int arqTexto = open("sv2_text.txt", O_CREAT | O_RDWR, 0644);

    write(arqTexto, buffer, strlen(buffer));

    int pagefd = open("page.html", O_RDONLY);

    struct stat page;
    fstat(pagefd, &page);

    char * html;

    char cab[500];

    html = "<!DOCTYPE html><html><head><title>Front-end GUI</title></head><body><h1>Ola Browser!!@!</h1></body></html>";

    //sprintf(cab, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\nConnection: close\r\n\r\n%s", strlen(html), html);
    sprintf(cab, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", page.st_size);

    send(c, cab, strlen(cab), 0);

    sendfile(c, pagefd, page.st_size, 0);

    close(arqTexto);
    close(pagefd);
    close(c);
    close(s);    

    return 0;
}
