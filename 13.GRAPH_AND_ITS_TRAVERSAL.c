#include<stdio.h>
#define max 10
int g[max][max],q[max],f=-1,r=-1,visit[max];

int isempty()
{
    if(f==-1 || f>r)
        return 1;
    else 
        return 0;
}

void enqueue(int v)
{
    if(r==max-1)
        printf("\n Overflow ");
    else
    {
        if(f==-1)
            f=0;
        r=r+1;
        q[r]=v;
    }
}

int dequeue()
{
    int item;
    item=q[f];
    f=f+1;
    return item;
}

void dfs(int v,int n)
{
    printf("%d",v);
    visit[v]=1;
    for(int u=0;u<n;u++)
        if(g[v][u]==1 && visit[u]!=1)
            dfs(u,n);
}

void bfs(int v,int n)
{
    for(int i=0;i<n;i++) 
        visit[i]=0;
    enqueue(v);
    visit[v]=1;
    while(isempty()==0)
    {
        v=dequeue();
        printf(" %d ",v);
        visit[v]=2;
        for(int u=0;u<n;u++)
        {
            if(g[u][v]==1 && visit[u]==0)
            {
                enqueue(u);
                visit[u]=1;
            }
        }
    }
}

int main()
{
    int n;
    printf("\n Enter no of vertices");
    scanf("%d",&n);
    for(int u=0;u<n;u++)
    {
        for(int v=0;v<n;v++)
        {
            printf("\n Enter 1 if there exists and edge between %d,%d or else 0 ",u,v);
            scanf("%d",&g[u][v]);
        }
    }
    int ch;
    printf("\n 1. DFS 2.BFS ");
    scanf("%d",&ch);
    if(ch==1)
    {
        for(int i=0;i<n;i++)    
            visit[i]=0;
        dfs(0,n);
    }
    else
        bfs(0,n);
    return 0;
}