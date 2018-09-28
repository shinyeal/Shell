/*************************************************************************
	> File Name: socket_client_chat.c
	> Author: 
	> Mail: 
	> Created Time: 2018年09月26日 星期三 15时13分33秒
 ************************************************************************/

//socket客户端发送消息

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {

    int socket_client;
    int num_read;
    char buffer[MAX_SIZE];   //存储接收数据
    struct sockaddr_in dest_addr;   //目标地址信息
    int port = atoi(argv[2]);   //目标地址端口地址信息
    char *host = argv[1];   //目标地址IP信息

    //建立socket
    if((socket_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    dest_addr.sin_family = AF_INET;  //接收本机或其他机器传输
    dest_addr.sin_port = htons(port);  //端口号
    dest_addr.sin_addr.s_addr = inet_addr(host);  //IP

    if(connect(socket_client, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
        perror("connect");
        return -1;
    }

    while(1) {
        scanf("%[^\n]s", buffer);
        getchar();  //防止死循环
        send(socket_client, buffer, strlen(buffer), 0);
        //将接收处打入buffer，参数分别是句柄，存储处
    }
    close(socket_client);

    return 0;
}
