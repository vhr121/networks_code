#include<stdio.h>
int main()
{
    int bckt_size,time,opt_rate,store=0,rem_size,packet_drop,opt_packets,i,packet_size[100];
    printf("enter the bucket size in bytes\n");
    scanf("%d",&bckt_size);
    rem_size=bckt_size;
    
    printf("enter the simulation time\n");
    scanf("%d",&time);
    
    printf("enter the output rate in bytes\n");
    scanf("%d",&opt_rate);
    
    for(i=0;i<time;i++)
    {
        printf("enter the packet size arrived at the time %d:",i);
        scanf("%d",&packet_size[i]);
    }
    
    printf("Time\tPacket Size\toutput packets\tstore\tpacket drop\n\n");
    for(i=0;i<time;i++)
    {
        
            
        if(packet_size[i]>=rem_size)
        {
            packet_drop=packet_size[i]-rem_size;
            rem_size=0;
            store=bckt_size;
            
        }
        else
        {
            rem_size-=packet_size[i];
            store+=packet_size[i];
            packet_drop=0;
        }
        
        if(store<=0){
            store=0;
            rem_size=bckt_size;}
        else
        {
            if(store<opt_rate) 
            {
                opt_packets=store;
                store=0;
                rem_size=bckt_size;
                
            }
            else{
                store-=opt_rate;
                opt_packets=opt_rate;
                rem_size+=opt_rate;
                }
        }
            
        printf("%d\t %d\t\t\t %d\t %d\t %d\t\n\n",i,packet_size[i],opt_packets,store,packet_drop);
       }
       
       while(store!=0)
       {
            
            if(store<opt_rate)
            {
                opt_packets=store;
                store=0;
                rem_size=bckt_size;
            }
            else{
                store-=opt_rate;
                opt_packets=opt_rate;
                rem_size+=opt_rate;
                }
                packet_drop=0;
                i++;
            printf("%d\t %d\t\t\t %d\t %d\t %d\t\n\n",i,0,opt_packets,store,packet_drop);
       }
                
 }
    
