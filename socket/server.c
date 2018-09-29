/*************************************************************************
> File Name: server.c
> Author: 
> Mail: 
> Created Time: 2018年09月28日 星期五 22时12分54秒
************************************************************************/

#include<stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <sys/stat.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/time.h>


#define MAX_SIZE 1000
#define PORT 1028
#define PORT1 1029
#define LISTNUM 100

int main(){

    int a, login;
    int pid;
    int socket_server, sockfd;
    struct sockaddr_in s_addr, c_addr;
    socklen_t len;
    int port, listnum; 

    if((socket_server = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(PORT);
    s_addr.sin_addr.s_addr = htons(INADDR_ANY);

    if((bind(socket_server, (struct sockaddr*) &s_addr, sizeof(struct sockaddr))) < 0) {
        perror("bind");
        return -1;
    }

    if(listen(socket_server, listnum) < 0) {
        perror("listem");
        return -1;
    }

    struct sockaddr_in s1_addr;
    int socket_server1, newfd;

    if((socket_server1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    s1_addr.sin_family = AF_INET;
    s1_addr.sin_port = htons(PORT1);
    s1_addr.sin_addr.s_addr = htons(INADDR_ANY);

    if((bind(socket_server1, (struct sockaddr*) &s1_addr, sizeof(struct sockaddr))) < 0) {
        perror("bind");
        return -1;
    }

    if(listen(socket_server1, listnum) < 0) {
        perror("listen");
        return -1;
    }


    while(1) {
        printf("begin !!\n");
        len = sizeof(struct sockaddr);
        if((sockfd = accept(socket_server, (struct sockaddr*) &c_addr, &len)) < 0){
            perror("accept");
            return -1;
        }

        if((pid = fork()) < 0) {
            printf("Error");
        }

        FILE *fpt;
        int buffer_num;
        if(pid == 0) {
            char buffer[MAX_SIZE];
            while((a = recv(sockfd, &buffer_num, MAX_SIZE, 0)) > 0) {
                send(sockfd, &buffer_num, 4, 0);
                if((newfd = accept(socket_server1, (struct sockaddr *) &c_addr, &len)) < 0) {
                    perror("newfd");
                    return -1;
                }

                while((login = recv(newfd, buffer, MAX_SIZE, 0)) > 0) {
                    buffer[login] = '\0';
                    //printf("recv %d 字节 %s\n",login, buffer);
                    printf("%s\n", buffer);

                    char IP[30] = {0};
                    strcpy(IP, inet_ntoa(c_addr.sin_addr));
                    char str[201] = "/home/xinyue/shell/socket/client ";
                    strcat(str, IP);
                    mkdir(str, 0777);

                    if(buffer_num == 100){
                        strcat(str, "/cpu.log");      
                    } else if(buffer_num == 101) {
                        strcat(str, "/disk.log");
                    } else if(buffer_num == 102) {
                        strcat(str, "/mem.log");
                    }
                    fpt = fopen(str, "a+");
                    fprintf(fpt, "%s\n", buffer);
                    fclose(fpt);

                }
                fflush(stdout);
                memset(buffer, 0, sizeof(buffer));
                close(newfd);
            }
            close(sockfd);
        }
    }
    close(socket_server);
    return 0;
}
