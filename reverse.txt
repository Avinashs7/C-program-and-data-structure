#include<stdio.h>
void reverse(int *num, int *rev)
{
	int rem;
	while(*num != 0 )
	{
		rem = *num%10;
		*rev = (*rev)*10 +rem;
		*num = *num/10;
	}
}	
int main()
{
	int num,rev=0;
	printf("Enter a number \n");
	scanf("%d",&num);
	reverse(&num,&rev);
	printf("the reverse of number is %d\n",rev);
	return 0;
}

