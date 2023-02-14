#include<stdio.h>
#include<string.h>
int pattern_match(char ms[20],char ps[10],int pos)
{
	for(int j=0; j<strlen(ps); j++)
	{
		if(ms[pos]!=ps[j])
		return 0;
		pos++;
	}
	return 1;
}
int copy_str(char os[100],char rs[20],int olen)
{
	for(int i=0; i<strlen(rs); i++)
	{
		os[olen]=rs[i];
		olen++;
	}
	return olen;
}
int main()
{
	int olen=0,i;
	char ms[20],ps[10],rs[20],os[100];
	printf("enter main string\n");
	scanf(" %[^\n]",ms);
	printf("enter pattern string\n");
	scanf(" %[^\n]",ps);
	printf("enter replace string\n");
	scanf(" %[^\n]",rs);
	for(i=0; ms[i]!='\0'; i++)
	{
		if(pattern_match(ms,ps,i))
		{
			olen=copy_str(os,rs,olen);
			i=i+strlen(ps)-1;
		}
		else
		{
			os[olen]=ms[i];
			olen++;
		}
	}
	os[olen]='\0';
	printf("the output string is :\n");
	printf("%s\n",os);
	return 0;
}

