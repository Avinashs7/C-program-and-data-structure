#include<stdio.h>
#define max 20
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
void pop(int s[max],int *top)
{
	int elem;
	if(*top==-1)
	{
		printf("underflow condition\n");
		return;
	}
	elem=s[*top];
	(*top)--;
	printf("%d element is poped\n",elem);
}
void display(int s[max],int top)
{
	int i;
	printf("displaying elements in stack are:\n");
	for(i=0; i<=top; i++)
		printf("%d\t",s[i]);
	printf("\n");
}
int main()
{
	int s[max],op,top=-1,elem;
	while(1)
	{
		printf("Enter an option to perform operation\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter element to be pushed\n");
			scanf("%d",&elem);
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
