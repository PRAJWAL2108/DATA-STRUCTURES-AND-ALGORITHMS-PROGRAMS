#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define max 50
char infix[max],postfix[max],stack[max];
int j=-1,top=-1;

int pre(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else 
        return 0;
}

void conversion()
{
    int i=0;
    strcat(infix,")");
    stack[++top]='(';
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(ch=='(')
            stack[++top]=ch;
        else if(isalnum(ch))
            postfix[++j]=ch;
        else if(ch==')')
        {
            while(stack[top]!='(')
            {
                postfix[++j]=stack[top];
                top--;
            }
            top--;
        }
        else
        {
            if(pre(ch)>pre(stack[top]))
            {
                stack[++top]=ch;
            }
            else
            {
                while(pre(ch)<=pre(stack[top]))
                {
                    postfix[++j]=stack[top];
                    top--;
                }
                stack[++top]=ch;
            }
        }
        i++;
    }
}

int main()
{
    printf("\n Enter infix expression ");
    scanf("%s",infix);
    conversion();
    printf("\n Postfix expression ");
    printf("%s",postfix);
    return 0;
}