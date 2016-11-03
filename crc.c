#include<stdio.h>
#include<string.h>

char gen[]="10001000000100001",msg[256],append_m[256],crc[256],send_m[256],rem[256],recieve_msg[256];

int main()
{
    char c;
    int n=0,i,k=0,j,m=0,l=0;
    long int size_gen=sizeof(gen);
    
    printf("enter the message\n");
    
    while((c=getchar())!='\n')
    {
        msg[n++]=c;
    }
    msg[n]='\0';
    
    printf("\n\nthe message entered is \n");
    puts(msg);
    for(i=0;i<n;i++)
        append_m[i]=msg[i];
    
    for(i=0;i<size_gen-2;i++)
        append_m[n+i]='0';
        
    append_m[n+i]='\0';
    
    printf("\n\nthe message appended with (size_gen-1)number of 0's is\n");
    puts(append_m);
    
    //modulo2 division
    
    for(i=0;i<n;i++)
    {
        if(append_m[i]=='1')
        {
            for(j=0;j<size_gen-1;j++)
            {
                if(append_m[i+j]==gen[j])
                {
                    append_m[i+j]='0';
                }
                else
                {
                    append_m[i+j]='1';
                }
           }
       }
    }
    
    printf("\n\nthe CRC code generated is\n");
    
    i=n;
    
    //extracting the reminder
    while(append_m[i]!='\0')    
    {
        crc[k++]=append_m[i++];
    }
    crc[k]='\0';
    puts(crc);
       
       
    for(i=0;i<n;i++)
        send_m[i]=msg[i];
       
     //appending the crc with the message before sending
    for(i=0;i<size_gen-2;i++)
        send_m[n+i]=crc[i];
    send_m[n+i]='\0';
    printf("\n\nthe message sent is\n");
    puts(send_m);
    
    printf("\n\nenter the message that is recieved\n");
    while((c=getchar())!='\n')
    {
        recieve_msg[m++]=c;
    }
    recieve_msg[m]='\0';
    printf("\n\nthe message recieved is\n");
    puts(recieve_msg);
    
     for(i=0;i<n;i++)
    {
        if(recieve_msg[i]=='1')
        {
            for(j=0;j<size_gen-1;j++)
            {
                if(recieve_msg[i+j]==gen[j])
                {
                    recieve_msg[i+j]='0';
                }
                else
                {
                    recieve_msg[i+j]='1';
                }
           }
       }
    }
    
    
    for(i=n;i<n+m;i++)
     rem[l++]=recieve_msg[i];
     
   //check if reminder is NOT ZERO
     
   for(i=0;i<l;i++)
    {
        if(rem[i]=='1'){
            printf("\n\nError in the message!! :(\n");
            return 0;
            }
     }
     printf("\n\nthe message is error free!! :)\n");
     
     return 0;
}
    
    
    

        
    
    
    
    
    
