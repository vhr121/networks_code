#include<stdio.h>
#define MAXL 10
typedef struct
{
    int dist[MAXL];
    int next[MAXL];
}n;

int main()
{
    n node[10];
    int s,i,j,cost[MAXL][MAXL],count,k;
    printf("enter the number of nodes\n");
    scanf("%d",&s);
    
    printf("enter the cost matrix\n");
    for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        {
            scanf("%d",&cost[i][j]);
            node[i].dist[j]=cost[i][j];
            node[i].next[j]=j;
         }
    }
    
    /*for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        printf("%d %d\n",node[i].dist[j],node[i].next[j]);
    }*/
    do
    {
        count =0;
    
        for(i=0;i<s;i++)
        {
            for(j=0;j<s;j++)
            {
                for(k=0;k<s;k++)
                {
                    if(node[i].dist[j]>(node[i].dist[k]+node[k].dist[j]))
                    {
                        node[i].dist[j]=node[i].dist[k]+node[k].dist[j];
                        node[i].next[j]=k;
                        count++;
                    }
               }
            }
         }
        }while(count!=0);
    
  printf("the shortest distance vector for each node is\n");
  for(i=0;i<s;i++)
  {
        printf("for node %d  to\n",i);
        for(j=0;j<s;j++)
        {
            printf("%d is %d and next hop:%d\n",j,node[i].dist[j],node[i].next[j]);
        }
    
    }
}
