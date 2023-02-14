#include<stdio.h>
#define max 10
typedef struct Employee
{
	int eid;
	char en[10];
}E;

void insert(E Q[max],int *rear,E elem)
{
	if(*rear == max-1)
	{
		printf("Insertion not possible\n");
		return;
	}
	(*rear)++;
	Q[*rear]=elem;
}
void delete(E Q[max],int front,int *rear)
{
	if(front>*rear)
	{
		printf("No elements in Queue\n");
	}
	else
	{
		printf("the deleted structure is \n");
		printf("Employee name %s\n",Q[front].en);
		printf("Employee ID %d\n",Q[front].eid);
		for(int i=0; i<=*rear;i++)
			Q[i]=Q[i+1];
		(*rear)--;
	}
}
void display(E Q[max],int rear,int front)
{
	if(front>rear)
	{
		printf("No elements to display\n");
		return;
	}
	printf("The elements in Queue are\n");
	for( ; front<=rear;front++)
	{
		printf("Employee name %s\n",Q[front].en);
		printf("Employee ID %d\n",Q[front].eid);
	}
	printf("\n");
}
int main()
{
	E Q[max],elem;
	int rear=-1,front=0,op;
	while(1)
	{
		printf("enter an option\n");
		printf("1:insert\n2:delete\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("enter structure to be inserted\n");
			printf("Employee name\n");
			scanf("%s",elem.en);
			printf("Employee id\n");
			scanf("%d",&elem.eid);
			insert(Q,&rear,elem);
			break;
			case 2:
			delete(Q,front,&rear);
			break;
			case 3:
			display(Q,rear,front);
			break;
			default:
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}	
