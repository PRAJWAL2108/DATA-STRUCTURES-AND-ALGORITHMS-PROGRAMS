#include<stdio.h>
int partition(int a[],int p,int r)
{
    int x=a[r],temp,i=p,j;
    for(j=p;j<r;j++)
    {
        if(a[j]<x)
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    temp=a[i];
    a[i]=a[r];
    a[r]=temp;
    return i;
}

void quick_sort(int a[],int p,int r)
{
    int q=a[r];
    if(p<r)
    {
        q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

void display(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf(" %d ",a[i]);
}

int main()
{
    int n;
    printf("\n Enter no of elements ");
    scanf("%d",&n);
    int a[n];
    printf("\n Enter %d elements ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    display(a,n);
    return 0;
}