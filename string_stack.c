#include<stdio.h>
#include<string.h>
#define max 20
void push(char s[max][10],int *top,char elem[10])
{
	if(*top==max-1)
	{
		printf("overflow condition\n");
		return;
	}
	(*top)++;
	strcpy(s[*top],elem);
}
void pop(char s[max][10],int *top)
{
	char elem[10];
	if(*top==-1)
	{
		printf("underflow condition\n");
		return;
	}
	strcpy(elem,s[*top]);
	(*top)--;
	printf("%s element is poped\n",elem);
}
void display(char s[max][10],int top)
{
	int i;
	if(top==-1)
	printf("No elements in stack\n");
	else
	{
		printf("displaying elements in stack are:\n");
		for(i=0; i<=top; i++)
			printf("%s\t",s[i]);
	}
	printf("\n");
}
int main()
{
	char s[max][10],elem[10];
	int op,top=-1;
	while(1)
	{
		op=0;
		printf("Enter an option to perform operation\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter element to be pushed\n");
			scanf(" %s",elem);
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
