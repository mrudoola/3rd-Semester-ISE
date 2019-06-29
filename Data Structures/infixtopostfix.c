#include<stdio.h>
#include<ctype.h>
int top=-1,popped,i=0,k=0;
char a[20],postfix[20],stack[20],j;
void push(char element)
{
    if(top==20)
    printf("Stack full");
    else
    top++;
    stack[top]=element;
}   
int pop()
{
    popped=stack[top];
    top--;
    return popped;
}
int priority(char symbol)
{
    switch(symbol)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
        case '$':
        case '^':return 4;
    }
}
void infixtopostfix(char infix[])
{
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
             postfix[k++]=infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            postfix[k++]=pop();
            j=pop();
        }
        else
        {
            if(stack[top]=='('||top==-1)
                push(infix[i]);
            else if(priority(stack[top])<priority(infix[i]))
                push(infix[i]);
            else
            {
                while(top!=-1&&(priority(stack[top])>=priority(infix[i])))
                postfix[k++]=pop();
                push(infix[i]);
            }
        }
    }
        int i;
        for(i=top;i>=0;i--)
        postfix[k++]=pop();
        postfix[k]='\0';
        printf("%s",postfix);
        
    }
void main()
{
    printf("Enter the infix expression");
    char a[20];
    scanf("%s",a);
    infixtopostfix(a);
}