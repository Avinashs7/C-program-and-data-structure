#include<stdio.h>
#include<stdlib.h>

void push(int *s,int *top,int elem)
{
	if(*top==-1)
	{
		(*top)++;
		s[*top]=elem;
	}
	else
	{
		s=(int*)realloc(s,sizeof(int)*((*top)+1));
		(*top)++;
		s[*top]=elem;
	}
}
void pop(int *s,int *top)
{
	int elem;
	if(*top==0)
	{
		s[*top]=0;
		(*top)--;
	}
	else
	{
		elem=s[*top];
		(*top)--;
		s=(int*)realloc(s,sizeof(int)*((*top)+1));
		printf("%d element is poped\n",elem);
	}
}
void display(int *s,int top)
{
	int i;
	printf("displaying elements in stack are:\n");
	for(i=0; i<=top; i++)
		printf("%d\t",s[i]);
	printf("\n");
}
int main()
{
	int *s,op,top=-1,elem;
	s=(int*)malloc(sizeof(int)*1);
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
