#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


#define MAXL 256
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main()
{
    int server_to_client,client_to_server;
    char file_name[MAXL],buffer[MAXL];
    
    server_to_client=open(FIFO1,O_RDONLY);
    client_to_server=open(FIFO2,O_WRONLY);
    printf("client connected....\n");
    printf("enter the file to fetch from the server\n");
    scanf("%s",file_name);
    
    write(client_to_server,file_name,MAXL);
    
    printf("requested server the file %s\n",file_name);
    
    read(server_to_client,buffer,MAXL);
    
    buffer[MAXL]='\0';
    
    printf("the contents of the file are:\n");
    
    printf("%s",buffer);
    
    close(client_to_server);
    close(server_to_client);
    
    return 0;
}
    
    
    
