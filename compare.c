#include<stdio.h>
#include<string.h>

void accept(char s[20])
{
	printf("Enter the string\n");
	scanf("%s",s);
}

int compare(char s1[20], char s2[20])
{
	int count=0;
	while(s1[count] != '\0' && s2[count] != '\0')
	{
		if(s1[count] == s2[count])
		count++;
		else
		break;
	}
	if(count == strlen(s1) && count == strlen(s2))
	return 0;
	else
	return 1;
}	
int main()
{
	char s1[20],s2[20];
	int check;
	accept(s1);
	accept(s2);
	check = compare(s1,s2);
	if(check==0)
	printf("The strings are equal\n");
	else
	printf("The strings are not equal\n");
	return 0;
}
