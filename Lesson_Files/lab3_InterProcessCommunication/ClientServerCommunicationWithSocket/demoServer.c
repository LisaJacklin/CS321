// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address; //Structures for handling internet addresses
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server"; //msg to send to a client
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) //create an endpoint for communication. Basically opens a file where both the communicating parties can write 
    {
        perror("socket failed"); //display system error
        exit(EXIT_FAILURE); //defined in stdlib.h. EXIT_SUCCESS = 0, EXIT_FAILURE = 8
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) //set the socket options.
	                                                              //online resource: https://pubs.opengroup.org/onlinepubs/000095399/functions/setsockopt.html
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET; //AF_INET specisies what family of address it is (here it is IPV4)
    address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY is an IP address that is used when we don't want to bind a socket to any specific IP
    address.sin_port = htons( PORT );//host-to-network short. This means it works on 16-bit short integers. i.e. 2 bytes
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0) //bind the socket file descriptor to the socket address. Online resource: https://pubs.opengroup.org/onlinepubs/009695399/functions/bind.html 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) //listen for connections on a socket
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}

