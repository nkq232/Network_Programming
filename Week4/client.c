//Nguyễn Khánh Quân 19020400
//Client tuần 4
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAX 1024
#define PORT 8081
#define SA struct sockaddr
void commute(int sockfd)
{
    char buffer[MAX];
    char buffer1[MAX];
    int n;
    while(1) {
        bzero(buffer, sizeof(buffer));
        printf("Enter message : ");
        scanf("%[^\n]%*c", buffer); 
        write(sockfd, buffer, sizeof(buffer));
        bzero(buffer1, sizeof(buffer1));
        read(sockfd, buffer1, sizeof(buffer1));
        printf("From Server : %s\n", buffer1);
        if (strncmp(buffer, "QUIT", 4) == 0)
        {
            /* code */
            write(sockfd, "Bye", sizeof("Bye"));
            break;
        }
    }
}
   
int main()
{
    int sockfd, confd;
    struct sockaddr_in serveras, cli;
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&serveras, sizeof(serveras));
   
    serveras.sin_family = AF_INET;
    serveras.sin_addr.s_addr = inet_addr("127.0.0.1");
    serveras.sin_port = htons(PORT);
   
    
    if (connect(sockfd, (SA*)&serveras, sizeof(serveras)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
   
   
    commute(sockfd);
   
    
    close(sockfd);
}