#include<stdio.h>
void add(int arr[20],int n,int *sum)
{
	for(int i=0; i<n; i++)
		*sum = *sum + arr[i];
}

int main()
{
	int array[20],n,sum=0;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter elements of array\n");
	for(int i=0; i<n; i++)
		scanf("%d",&array[i]);
	add(array,n,&sum);
	printf("The sum of elements of the array is %d",sum);
	return 0;
}
