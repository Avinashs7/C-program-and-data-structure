#include<stdio.h>
#define max 10
void insert_rear(int Q[max],int *rear,int elem)
{
	if(*rear == max-1)
	{
		printf("insertion is not possible\n");
		return;
	}
	(*rear)++;
	Q[*rear]=elem;
}
void insert_front(int Q[max],int *front,int *rear,int elem)
{
	if(*rear==-1 && *front==0)
	{
		Q[*front]=elem;
		(*rear)++;
	}
	else if(*front!=0)
	{
		(*front)--;
		Q[*front]=elem;
	}
	else
		printf("Insertion is not possible\n");
}
void delete_front(int Q[max],int *front,int rear)
{
	if(*front>rear)
	{
		printf("deletion is not possible\n");
	}
	else 
	{
		int elem;
		elem=Q[*front];
		(*front)++;
		printf("The deleted element is %d\n",elem);
	}
}
void delete_rear(int Q[max],int *front,int *rear)
{
	if(*front>*rear)
	{
		printf("deletion is not possible\n");
	} 
	else 
	{
		int elem;
		elem=Q[*rear];
		(*rear)--;
		printf("The deleted element is %d\n",elem);
	}
}
void display(int Q[max],int front,int rear)
{
	int i;
	if(front>rear)
	{
		printf("No elements to display\n");
		return;
	}
	printf("The elements in queue is \n");
	for(i=front ; i<=rear ; i++)
	{
		printf("%d\t",Q[i]);
	}
	printf("\n");
}
int main()
{
	int Q[max],rear=-1,front=0,op,elem;
	while(1)
	{
		printf("enter an option\n");
		printf("1:insert from front\n2:insert from rear\n3:delete from front\n4:delete from rear\n5:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("enter an element to be inserted\n");
			scanf("%d",&elem);
			insert_front(Q,&front,&rear,elem);
			break;
			case 2:
			printf("enter an element to be inserted\n");
			scanf("%d",&elem);
			insert_rear(Q,&rear,elem);
			break;
			case 3:
			delete_front(Q,&front,rear);
			break;
			case 4:
			delete_rear(Q,&front,&rear);
			break;
			case 5:
			display(Q,front,rear);
			break;
			default:
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}
