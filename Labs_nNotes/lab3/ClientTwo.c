// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>
#define PORT 8080

int client_sockets[2] = {0};
int num_clients = 0;

void handle_sigint(int sig) {
    printf("\nCannot terminate server by Ctrl+C.\n");
}

void forward_message(char *buffer, int sender_id) {
    int receiver_id = 1 - sender_id;
    send(client_sockets[receiver_id], buffer, strlen(buffer), 0);
}

int main(int argc, char const *argv[]) {
    signal(SIGINT, handle_sigint);

    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    char *hello = "Welcome to the chat room.\n";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080            
    //if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt)))
    {    
    	perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 2) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (num_clients < 2) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        client_sockets[num_clients] = new_socket;
        num_clients++;
        send(new_socket, hello, strlen(hello), 0);
    }

    printf("Both clients connected. You can start chatting now.\n");

    while (1) {
        valread = read(client_sockets[0], buffer, 1024);
        if (strcmp(buffer, "BYE\n") == 0) {
            printf("Client 1 disconnected. Closing the connection...\n");
            break;
        }
        forward_message(buffer, 0);

        valread = read(client_sockets[1], buffer, 1024);
        if (strcmp(buffer, "BYE\n") == 0) {
            printf("Client 2 disconnected. Closing the connection...\n");
            break;
        }
        forward_message(buffer, 1);
    }

    close(client_sockets[0]);
    close(client_sockets[1]);
    close(server_fd);

    printf("Server shutting down.\n");
    return 0;
}