#include<stdio.h>
#define max 10
int F(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		return 2;
		case '*':
		case '/':
		case '%':
		return 4;
		case '^':
		case '$':
		return 5;
		case '(':
		return 0;
		case '#':
		return -1;
		default:
		return 8;
	}
}
int G(char c)
{
	switch(c)
	{
		case '+':
		case '-':
		return 1;
		case '*':
		case '/':
		case '%':
		return 3;
		case '^':
		case '$':
		return 6;
		case ')':
		return 0;
		case '(':
		return 9;
		default:
		return 7;
	}
}
char pop(char s[max],int *top)
{
	if((*top)==-1)
	{
		printf("underflow condition\n");
	}
	else
	{
		char elem;
		elem =s[*top];
		(*top)--;
		return elem;
	}
}
void push(char s[max],int *top,char elem)
{
	if((*top)==max-1)
	{
		printf("underflow condition");
		return;
	}
	(*top)++;
	s[*top]=elem;
}
void convert_postfix(char infix[max])
{
	int i=0,j=0,top=-1;
	char s[max],symbol,postfix[max];
	push(s,&top,'#');
	while(infix[i]!='\0')
	{
		symbol=infix[i];
		while(F(s[top])>G(symbol))
		{
			postfix[j]=pop(s,&top);
			j++;
		}
		if(F(s[top])!=G(symbol))
			push(s,&top,symbol);
		else
			pop(s,&top);
		i++;
	}
	while(top!=0)
	{
		postfix[j]=pop(s,&top);
		j++;
	}
	postfix[j]='\0';
	printf("The postfix expression is \n");
	printf(" %s\n",postfix);
}
int main()
{
	char infix[max];
	printf("Enter infix expression \n");
	scanf(" %s",infix);
	convert_postfix(infix);
	return 0;
}
