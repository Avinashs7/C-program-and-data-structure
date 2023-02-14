#include<stdio.h>
typedef struct Sparse
{
	int row,col,value;
}s;
void accept(s a[20],int m,int n)
{
	int i,j,k=1,elem;
	for(i=0; i<m; i++)
	{
		for(j=0;j<n;j++)
		{
			printf("enter an element \n");
			scanf("%d",&elem);
			if(elem!=0)
			{
				a[k].row=i;
				a[k].col=j;
				a[k].value=elem;
				k++;
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].value=k-1;
}
void display(s a[20])
{
	int i,j,k=1;
	for(i=0; i<a[0].row; i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			if(a[k].row==i && a[k].col==j)
			{
				printf("%d\t",a[k].value);
				k++;
			}
			else
				printf("0\t");
		}
		printf("\n");
	}
}
int main()
{
	int m,n;
	s a[20];
	printf("enter the order of sparse matrix\n");
	scanf("%d%d",&m,&n);
	accept(a,m,n);
	display(a);
	return 0;
}
