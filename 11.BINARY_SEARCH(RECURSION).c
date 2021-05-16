#include<stdio.h>
#include<stdlib.h>

int binary(int a[],int l,int h,int x)
{
    int m;
    if(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==x)
            return m;
        else if(a[m]>x)
            return binary(a,l,m-1,x);
        else  
            return binary(a,m+1,h,x);
    }
    else
        return -1;
}

int main()
{
    int n,x;
    printf("\n Enter no of elements ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter elements ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n Enter search element");
    scanf("%d",&x);
    int r=binary(a,0,n-1,x);
    if(r==-1)
        printf("%d not found",x);
    else
        printf("\n %d found at %d",x,r+1);
    return 0;
}