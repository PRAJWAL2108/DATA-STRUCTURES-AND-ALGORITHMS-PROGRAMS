#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes
{
    int data;
    struct Nodes *next;
}node;

node *head=0,*temp=0,*newnode=0,*top=0;

void allocate()
{
    newnode=(node*)malloc(sizeof(node));
    printf("\n Enter element to be pushed into stack ");
    scanf("%d", &newnode->data);
    newnode->next=0;
}

int isempty()
{
    if(top==0)
        return 1;
    else
        return 0;
}

void push()
{
    allocate();
    if(isempty()==1)
    {
        top=newnode;
        head=newnode;
    }
    else
    {
        top->next=newnode;
        top=newnode;
    }
}

void peek()
{
    if(!isempty())
        printf("\n Top of stack is %d",top->data);
    else
        printf("\n No element is present at top of stack ");
}

void display()
{
    if(!isempty())
    {
        temp=head;
        while(temp!=top)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf(" %d \n ",temp->data);
    }
    else
        printf("\n Stack Underflow");
}

void pop()
{
    node *prev;
    temp=top;
    if(isempty()==1)
        printf("\n No element in stack to be removed is present ");
    else if(head==top)
    {
        printf("\n %d is deleted from stack ",top->data);
        head=0;
        top=0;
        free(temp);
    }
    else
    {
        printf("\n %d is deleted from stack ",temp->data);
        temp=head;
        while(temp!=top)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=0;
        top=prev;
        free(temp);
    }
}

int main()
{
    int ch;
    do{
        printf("\n 1.push 2.pop 3.peek 4.display \n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            default : printf("\n Enter valid choice "); break;
        }
    }while(ch<=4);
    return 0;
}