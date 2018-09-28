/*************************************************************************
> File Name: socket_client.c
> Author: 
> Mail: 
> Created Time: 2018年09月23日 星期日 16时25分04秒
************************************************************************/

#define MAX_SIZE 1000
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

int main(int argc, char *argv[]) {

    int sock_client;
    int num_read;
    char buffer[MAX_SIZE];  //储存接收数据
    struct sockaddr_in dest_addr;  //目标地址信息
    int port = atoi(argv[2]);  //目标地址端口地址信息
    char *host = argv[1];   //目标地址IP信息

    //建立socket
    if((sock_client = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket");
        return -1;
    }

    dest_addr.sin_family = AF_INET;
    //该属性表示接收本机或其他机器传输
    dest_addr.sin_port = htons(port);  //端口号
    dest_addr.sin_addr.s_addr = inet_addr(host);  //IP

    if(connect(sock_client, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) < 0) {
        perror("Connect");
        return -1;
    }


    FILE *fd;
    fd = fopen("./socket_server.c", "r");
    while(!feof(fd)) {

        num_read = fread(buffer, sizeof(char), MAX_SIZE, fd);
        send(sock_client, buffer, num_read, 0);
        //发送信息
        //scanf("%[^\n]s", buffer);
        //getchar();  //防止死循环
        //send(sock_client, buffer, strlen(buffer), 0);
        //将接收处打入buffer，参数分别是句柄，储存处
    }

    fflush(stdout);
    fclose(fd);
    close(sock_client);
    //close(sock_client);   //关闭socket
    return 0;
}
