#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes
{
    int data;
    struct Nodes *next;
}node;

node *allocate()
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    printf("\n Enter element ");
    scanf("%d", &newnode->data);
    newnode->next-0;
    return newnode;
}

node *create(node *head)
{
    int n=0;
    node *newnode,*prev;
    while(n==0)
    {
        newnode=allocate();
        if(head==0)
        {
            head=newnode;
            prev=newnode;
        }
        else
        {
            prev->next=newnode;
            prev=newnode;
        }
        printf("\n Enter 0 to continue or 1 to exit ");
        scanf("%d",&n);
    }
    return head;
}

void display(node *head)
{
    node *temp=head;
    while(temp!=0)
    {
        printf(" %d -> ",temp->data);
        temp=temp->next;
    }
    printf(" null ");
}

node *ib(node *head)
{
    node *newnode;
    newnode=allocate();
    newnode->next=head;
    head=newnode;
    return newnode;    
}

node *im(node *head)
{
    node *temp=head,*newnode=allocate();
    int pos,i=1;
    printf("\n Enter position of insertion ");
    scanf("%d",&pos);
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

node *ie(node *head)
{
    node *temp=head,*newnode=allocate();
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

node *db(node *head)
{
    node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

node *dm(node *head)
{
    node *temp=head,*prev;
    int pos,i=1;
    printf("\n Enter position of deletion ");
    scanf("%d",&pos);
    while(i<=pos-1)
    {
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}

node *de(node *head)
{
    node *temp=head;
    node *prev;
    while(temp->next!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=0;
    return head;
}

int main()
{
    node *head=0;
    int ch;
    do{
        printf("\n 1.create 2.display 3.insert @ start 4.insert @ middle 5.insert @ end 6.delete @ start 7.delete @ middle 8.delete @ end \n Enter choice ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: head=create(head); break;
            case 2: display(head); break;
            case 3: head=ib(head); break;
            case 4: head=im(head); break;
            case 5: head=ie(head); break;
            case 6: head=db(head); break;
            case 7: head=dm(head); break;
            case 8: head=de(head); break;
            default : printf("\n Enter valid choice ");
        }
    }while(ch<=8);
    return 0;
}





















