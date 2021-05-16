#include<stdio.h>
void search(int m,int n,int a[][n],int ele)
{
    int flag=0;
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<n;j++)
        {
            if(ele==a[i][j])
                printf("\n %d found at location %d,%d",ele,i+1,j+1);
                flag=1;
        }
    }
    if(flag==0)
        printf("\n %d not found",ele);
}

int main()
{
    int n,m,ele;
    printf("\n Enter size of array");
    scanf("%d%d",&m,&n);
    int a[m][n];
    printf("\n Enter array elements");
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &a[i][j]);
    printf("\n Enter search element");
    scanf("%d",&ele);
    search(m,n,a,ele);
}