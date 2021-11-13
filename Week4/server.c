//Nguyễn Khánh Quân 19020400
//Server tuần 4
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
void commute(int confd){
	char buffer[MAX];
	int n;

	while(1){
		bzero(buffer, MAX);
		read(confd, buffer, sizeof(buffer));
		printf("From Client: %s\n" ,buffer);
		if (strncmp(buffer, "HELO Server", 11) == 0)
		{
			/* code */
			char buffer1[MAX]= "200 Hello Client";
			write(confd, buffer1, sizeof(buffer1));
			printf("Sending to client: 200 Hello Client\n");
		}
		if (strncmp(buffer, "USER NAME", 9) == 0)
		{
			/* code */
			printf("Sending to client: 210 User name OK\n");
			write(confd, "210 User name OK", sizeof("210 User name OK"));
			bzero(buffer, MAX);
			read(confd, buffer, sizeof(buffer));
			printf("From Client: %s\n" ,buffer);
			int check = 0;
			for (int i = 0; i < 1024; i++)
			{
				/* code */
				if (!((buffer[i] >= 'A' && buffer[i] <= 'Z') || (buffer[i] >= 'a' && buffer[i] <= 'z')))
				{
					/* code */
					if (buffer[i] == '\0' || buffer[i] == '\n')
					{
						/* code */
						continue;
					}
					check++;
					
				}
			}
			
			if (!check)
			{
				/* code */
				char buffer1[MAX]= "211 User name ";
				strcat(buffer1, buffer);
				strcat(buffer1, " OK");
				printf("Sending to client: %s\n", buffer1);
				write(confd, buffer1, sizeof(buffer1));
			} else {
				write(confd, "410 User name error", sizeof("410 User name error"));
				printf("Sending to client: 410 User name error\n");
			}
		}
		if (strncmp(buffer, "USER AGE", 8) == 0)
		{
			/* code */
			printf("Sending to client: 220 User age OK\n");
			write(confd, "220 User age OK", sizeof("220 User age OK"));
			bzero(buffer, MAX);
			read(confd, buffer, sizeof(buffer));
			printf("From Client: %s\n" ,buffer);
			int check = 0;
			for (int i = 0; i < 1024; ++i)
			{
				/* code */
				if (!(buffer[i] >= '0' && buffer[i] <= '9'))
				{
					/* code */
					if (buffer[i] == '\0' || buffer[i] == '\n')
					{
						/* code */
						continue;
					}
					check++;
					break;
				}
			}
			if (!check)
			{
				/* code */
				char buffer1[MAX]= "211 User age ";
				strcat(buffer1, buffer);
				strcat(buffer1, " OK");
				printf("Sending to client: %s\n", buffer1);
				write(confd, buffer1, sizeof(buffer1));
			} else {
				write(confd, "420 User age error", sizeof("420 User age error"));
				printf("Sending to client: 420 User age error\n");
			}
		}
		if (strncmp(buffer, "QUIT", 4) == 0)
		{
			/* code */
			write(confd, "500 bye", sizeof("500 bye"));
			printf("Sending to client: 500 bye\n");
			break;
		}
		
	}
}
int main(){
	int sockfd, confd, len;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		/* code */
		printf("Fail to create \n");
	} else {
		printf("Create successfull ! \n");
	}

	struct sockaddr_in serveras, cli;
	bzero(&serveras, sizeof(serveras));

	serveras.sin_family = AF_INET;
	serveras.sin_addr.s_addr = htonl(INADDR_ANY);
	serveras.sin_port = htons(PORT);

	if ((bind(sockfd,(SA*)&serveras, sizeof(serveras))) != 0)
	{
	 	/* code */
	 	printf("Binding failed \n");
	 	exit(0);
	} else {
	 	printf("Binding success ! \n");
	}

	if (listen(sockfd,5) != 0)
	{
		/* code */
		printf("Listening failed ! \n");
	} else {
		printf("Server Listening .. \n");
	}
	len = sizeof(cli);

	confd = accept(sockfd, (SA*)&cli, &len);
	if (confd < 0)
	{
		/* code */
		printf("Accept Failed \n");
	} else {
		printf("Accept Client \n");
	}
	commute(confd);
	close(sockfd);
}