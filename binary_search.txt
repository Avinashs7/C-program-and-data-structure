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
void search(int arr[20], int n)
{
	int l=0,r=n-1,mid,elem,flag=0;
	printf("Enter the element to be searched\n");
	scanf("%d",&elem);
	while(l<=r)
	{
		mid =(l+r)/2;
		if(arr[mid] == elem)
		{
			flag=1;
			break;
		}
		else if(arr[mid]>elem)
		r=mid-1;
		else
		l=mid+1;
	}
	if(flag==1)
	printf("The element is found in %d position\n",mid);
	else
	printf("The element is not found\n");
}
int main()
{
	int array[20],n;
	accept(array,&n);
	sort(array,n);
	search(array,n);
	return 0;
} 
