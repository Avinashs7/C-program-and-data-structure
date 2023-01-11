#include<stdio.h>
typedef
struct Employee
{
	int eid;
	char ename[20];
	float esal;
}E;
int main()
{
	E e1;
	printf("Enter id of employee\n");
	scanf("%d",&e1.eid);
	printf("Enter name of employee\n");
	scanf("%s",e1.ename);
	printf("Enter salary of employee\n");
	scanf("%f",&e1.esal);
	printf("Displaying employee info\n");
	printf("Name: %s\n ID: %d\n salary: %f\n",e1.ename,e1.eid,e1.esal);
	return 0;
}
