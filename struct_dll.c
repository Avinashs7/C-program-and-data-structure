#include<stdio.h>
#include<stdlib.h>
typedef struct employee
{
	char name[10];
	float esal;
	int eid;
}E;
struct node
{
	E info;
	struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x== NULL)
	{
		printf("Memory not available\n");
		exit(0);
	}
	return x;
}
NODE insert_front(NODE first,E elem)
{
	NODE temp;
	temp=getnode();
	temp->info=elem;
	temp->llink=temp->rlink=NULL;
	if(first==NULL)
	return temp;
	temp->rlink=first;
	first->llink=temp;
	return temp;
}
NODE insert_rear(NODE first,E elem)
{
	NODE temp,curr=first,pre=NULL;
	temp=getnode();
	temp->info=elem;
	temp->rlink=temp->llink=NULL;
	if(first==NULL)
	return temp;
	while(curr->rlink!=NULL)
	{
		curr=curr->rlink;
	}
	temp->llink=curr;
	curr->rlink=temp;
	return first;
}
NODE delete_front(NODE first)
{
	if(first==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	NODE next=first->rlink;
	E elem=first->info;
	printf("The deleted employee detail is %d\n",);
	printf("Name: %s\nID : %d\nSalary: %f\n",elem.name,elem.eid,elem.esal);
	free(first);
	if(next!=NULL)
	next->llink=NULL;
	return next;
}
NODE delete_rear(NODE first)
{
	if(first==NULL)
	{
		printf("Deletion is not possible\n");
		return NULL;
	}
	NODE pre=NULL,curr=first;
	while(curr->rlink!=NULL)
	{
		pre=curr;
		curr=curr->rlink;
	}
	E elem=curr->info;
	printf("The deleted employee detail is %d\n");
	printf("Name: %s\nID : %d\nSalary: %f\n",elem.name,elem.eid,elem.esal);
	if(pre==NULL)
	return NULL;
	pre->rlink=NULL;
	free(curr);
	return first;
}
void display(NODE first)
{
	if(first==NULL)
	{
		printf("No elements to display\n");
		return;
	}
	printf("Displaying elements of DLL:\n");
	while(first!=NULL)
	{
		E elem=first->info;
		printf("Name: %s\nID : %d\nSalary: %f\n",elem.name,elem.eid,elem.esal);
		first=first->rlink;
	}
	printf("\n");
}
int main()
{
	NODE first=NULL;
	E elem;
	int op;
	while(1)
	{
		printf("Enter an option\n");
		printf("1: insert at front\n2: insert at rear\n3: delete front\n4: delete rear\n5: display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter the employee detail to be inserted\n");
			printf("Enter  the employee name,employee id and employee salary\n");
			scanf("%s%d%f",elem.name,&elem.eid,&elem.esal);
			first=insert_front(first,elem);
			break;
			case 2:
			printf("Enter the employee detail to be inserted\n");
			printf("Enter  the employee name,employee id and employee salary\n");
			scanf("%s%d%f",elem.name,&elem.eid,&elem.esal);
			first=insert_rear(first,elem);
			break;
			case 3:
			first=delete_front(first);
			break;
			case 4:
			first=delete_rear(first);
			break;
			case 5:
			display(first);
			break;
			default:
			printf("Invalid option\n");
			exit(0);
		}
	}
	return 0;
}
