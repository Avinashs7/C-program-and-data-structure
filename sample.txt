#include<stdio.h>
void getdata(char s[10])
{
	printf("enter name\n");
	scanf("%[^\n]",s);
	
}
int main()
{
	char name[10];
	getdata(name);
	printf("%s",name);
	return 0;
}
