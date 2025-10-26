#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/socket_chat"
#define BUFFER_SIZE 256

int main() {
    int server_sock, client_sock;
    struct sockaddr_un addr;
    char buffer[BUFFER_SIZE];
    char resposta[BUFFER_SIZE];

    unlink(SOCKET_PATH); // Remove qualquer socket antigo

    if ((server_sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    if (bind(server_sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("bind");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 1) == -1) {
        perror("listen");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexão...\n");

    if ((client_sock = accept(server_sock, NULL, NULL)) == -1) {
        perror("accept");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado!\n");

    while (1) {
        int bytes = read(client_sock, buffer, BUFFER_SIZE - 1);
        if (bytes <= 0) {
            printf("Cliente desconectado.\n");
            break;
        }

        buffer[bytes] = '\0';

        if (strncmp(buffer, "sair", 4) == 0)
            break;

        printf("Cliente: %s\n", buffer);

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        write(client_sock, buffer, strlen(buffer));
    }

    close(client_sock);
    close(server_sock);
    unlink(SOCKET_PATH);
    return 0;
}