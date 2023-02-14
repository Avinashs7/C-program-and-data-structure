#include<stdio.h>
#include<string.h>
typedef
struct Employee
{
	int eid;
	char name[10];
}E;
void accept(E e[10],int *n)
{
	printf("Enter the number of employee details to be stored\n");
	scanf("%d",n);
	for(int i=0; i<*n; i++)
	{
		printf("Enter employee id:\n");
		scanf("%d",&e[i].eid);
		printf("Enter employee name:\n");
		scanf("%s",e[i].name); 	
	}
}
void search_id(E e[10],int n)
{
	int key;
	printf("Enter the id to be searched\n");
	scanf("%d",&key);
	for(int i=0; i<n; i++)
	{
		if(e[i].eid == key)
		{
			printf("the element is found in %d position\n",i);
			printf("Employee id: %d\n",e[i].eid);
			printf("Employee name: %s\n",e[i].name);
			return;
		}
	}
	printf("The id is not found in the employee details\n");
}
void search_name(E e[10],int n)
{
	char key[10];
	printf("Enter the name to be searched\n");
	scanf("%s",key);
	for(int i=0; i<n; i++)
	{
		if(strcmp(e[i].name,key)== 0)
		{
			printf("the element is found in %d position\n",i);
			printf("Employee id: %d\n",e[i].eid);
			printf("Employee name: %s\n",e[i].name);
			return;
		}
	}
	printf("The name is not found in the employee details\n");
}
int main()
{
	int n,op;
	E e[10];
	accept(e,&n);
	printf("Enter an option to search based on :\n");
	printf("1: id\n 2: name\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
		search_id(e,n);
		break;
		case 2:
		search_name(e,n);
		break;
		default:
		printf("invalid option\n");
		break;
	}
}
	
