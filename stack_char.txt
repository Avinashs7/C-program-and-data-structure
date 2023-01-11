#include<stdio.h>
#include<ctype.h>
#define max 20
void push(char s[max],int *top,char elem)
{
	if(*top==max-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*top)++;
	s[*top]=elem;
}
void pop(char s[max],int *top)
{
	char elem;
	if(*top==-1)
	{
		printf("underflow condition\n");
		return;
	}
	elem=s[*top];
	(*top)--;
	printf("%c element is poped\n",elem);
}
void display(char s[max],int top)
{
	int i;
	printf("displaying elements in stack are:\n");
	for(i=0; i<=top; i++)
		printf("%c\t",s[i]);
	printf("\n");
}
int main()
{
	char s[max],elem;
	int op,top=-1;
	while(1)
	{
		op=4;
		printf("Enter an option to perform operation\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter element to be pushed\n");
			scanf(" %c",&elem);
			push(s,&top,elem);
			break;
			case 2:
			pop(s,&top);
			break;
			case 3:
			display(s,top);
			break;
			default:
			printf("invalid operation\n");
			return 0;
		}
	}
	return 0;
}
