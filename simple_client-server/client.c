#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#define MAXL 256

int main(int argc,char* argv[])
{
    int soc;
    char msg1[]="hello from client";
    char msg2[MAXL];
    struct sockaddr_in seraddr;
    int len=sizeof(struct sockaddr_in);
    soc=socket(AF_INET,SOCK_STREAM,0);
    
    seraddr.sin_port=htons(atoi(argv[2]));
    seraddr.sin_addr.s_addr=inet_addr(argv[1]);
    seraddr.sin_family=AF_INET;
    bzero(&seraddr.sin_zero,8);
    
    if((connect(soc,(struct sockaddr *)&seraddr,len))==-1)
    {
        perror("connect:");
        exit(-1);
    }
     
    while(1)
    {
    
        send(soc,msg1,sizeof(msg1),0);
        
        recv(soc,msg2,MAXL,0);
        msg2[MAXL]='\0';
        printf("%s\n",msg2);
        
   }
   
   close(soc);
 } 
    
    
    
