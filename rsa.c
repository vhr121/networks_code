#include<stdio.h>
#include<string.h>

unsigned int find_gcd(unsigned int a,unsigned int b)
{
    unsigned int r;
   do
    {
        r=b%a;
        b=a;
        a=r;
    }while(r!=0);
    return b;
    
}
unsigned int find_e(unsigned int to)
{
    int gcd,i;
    for(i=2;i<to;i++)
    {
        if((gcd=find_gcd(i,to))==1)
           break;
       
    }
    return i;
}

unsigned int find_d(unsigned int to,unsigned int e)
{
    unsigned int i;
    for(i=2;i<to;i++)
    {
        if((i*e)%to==1)
            break;
   }
   return i;
}
    
unsigned int power(unsigned int a,unsigned int b)
{
    unsigned int i,res=1;
    for(i=0;i<b;i++)
    {
        res=a*res;
    }
    return res;
}

int main()
{
    int len,flag[256],i,msg_r[256];
    char msg_s[256],encoded[256],decoded[256];
    //at the reciever end the below calculations are performed

    unsigned int p,q,n,to,e,d,c[256];
    do{
    
        printf("enter 2 large prime numbers\n");
        scanf("%d%d",&p,&q);
      }while(find_gcd(p,q)!=1);
      
    
    printf("%d %d",p,q);
    n=p*q;
    to=(p-1)*(q-1);
    
    e=find_e(to);
    
    d=find_d(to,e);
    
   
    
    
    
    printf("\n\nthe public keys (n,e) that is sent to the sender is (%d,%d)\n",n,e);
    
    
    //at the sender side the message is encrypted using public key
    
    printf("\n\nenter the message to be send using encryption\n");
    scanf("%s",msg_s);
    
    len=strlen(msg_s);
    
    for(i=0;i<len;i++)
    {
        if(msg_s[i]>='A'&msg_s[i]<='z')
        {
            if(msg_s[i]>='A'&msg_s[i]<='Z')
            {
                flag[i]=1;
                encoded[i]=msg_s[i]-65;
             }
             else if(msg_s[i]>='a'&msg_s[i]<='z')
             {
                flag[i]=0;
                encoded[i]=msg_s[i]-97;
             }
         }
         else
            continue;
     }
    for(i=0;i<len;i++)
    {
    c[i]=power(encoded[i],e)%n;
    }
    printf("\n\nthe encrypted message is :\t ");
    for(i=0;i<len;i++)
    {
        printf("%d",c[i]);
    }
    
    //at the reciever the message recieved is decrypted
     for(i=0;i<len;i++)
     {
        msg_r[i]=(power(c[i],d))%n;
     }
    
    
    for(i=0;i<len;i++)
    {
        
           if(flag[i]==1)
           {
                decoded[i]=msg_r[i]+65;
           }
           else if(flag[i]==0)
           {
            decoded[i]=msg_r[i]+97;
           }
           else
           {
                printf("error\n");
           }
           
    }
    
   printf("\n the decoded message is :\n");
   for(i=0;i<len;i++)
   printf("%c",decoded[i]);
   printf("\n\n");
   
    
        
    
}



