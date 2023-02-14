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
void sort(E e[10],int n)
{
	int i,j;
	E temp;
	for(i=0 ;i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		if(e[j].eid>e[j+1].eid)
		{
			temp = e[j];
			e[j] = e[j+1];
			e[j+1] = temp;
		}
	}
}
void search(E e[10],int n)
{
	int key;
	printf("Enter the id to be searched\n");
	scanf("%d",&key);
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(e[mid].eid == key)
		{
			printf("the element is found in %d position\n",mid);
			printf("Employee id: %d\n",e[mid].eid);
			printf("Employee name: %s\n",e[mid].name);
			return;
		}
		else if(e[mid].eid>key)
		r=mid-1;
		else
		l=mid+1;
	}
	printf("The id is not found in the employee details\n");
}

int main()
{
	int n;
	E e[10];
	accept(e,&n);
	sort(e,n);
	search(e,n);
}
