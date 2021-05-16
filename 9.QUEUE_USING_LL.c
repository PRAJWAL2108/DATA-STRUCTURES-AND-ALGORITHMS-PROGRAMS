#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes
{
    int data;
    struct Nodes *next;
}node;

node *f=0,*newnode=0,*r=0,*temp=0;

void allocate()
{
    newnode=(node*)malloc(sizeof(node));
    printf("\n Enter element to enqueue ");
    scanf("%d",&newnode->data);
    newnode->next=0;
}

int isempty()
{
    if(f==0 && r==0)
        return 1;
    else
        return 0;
}

void enqueue()
{
    allocate();
    if(isempty()==1)
    {   
        f=newnode;
        r=newnode;
    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}

void dequeue()
{
    node *prev;
    if(isempty()==1)
        printf("\n No element is present for deletion in queue ");
    else if(f==r)
    {
        prev=f;
        printf("\n %d is deleted from queue ",f->data);
        r=0;
        f=0;
        free(prev);
    }
    else
    {
        printf("\n %d is deleted from queue ",f->data);
        f=f->next;
    }
}

void display()
{
    if(!isempty())
    {
        temp=f;
        while(temp!=r)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
        printf(" %d \n",temp->data);
    }
    else
        printf("\n Queue underflow ");
}

int main()
{
    int ch;
    do{
        printf("\n 1.enqueue 2.dequeue 3.display \n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            default : printf("\n Enter valid choice "); break;
        }
    }while(ch<=3);
    return 0;
}


    
    
    
    
    
    
    
    
    
    
