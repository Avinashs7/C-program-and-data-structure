//Transpose of matrix
#include<stdio.h>
struct sparse
{
	int row,col,value;
};
typedef struct sparse S;
void accept (S a[20],int m,int n)
{
	int i,j,elem,k=1;
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("Enter an element\n");
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
void transpose (S a[20],S aT[20])
{
	int i,j,k=1;
	for(i=0; i<a[0].col ; i++)
	{
		for(j=1; j<=a[0].value ; j++)
		{
			if(i==a[j].col)
			{
				aT[k].row=a[j].col;
				aT[k].col=a[j].row;
				aT[k].value=a[j].value;
				k++;
			}
		}
	}
	aT[0].row=a[0].col;
	aT[0].col=a[0].row;
	aT[0].value=a[0].value;
}
void display(S a[20])
{
	int k=1,i,j;
	for(i=0; i<a[0].row; i++)
	{
		for(j=0; j<a[0].col; j++)
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
	S a[20],aT[20];
	printf("Enter the order of sparse matrix\n");
	scanf("%d%d",&m,&n);
	accept(a,m,n);
	printf("The given sparse matrix is :\n");
	display(a);
	printf("The transpose of given matrix\n");
	transpose(a,aT);
	display(aT);
	return 0;
}
	
