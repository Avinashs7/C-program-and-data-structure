#include<stdio.h>
void row_m(int a[20][20],int m,int n)
{
	printf("the matrix in row major\n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			printf("%d\t",a[i][j]);
	}
}
void column_m(int a[20][20],int m,int n)
{
	printf("the matrix in column major\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%d\t",a[j][i]);
	}
}
void accept(int a[20][20],int *m,int *n)
{
	printf("Enter the number of rows and column of matrix\n");
	scanf("%d%d",m,n);
	printf("enter the elements of matrix\n");
	for(int i=0; i<*m; i++)
	{
		for(int j=0; j<*n; j++)
			scanf("%d",&a[i][j]);
	}
}
int main()
{
	int a[20][20],m,n;
	accept(a,&m,&n);
	row_m(a,m,n);
	printf("\n");
	column_m(a,m,n);
	return 0;
}
