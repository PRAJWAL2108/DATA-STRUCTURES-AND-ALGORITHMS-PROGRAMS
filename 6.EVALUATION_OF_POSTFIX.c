#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int top=-1,num[max],i=0,stack[max];
char postfix[max];

int eval()
{
    strcat(postfix,")");
    while(postfix[i]!='\0')
    {
        char ch=postfix[i];
        if(isalnum(ch))
        {
            printf("\n Enter value %c ",ch);
            scanf("%d",&num[i]);
            stack[++top]=num[i];
        }
        else if(ch==')')
            return stack[top];
        else
        {
            int n1,n2;
            n1=stack[top--];
            n2=stack[top--];
            switch(ch)
            {
                case '+' : stack[++top]=n2+n1; break;
                case '-' : stack[++top]=n2-n1; break;
                case '/' : stack[++top]=n2/n1; break;
                case '*' : stack[++top]=n2*n1; break;
                case '^' : stack[++top]=pow(n2,n1); break;
            }
        }
        i++;
    }
}

int main()
{
    int r;
    printf("\n Enter postfix expression ");
    scanf("%s",postfix);
    r=eval();
    printf("\n Result = %d",r);
    return 0;
}