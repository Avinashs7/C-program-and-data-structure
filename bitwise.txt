#include<stdio.h>
void addition(int *num1, int *num2, int *sum)
{
	printf("Enter two numbers\n");
	scanf("%d%d",num1,num2);
	*sum = ((*num1)^(*num2))|(((*num1)&(*num2))<<1);
}

int main()
{
	int num1,num2,sum=0;
	addition(&num1,&num2,&sum);
	printf("The sum is %d\n",sum);
	return 0;
}
