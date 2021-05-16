#include<stdio.h>
#define max 10
int stack[max],top=-1,item;

int isempty()
{
    if(top==-1)
        return 1;
    else 
        return 0;
}

int isfull()
{
    if(top==max-1)
        return 1;
    else return 0;
}

void push()
{
    if(isfull()==1)
        printf("\n Stack Overflow");
    else
        printf("\n Enter element");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
}

void pop()
{
    if(isempty()==1)
        printf("\n Stack Underflow");
    else
        item=stack[top];
        top=top-1;
        printf("\n Deleted element is %d",item);
}

void peek()
{
    printf(" element at top is %d",stack[top]);
}

void display()
{
    printf("\n Stack elements are : ");
    for(int i=0;i<=top;i++)
        printf(" %d ",stack[i]);
}

int main()
{
    int ch;
    do{
        printf("\n 1.push 2.pop 3.peek 4.display\n Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : peek(); break;
            case 4 : display(); break;
            default : printf("\n Enter valid choice"); break;
        }
    }while(ch<6);
    return 0;
}