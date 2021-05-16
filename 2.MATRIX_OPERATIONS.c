#include<stdio.h>
void add(int m,int n,int p,int q,int a[m][n],int b[p][q])
{
    if(m!=p && n!=q)
        printf("\n Addition of matrices not possible");
    else
    {
        int c[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j]=0;
                c[i][j]=a[i][j]+b[i][j];
                printf(" %d ",c[i][j]);
            }
            printf("\n");
        }
    }
}
void sub(int m,int n,int p,int q,int a[m][n],int b[p][q])
{
    if(m!=p && n!=q)
        printf("\n Subtraction of matrices not possible");
    else
    {
        int c[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                c[i][j]=0;
                c[i][j]=a[i][j]-b[i][j];
                printf(" %d ",c[i][j]);
            }
            printf("\n");
        }
    }
}
void product(int m,int n,int p,int q,int a[m][n],int b[p][q])
{
    if(n!=p)
        printf("\n Addition of matrices not possible");
    else
    {
        int c[m][q];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<q;j++)
            {
                c[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    c[i][j]+=a[i][k]*b[k][j];
                }
                printf(" %d ",c[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int m,n,p,q;
    printf("\n Enter size of array1");
    scanf("%d%d",&m,&n);
    printf("\n Enter size of array2");
    scanf("%d%d",&p,&q);
    int a[m][n],b[p][q];
    printf("\n Enter array1 elements");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\n Enter array2 elements");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int ch;
    printf("\n 1.addition 2.subtraction 3.multiplication\n Enter choice");
    scanf("%d",&ch);
    if(ch==1)
        add(m,n,p,q,a,b);
    else if(ch==2)
        sub(m,n,p,q,a,b);
    else if(ch==3)
        product(m,n,p,q,a,b);
    else
        printf("\n Enter valid choice");

    return 0;
}