#include<stdio.h>
#include<stdlib.h>
void accept(int a[20][20],int *row,int *col)
{
	int i,j;
	printf("enter the order of matrix\n");
	scanf("%d%d",row,col);
	printf("enter the matrix elements\n");
	for(i=0; i<*row; i++)
	{
		for(j=0; j<*col; j++)
		scanf("%d",&a[i][j]);
	}
}
void transpose(int a[20][20],int t[20][20],int m,int n)
{
	int i,j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		t[j][i] = a[i][j];
	}
}
void display(int a[20][20],int m, int n)
{
	int i,j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		printf("%d\t",a[i][j]);
		printf("\n");
	}
}
void add(int a[20][20],int b[20][20],int c[20][20],int m,int n)
{
	int i,j;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		c[i][j]=a[i][j]+b[i][j];
	}
}
void multiply(int a[20][20], int b[20][20],int c[20][20],int m,int q, int n)
{
	int i,j,k;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			c[i][j]=0;
			for(k=0; k<q; k++)
			c[i][j]=c[i][j]+a[i][k]*b[k][j];
		}
	}
}
int main()
{
	int a[20][20], b[20][20], c[20][20],t[20][20],res[20][20],m,n,p,q,r,s;
	accept(a,&m,&n);
	printf("displaying matrix A\n");
	display(a,m,n);
	printf("displaying transpose of matrix A\n");
	transpose(a,t,m,n);
	display(t,n,m);
	accept(b,&p,&q);
	if(m==p && n==q)
	add(a,b,c,m,n);
	else
	{
		printf("addition not possible\n");
		exit(0);
	}
	printf("the addition of matrix A and B is :\n");
	display(c,m,n);
	accept(c,&r,&s);
	if(n==r)
	multiply(a,c,b,m,s,n);
	else
	{
		printf("multiplication is not possible\n");
		exit(0);
	}
	printf("the product of matrix a and c is:\n");
	display(b,m,s);
	return 0;
}
	
	
		
	
