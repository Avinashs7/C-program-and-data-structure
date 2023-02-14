#include<stdio.h>
void accept(int arr[20],int *n)
{
	printf("Enter the size of array\n");
	scanf("%d",n);
	printf("Enter the elements of array\n");
	for(int i=0; i<*n; i++)
		scanf("%d",&arr[i]);
}

void search(int arr1[20],int n)
{
	int i,key,flag =-1;
	printf("Enter the key element to be searched \n");
	scanf("%d",&key);
	//for(i=0; i<n; i++)
		//printf("%d\t",arr1[i]);
	
	for(i=0; i<n; i++)
	{
		if(arr1[i] == key)
		{
			flag=1;
			break;
		}
	}
	if(flag == 1)
		printf("The element is found in %d position",i);
	else
		printf("The element is not found\n");
}

int main()
{
	int array[20],n;
	accept(array,&n);
	search(array,n);
	return 0;
}
