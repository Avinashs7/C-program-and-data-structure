#include<stdio.h>
void accept(int arr[20],int *n)
{
	printf("Enter the size of array\n");
	scanf("%d",n);
	printf("Enter the elements of array\n");
	for(int i=0; i<*n; i++)
		scanf("%d",&arr[i]);
}

void display(int arr1[20], int n)
{
	printf("The elements of array are displayed below:\n");
	for(int i=0; i<n; i++)
		printf("%d\t",arr1[i]);
}

int main()
{
	int array[20],n;
	accept(array,&n);
	display(array,n);
	return 0;
}
