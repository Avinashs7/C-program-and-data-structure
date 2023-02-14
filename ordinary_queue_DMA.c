#include<stdio.h>
#include<stdlib.h>
int *insert(int *Q,int *rear,int elem)
{
	if(*rear == -1)
	{
		(*rear)++;
		Q[*rear]=elem;
		return Q;
	}
	Q=(int*)realloc(Q,sizeof(int)*((*rear)+2));
	(*rear)++;
	Q[*rear]=elem;
	return Q;
}
int *delete(int *Q,int *front,int *rear)
{
	if(*rear==-1)
	{
		printf("No elements in Queue\n");
	}
	if(*front==*rear)
	{
		printf("the deleted element is %d\n",Q[*front]);
		free(Q);
		(*rear)=-1;
		return 0;
	}
	else
	{
		printf("the deleted element is %d\n",Q[*front]);
		for(int i=0; i<=*rear;i++)
			Q[i]=Q[i+1];
		Q=(int*)realloc(Q,sizeof(int)*((*rear)+1));
		(*rear)--;
		return Q;
	}
}
void display(int *Q,int rear,int front)
{
	if(front>rear)
	{
		printf("No elements to display\n");
		return;
	}
	printf("The elements in Queue are\n");
	for( ; front<=rear;front++)
		printf("%d\t",Q[front]);
	printf("\n");
}
int main()
{
	int *Q,rear=-1,front=0,elem,op;
	Q=(int*)malloc(sizeof(int));
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
			insert(Q,&rear,elem);
			break;
			case 2:
			delete(Q,&front,&rear);
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
