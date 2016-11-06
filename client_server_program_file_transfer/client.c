#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <arpa/inet.h>

#define MAXL 256

int main(int argc,char* argv[])
{
    int sock,len;
    char buff[MAXL];
    struct sockaddr_in servaddr;
    len=sizeof(struct sockaddr_in);
    
    sock=socket(AF_INET,SOCK_STREAM,0);
    
    servaddr.sin_addr.s_addr=inet_addr(argv[1]);
    servaddr.sin_port=htons(atoi(argv[2]));
    servaddr.sin_family=AF_INET;
    
    
    connect(sock,(struct sockaddr *)&servaddr,len);
    
    
    printf("requesting the file %s to server\n",argv[3]);
    send(sock,argv[3],sizeof(argv[3]),0);
    
    recv(sock,buff,MAXL,0);
    
    buff[MAXL]='\0';
    
    printf("the contents of the file are:\n");
    printf("%s\n",buff);
    
    return 0;
}
    
    
