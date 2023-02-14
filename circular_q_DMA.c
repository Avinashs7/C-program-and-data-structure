#include<stdio.h>
#include<stdlib.h>
int max=3;
int *insert_cq(int *q,int *rear,int *front,int *count,int elem)
{
	if(*count == max)
	{
		int *p,i,j,c=*count;
		max = 2*max;
		p = (int*)malloc(sizeof(int)*max);
		for(i= 0,j=(*front); c!=0 ;j=(j+1)%(max/2),c--,i++)
		p[i]=q[j];
		(*rear)=(max/2)-1;
		(*front) = 0;
		(*rear)=((*rear)+1)%max;
		p[*rear]=elem;
		(*count)++;
		return p;
	}
	(*rear)=((*rear)+1)%max;
	q[*rear]=elem;
	(*count)++;
	return q;
}
void delete_cq(int *q,int *front,int *count)
{
	if(*count ==0)
	{
		printf("no elements to delete\n");
		return;
	}
	printf("the element %d is deleted from queue\n",q[*front]);
	(*front)=((*front)+1)%max;
	(*count)--;
}
void display(int *q,int front,int count)
{
	if(count ==0)
	{
		printf("no elements to display\n");
		return;
	}
	printf("displaying the elements of queue\n");
	for(int i=front ;count>0; i=(i+1)%max,count--)
	printf("%d\t",q[i]);
	printf("\n");
}
int main()
{
	int *q,rear=max-1,front=0,count=0,op,elem;
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
			q=insert_cq(q,&rear,&front,&count,elem);
			break;
			case 2:
			delete_cq(q,&front,&count);
			break;
			case 3:
			display(q,front,count);
			break;
			default:
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}
