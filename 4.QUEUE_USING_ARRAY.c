#include<stdio.h>
#define max 10
int q[max],f=-1,r=-1,key;

int isempty()
{
    if(f==-1 || f>r)
        return 1;
    else
        return 0;
}

int isfull()
{
    if(r==max-1)
        return 1;
    else 
        return 0;
}

void enqueue()
{
    if(isfull()==1)
        printf("\n Queue Overflow");
    else
    {
        printf("\n Enter element to enqueue");
        scanf("%d",&key);
        if(f==-1)
        {
            f=0;
            r=0;
        }
        else
        {
            r=r+1;
        }
    }
    q[r]=key;
}

void dequeue()
{
    if(isempty()==1)
        printf("\n Queue Underflow");
        break;
    else
        f++;
        printf("deleted element is: %d",f);
}

void display()
{
    printf("\n Queue elements are : ");
    for(int i=f;i<=r;i++)
        printf(" %d ",q[i]);
}

int main()
{
    int ch;
    do{
        printf("\n 1.enqueue 2.dequeue 3.display\n Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : display(); break;
            default : printf("\n Enter valid choice"); break;
        }
    }while(ch<4);
    return 0;
}