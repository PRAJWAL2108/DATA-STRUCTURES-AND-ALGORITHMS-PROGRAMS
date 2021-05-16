#include<stdio.h>
void merge(int nl, int nr, int na, int left[], int right[], int a[])
{
    int i=0,j=0,k=0;
    while(i<nl && j<nr)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
            k++;
        }
        else
        {
            a[k]=right[j];
            j++;
            k++;
        }
    }
    while(i<nl)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        a[k]=right[j];
        j++;
        k++;
    }
}

void merge_sort(int n,int a[])
{
    int m,left[n],right[n];
    if(n<2)
        return;
    else
    {
        m=n/2;
        for(int i=0;i<m;i++)
            left[i]=a[i];
        for(int j=m;j<n;j++)    
            right[j-m]=a[j];
        merge_sort(m,left);
        merge_sort(n-m,right);
        merge(m,n-m,n,left,right,a);
    }
}

void display(int n,int a[])
{
    printf("\n Sorted elements ");
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
    merge_sort(n,a);
    display(n,a);
    return 0;
}