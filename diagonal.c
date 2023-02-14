#include<stdio.h>
int main()
{
	int m,n,A[20][20],i,j,diagonal_sum=0,non_diagonal_sum=0;
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
		if(i==j)
		diagonal_sum = diagonal_sum + A[i][j];
		else
		non_diagonal_sum = non_diagonal_sum + A[i][j];
	}
	printf("The sum of diagonal elements is %d\n",diagonal_sum);
	printf("The sum of non diagonal elements is %d\n",non_diagonal_sum);
}

