#include<stdio.h>
#define max 20
typedef
struct employee
{
	int eid;
	char name[20];
}E;
void push(E s[max],int *top,E elem)
{
	if(*top==max-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*top)++;
	s[*top]=elem;
}
void pop(E s[max],int *top)
{
	E elem;
	if(*top==-1)
	{
		printf("underflow condition\n");
		return;
	}
	elem=s[*top];
	(*top)--;
	printf("employee is poped\n");
	printf("employee id :%d\n",elem.eid);
	printf("employee name :%s\n",elem.name);
}
void display(E s[max],int top)
{
	int i;
	printf("displaying elements in stack are:\n");
	for(i=0; i<=top; i++)
	{
		printf("employee id :%d\n",s[i].eid);
		printf("employee name :%s\n",s[i].name);
	}
	printf("\n");
}
int main()
{
	int op,top=-1;
	E s[max],elem;
	while(1)
	{
		printf("Enter an option to perform operation\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter employee structure to be pushed\n");
			printf("enter employee id\n");
			scanf("%d",&elem.eid);
			printf("enter employee name\n");
			scanf("%s",elem.name);
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
