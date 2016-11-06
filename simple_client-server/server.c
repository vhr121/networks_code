 #include <sys/types.h>         
 #include <sys/socket.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <netinet/in.h>
 #include <string.h>
 #include <unistd.h>
 
 #define MAXL 256
 
 int main()
 {
    unsigned int soc,new;
    struct sockaddr_in seraddr;
    struct sockaddr_in cliaddr;
    char msg1[]="hello from the server!!";
    char msg2[MAXL];
    int len=sizeof(struct sockaddr_in );
    
    if((soc=socket(AF_INET,SOCK_STREAM,0))==-1)
    {
        perror("socket:");
        exit(-1);
    }
    
    seraddr.sin_port=htons(10000);
    seraddr.sin_addr.s_addr=INADDR_ANY;
    seraddr.sin_family=AF_INET;
    bzero(&seraddr.sin_zero,8);
    
    if((bind(soc,(struct sockaddr*)&seraddr,len))==-1)
    {
        perror("bind:");
        exit(-1);
    }
    
    if((listen(soc,10))==-1)
    {
        perror("listen:");
        exit(-1);
    }
    
    while(1)
    {
        if((new=accept(soc,(struct sockaddr*)&cliaddr,&len))==-1)
        {
            perror("accept:");
            exit(-1);
        }
        recv(new,msg2,MAXL,0);
        msg2[MAXL]='\0';
        send(new,msg1,sizeof(msg1),0);
        printf("%s\n",msg2);
        
        
   }
   close(new);
   
   printf("disconnected from client\n");
 
   return 0;  
}
        
        
        
        
        
    
    
    
    
    

