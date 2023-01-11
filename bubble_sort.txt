#include<stdio.h>
void sort(int arr[20], int n)
{
	int i,j,temp;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		if(arr[j]>arr[j+1])
		{
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
}	
void accept(int arr[20],int *n)
{
	printf("Enter the size of array\n");
	scanf("%d",n);
	printf("Enter the elements of array\n");
	for(int i=0; i<*n; i++)
		scanf("%d",&arr[i]);
}
int main()
{
	void display(int arr[20],int n);
	int array[20],n;
	accept(array,&n);
	sort(array,n);
	display(array,n);
	return 0;
}	
void display(int arr[20],int n)
{
	printf("The elements of array after sorting\n");
	for(int i=0; i<n; i++)
	printf("%d\t",arr[i]);
}

