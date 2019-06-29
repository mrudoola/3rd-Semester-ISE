#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int top=-1,i=0,stack[30];
char postfix[30];
void push(int element)
{
    top++;
   stack[top]=element;
}
int pop()
{
   return stack[top--];
}

int valid()
{
  int digits=0,operators=0,i;
  
  if(!(isdigit(postfix[0]) && isdigit(postfix[1]))) 
    return(0);

  for(i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i])) 
      digits++;  
    else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
      operators++;  
    else
      return (0);
  }

  if(digits-operators!=1)  
    return (0);

  return (1);
}
void main()
{
	char ch;
	int op2,op1;
	while(1)
	{
		printf("Enter the postfix expression\n");
		scanf("%s",postfix);
		if(valid())
		break;
		else
		printf("Invalid");
	}
	for(i=0;postfix[i]!='\0';i++)
	{
		ch=postfix[i];
		if(isdigit(ch))
		push(ch-48);
		else
		{
			op2=pop();
			op1=pop();
			switch(ch)
			{
				case '+':push(op1+op2);
				    break;
				case '-':push(op1-op2);
				    break;
				case '*':push(op1*op2);
				    break;
				case '/':push(op1/op2);
				    break;
			}
		}
	}
	printf("Result is %d\n",stack[top]);
}