#include<stdio.h>
typedef
struct Employee
{
	int eid;
	char ename[20];
	float esal;
}E;
void accept(E *e)
{
	printf("Enter id of employee\n");
	scanf("%d",&(*e).eid);
	printf("Enter name of employee\n");
	scanf("%s",(*e).ename);
	printf("Enter salary of employee\n");
	scanf("%f",&(*e).esal);
}
void display(E e)
{
	printf("Details of employee\n");
	printf("Name: %s\nID: %d\nsalary: %f",e.ename,e.eid,e.esal);
}
int main()
{
	E e1;
	accept(&e1);
	display(e1);
	return 0;
}	
