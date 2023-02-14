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
void transpose(s a[20],s aT[20])
{
	int i,j,k=1;
	for(i=0; i<a[0].col; i++)
	{
		for(j=1;j<=a[0].value;j++)
		{
			if(i==a[j].col)
			{
				aT[k].col=a[j].row;
				aT[k].row=a[j].col;
				aT[k].value=a[j].value;
				k++;
			}
		}
	}
	aT[0].col=a[0].row;
	aT[0].row=a[0].col;
	aT[0].value=a[0].value;
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
	s a[20],aT[20];
	printf("enter the order of sparse matrix\n");
	scanf("%d%d",&m,&n);
	accept(a,m,n);
	printf("the sparse matrix\n");
	display(a);
	transpose(a,aT);
	printf("The transpose of sparse matrix :\n");
	display(aT);
	return 0;
}
