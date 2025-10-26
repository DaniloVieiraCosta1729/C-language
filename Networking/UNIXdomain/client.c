#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_PATH "/tmp/socket_chat"
#define BUFFER_SIZE 256

int main() {
    int sock;
    struct sockaddr_un addr;
    char buffer[BUFFER_SIZE];

    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SOCKET_PATH, sizeof(addr.sun_path) - 1);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_un)) == -1) {
        perror("connect");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor. Digite mensagens (ou 'sair' para encerrar):\n");

    while (1) {
        printf("Você: ");
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
            break;

        buffer[strcspn(buffer, "\n")] = '\0';

        write(sock, buffer, strlen(buffer));

        if (strncmp(buffer, "sair", 4) == 0)
            break;

        int bytes = read(sock, buffer, BUFFER_SIZE - 1);
        if (bytes <= 0) {
            printf("Servidor desconectado.\n");
            break;
        }

        buffer[bytes] = '\0';
        printf("Servidor: %s\n", buffer);
    }

    close(sock);
    return 0;
}