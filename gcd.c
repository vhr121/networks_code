#include<stdio.h>
int find_gcd(int a,int b)
{
    int r;
   while(r!=0)
    {
        r=b%a;
        b=a;
        a=r;
    }
    return b;
    
}
int main()
{
    int a,b;
    printf("enter 2 no");
    scanf("%d%d",&a,&b);
    printf("gcd=%d",find_gcd(a,b));
}
