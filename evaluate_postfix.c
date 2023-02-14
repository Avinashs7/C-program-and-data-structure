#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define max 20
int compute(int op1,char op, int op2)
{
	switch(op)
	{
		case '+':
		return op1+op2;
		case '-':
		return op1-op2;
		case '*':
		return op1*op2;
		case '/':
		return op1/op2;
		case '%':
		return op1%op2;
		case '^':
		return pow(op1,op2);
		default:
		printf("invlaid operation\n");	
	}
}
void push(int s[max],int *top,int elem)
{
	if(*top==max-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*top)++;
	s[*top]=elem;
}
int pop(int s[max],int *top)
{
	int elem;
	if(*top==-1)
	{
		printf("underflow condition\n");
	}
	elem=s[*top];
	(*top)--;
	return elem;
}
int evaluate(char postfix[max])
{
	char op;
	int i=0,top=-1,op2,op1,res,s[max];
	while(postfix[i]!='\0')
	{
		if(isdigit(postfix[i]))
			push(s,&top,postfix[i]-'0');
		else
		{
			op2=pop(s,&top);
			op1=pop(s,&top);
			op=postfix[i];
			push(s,&top,compute(op1,op,op2));
		}
		i++;
	}
	return s[0];
}
int main()
{
	char postfix[max];
	printf("Enter a postfix expression \n");
	scanf("%s",postfix);
	printf("The evaluation of postfix expression leads to %d\n",evaluate(postfix));
	return 0;
}
