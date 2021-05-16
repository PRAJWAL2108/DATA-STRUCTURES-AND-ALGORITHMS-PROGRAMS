#include<stdio.h>
#include<stdlib.h>
typedef struct Nodes
{
    int data;
    struct Nodes *left;
    struct Nodes *right;
}node;

node *search(node *root,int key)
{
    if(root==0)
        return 0;
    else if(key==root->data)
        return root->data;
    else if(key>root->data)
        return search(root->right,key);
    else
        return search(root->left,key);
}

node *allocate(int num)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=num;
    newnode->left=0;
    newnode->right=0;
    return newnode;
}

node *insert(node *root, int value)
{
    if(root==0)
        return allocate(value);
    else
    {
        if(value>root->data)
            root->right=insert(root->right,value);
        else
            root->left=insert(root->left,value);
    }
}

node *findmin(node *root)
{
    if(root->left==0)
        return root;
    else
        return findmin(root->left);
}

node *delete(node *root,int value)
{
    node *temp;
    if(root==0)
        return 0;
    else if(value>root->data)
        root->right=delete(root->right,value);
    else if(value<root->data)
        root->left=delete(root->left,value);
    else
    {
        if(root->left==0 && root->right==0) 
        {
            free(root);
            root=0;
        }
        else if(root->left==0)
        {
            temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==0)
        {
            temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            node *tnode=findmin(root->right);
            root->data=tnode->data;
            root->right=delete(root->right,tnode->data);
        }
        return root;
    }
}

void in_traversal(node *root)
{
    if(root!=0)
    {
        in_traversal(root->left);
        printf(" %d ", root->data);
        in_traversal(root->right);
    }
}

int main()
{
    int ch,num;
    node *root=0,*found;
    do{
        printf("\n 1.insert 2.delete 3.search 4.inorder traversal \n Enter choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n Enter element to insert ");
                    scanf("%d",&num);
                    root=insert(root,num);
                    break;
            case 2: printf("\n Enter element to delete ");
                    scanf("%d",&num);
                    root=delete(root,num);
                    break;
            case 3: printf("\n Enter element to search ");
                    scanf("%d",&num);
                    found=search(root,num);
                    if(found!=0)
                        printf("\n Element found ");
                    else
                        printf("\n Element not found ");
                    break;
            case 4: in_traversal(root);
                    break;
            default: printf("\n Enter valid choice "); break;
        }
    }while(ch<=4);
    return 0;
}