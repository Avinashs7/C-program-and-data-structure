#include<stdio.h>
void swap(int *num1,int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main()
{
	int num1,num2;
	printf("Enter two numbers \n");
	scanf("%d%d",&num1,&num2);
	swap(&num1,&num2);
	printf("After swapping \nnum1 = %d \nnum2 = %d",num1,num2);
	return 0;
}
