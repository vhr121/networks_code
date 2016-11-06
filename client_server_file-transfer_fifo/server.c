#include <sys/types.h>
#include <sys/stat.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define MAXL 256
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

#define PERM 0666

int main()
{
       int server_to_client,client_to_server,fd;
       char file_name[MAXL],buffer[MAXL];
    
       if((mkfifo(FIFO1,PERM))==-1)
       {
            perror("fifo:");
       }
       
       if((mkfifo(FIFO2,PERM))==-1)
       {
            perror("fifo:");
       }
       
       server_to_client=open(FIFO1,O_WRONLY);
       client_to_server=open(FIFO2,O_RDONLY);
       
       printf("server is connected...\n");
       
       read(client_to_server,file_name,MAXL);
       
       fd=open(file_name,O_RDONLY);
       
       read(fd,buffer,MAXL);
       
       write(server_to_client,buffer,sizeof(MAXL));
       
       printf("file transferred successfully\n");
       
       close(fd);
       close(server_to_client);
       close(client_to_server);
       
       return 0;
  }
       
       
       

