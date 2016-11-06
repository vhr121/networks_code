#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h>




#define MAXL 256

int main()
{
    int sock,new,fd;
    unsigned int len;
    char buff1[MAXL],buff2[MAXL];
    struct sockaddr_in servaddr;
    struct sockaddr_in clinaddr;
    
    //create the socket for the server  which uses IPV4 protocol and TCP
    
    sock=socket(AF_INET,SOCK_STREAM,0);
    
    //initialise the IP address , port number and family
    
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(10000);             //port number host to network short(htons)
    servaddr.sin_addr.s_addr=INADDR_ANY;        //any available IP address
    
    bzero(&servaddr.sin_zero,8);                //initializing unused 8bits to zero
    
    
    len=sizeof(struct sockaddr_in);
    
    //bind the ip address and the port to the socket
    
    bind(sock,(struct sockaddr *)&servaddr,len);
    
    // listen for the connection request from client 
    
    listen(sock,10);
    
    //accept the connection request from the client and store the client socket in new
    
    new=accept(sock,(struct sockaddr *)&clinaddr,&len);
    
    //perform the send and recieve operation
    
    printf("client %s connected\n",inet_ntoa(clinaddr.sin_addr));
    
    recv(new,buff1,MAXL,0);         //get the file name to be opened
    
    fd=open(buff1,O_RDONLY);              //open the file
    
    read(fd,buff2,MAXL);            //read the file into buff2
    
    send(new,buff2,sizeof(buff2),0);    //send the file to the client
    
    
    printf("sent the file %s to client\n",buff1);
    
    close(fd);
    close(new);
    
    printf("disconnected\n");
    
    return 0;
 }
    
    
    
    
    
    
    
    
    
    
    

