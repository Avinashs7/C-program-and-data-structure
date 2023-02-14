#include<stdio.h>
typedef
struct student
{
	int id;
	char name[20];
}S;
void accept(S *s)
{
	printf("Enter id of student\n");
	scanf("%d",&(*s).id);
	printf("Enter name of student\n");
	scanf("%s",(*s).name);
}
void swap(S *p,S *q)
{
	S temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void display(S s1, S s2)
{
	printf("Displaying student info\n");
	printf("ID: %d\nName: %s\n",s1.id,s1.name);
	printf("2nd student\n");
	printf("ID: %d\nName: %s\n",s2.id,s2.name);
}
int main()
{
	S s1,s2;
	accept(&s1);
	accept(&s2);
	swap(&s1,&s2);
	display(s1,s2);
	return 0;
}
