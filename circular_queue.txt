#include<stdio.h>
#define max 4
void insert(int Q[max],int *rear,int *count,int elem)
{
	if(*count == max)
	{
		printf("insertion is not possible\n");
		return;
	}
	(*rear)=((*rear)+1)%max;
	Q[*rear]=elem;
	(*count)++;
}
void delete(int Q[max],int *front,int *count)
{
	if(*count == 0)
	{
		printf("deletion is not possible\n");
		return;
	}
	int elem;
	elem=Q[*front];
	(*front)=((*front)+1)%max;
	(*count)--;
	printf("The deleted element is %d\n",elem);
}
void display(int Q[max],int front,int count)
{
	int i;
	if(count ==0)
	{
		printf("No elements to display\n");
		return;
	}
	printf("The elements in queue is \n");
	for(i=front;count>0;i=(i+1)%max,count--)
	{
		printf("%d\t",Q[i]);
	}
	printf("\n");
}
int main()
{
	int Q[max],rear=max-1,front=0,count=0,op,elem;
	while(1)
	{
		printf("enter an option\n");
		printf("1:insert\n2:delete\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("enter an element to be inserted\n");
			scanf("%d",&elem);
			insert(Q,&rear,&count,elem);
			break;
			case 2:
			delete(Q,&front,&count);
			break;
			case 3:
			display(Q,front,count);
			break;
			default:
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}
