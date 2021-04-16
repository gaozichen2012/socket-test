#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "server_poc.h"
#define PORT 22
#define MAXDATASIZE 100

int sockfd;
struct sockaddr_in server;
struct sockaddr_in client_present;
struct sockaddr_in client_other;

socklen_t addrlen;
int num;
char rx_buf[MAXDATASIZE];

void main(void)
{
    //socket()确定一个socket文件描述符
    //AF_INET 决定了要用ipv4地址（32位的）与端口号（16位的）的组合
    //SOCK_DGRAM 表示建立UDP链接
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Creatingsocket failed.");
        exit(1);
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind()函数把一个地址族中的特定地址赋给socket。
    //将刚创建的sockfd绑定特定地址
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        perror("Bind()error.");
        exit(1);
    }

    addrlen = sizeof(client_present);
    while (1)
    {
        num = recvfrom(sockfd, rx_buf, MAXDATASIZE, 0, (struct sockaddr *)&client_present, &addrlen);

        if (num < 0)
        {
            perror("recvfrom() error\n");
            exit(1);
        }
        rx_buf[num] = '\0';

        // printf("You got a message (%s) from client_present.\nIt's ip is%s, port is %d.\n", rx_buf, inet_ntoa(client_present.sin_addr), htons(client_present.sin_port));
        server_at_unpacket_process(rx_buf);

        if (!strcmp(rx_buf, "bye"))
            break;
    }
    close(sockfd);
}

int server_send_cmd2_answer(char *pCmd)
{
    return sendto(sockfd, pCmd, 22, 0, (struct sockaddr *)&client_present, addrlen);
}

int server_send_cmd2_other(char *pCmd)
{
    return sendto(sockfd, pCmd, 22, 0, (struct sockaddr *)&client_other, addrlen);
}

void identify_client_persent_or_other(void)
{
    if (client_present.sin_addr == "112.97.57.194")
    {
        client_other.sin_addr = "112.97.57.194";
    }
    else
    {
        client_other.sin_addr = "112.97.57.194";
    }
}