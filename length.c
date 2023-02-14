#include<stdio.h>
int length(char s[100])
{
	int i,count=0;
	for(i=0; s[i]!='\0'; i++)
		count++;
	return count;
}
int main()
{
	char str[100];
	printf("enter a string\n");
	scanf("%s",str);
	printf("The length of string is %d\n",length(str));
	return 0;
}
