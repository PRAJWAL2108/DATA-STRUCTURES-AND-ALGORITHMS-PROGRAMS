#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes
{
    int cf;
    int ex;
    struct Nodes *next;
}node;

node *newnode=0;

node allocate(int c,int e)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->cf=c;
    newnode->ex=e;
    newnode->next=0;
}

node *create()
{
    node *tail=0;
    int c,e,ch=1;
    while(ch!=0)
    {
        printf("\n Enter co-efficient and expression\n");
        scanf("%d%d",&c,&e);
        allocate(c,e);
        if(tail==0)
        {
            tail=newnode;
            tail->next=newnode;
        }
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("\nEnter 1 to continue or 0 to exit");
        scanf("%d",&ch);
    }
    return tail;
}

node *insert(node *tail)
{
    if(tail==0)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    return tail;
}

node *addpoly(node *tail1,node *tail2,node *tail3)
{
    node *temp1=tail1->next,*temp2=tail2->next;
    while(temp1!=tail1 && temp2!=tail2)
    {
        if(temp1->ex==temp2->ex)
        {
            allocate(temp1->cf+temp2->cf,temp1->ex);
            tail3=insert(tail3);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->ex>temp2->ex)
        {
            allocate(temp1->cf,temp1->ex);
            tail3=insert(tail3);
            temp1=temp1->next;
        }
        else
        {
            allocate(temp2->cf,tail2->ex);
            tail3=insert(tail3);
            temp2=temp2->next;
        }
    }
    if(temp1->ex==temp2->ex)
    {
        allocate(temp1->cf+temp2->cf,temp1->ex);
        tail3=insert(tail3);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    else if(temp1->ex>temp2->ex)
    {
        allocate(temp1->cf,temp1->ex);
        tail3=insert(tail3);
        temp1=temp1->next;
    }
    else
    {
        allocate(temp2->cf,tail2->ex);
        tail3=insert(tail3);
        temp2=temp2->next;
    }
    while(temp1!=tail1->next)
    {
        allocate(temp1->cf,temp1->ex);
        tail3=insert(tail3);
        temp1=temp1->next;
    }
    while(temp2!=tail2->next)
    {
        allocate(temp2->cf,temp2->ex);
        tail3=insert(tail3);
        temp2=temp2->next;
    }
}

void display(node *tail)
{
    node *temp=tail->next;
    do{
        printf(" %dx^%d+",temp->cf,temp->ex);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("0");
}

int main()
{
    node *tail1=0,*tail2=0,*tail3=0;
    printf("\n Enter first polynomial expression");
    tail1=create();
    printf("\n Enter second polynomial expression");
    tail2=create();
    tail3=addpoly(tail1,tail2,tail3);
    display(tail3);
    return 0;
}
