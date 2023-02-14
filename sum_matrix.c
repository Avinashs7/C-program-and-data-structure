#include<stdio.h>
int main()
{
	int m,n,A[20][20],i,j,sum=0;
	printf("Enter the order of matrix\n");
	scanf("%d%d",&m,&n);
	printf("Enter the elements of matrix\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		scanf("%d",&A[i][j]);
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		sum= sum+A[i][j];
	}
	printf("The sum of all the elements of matrix is %d\n",sum);
	return 0;
}
	
