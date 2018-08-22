#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 4096 // 4 * 1024

int main(int argc, char **argv)
{
    int listenfd, // 监听端口的 socket 描述符
        connfd;   // 连接端 socket 描述符
    struct sockaddr_in servaddr;
    char buff[MAXLINE];
    int n;

    // 创建 socket，并且进行错误处理
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    // 初始化 sockaddr_in 数据结构
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    // 绑定 socket 和 端口
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    // 监听连接
    if (listen(listenfd, 10) == -1)
    {
        printf("listen socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    printf("====== Waiting for client's request======\n");

    // 持续接收客户端的连接请求
    while (true)
    {
        if ((connfd = accept(listenfd, (struct sockaddr *)NULL, NULL) == -1))
        {
            printf("accept socket error: %s(errno: %d)\n", strerror(errno), errno);
            continue;
        }

        n = recv(connfd, buff, MAXLINE, 0);
        buff[n] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(connfd);
    }

    close(listenfd);
    return 0;
}
