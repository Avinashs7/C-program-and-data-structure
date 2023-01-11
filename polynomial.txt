#include<stdio.h>
typedef struct polynomial
{
	int cf,ex;
}p;
void accept(p p1[20],int terms)
{
	for(int i=0; i<terms; i++)
	{
		printf("enter the co efficient and exponent of a term\n");
		scanf("%d%d",&p1[i].cf,&p1[i].ex);
	}
}
void display(p p1[40],int terms)
{
	for(int i=0; i<terms; i++)
	{
		if(p1[i].cf>0)
		printf("+%d x^%d ",p1[i].cf,p1[i].ex);
		else
		printf("%d x^%d ",p1[i].cf,p1[i].ex);
	}
}
int poly_add(p p1[20], p p2[20], int m, int n, p p3[40])
{
	int i,j,k=0;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(p1[i].ex == p2[j].ex)
			{
				p3[k].cf=p1[i].cf+p2[j].cf;
				p3[k].ex = p1[k].ex;
				p2[j].cf = -999;
				k++;
				break;
			}
		}
		if(j==n)
		{
			p3[k]=p1[i];
			k++;
		}
	}
	for(int j=0; j<n; j++)
	{
		if(p2[j].cf!=-999)
		{
			p3[k]=p2[j];
			k++;
		}
	}
	return k;
}
int main()
{
	p p1[20],p2[20],p3[40];
	int m,n,k;
	printf("enter number of terms in 1st polynomial\n");
	scanf("%d",&m);
	accept(p1,m);
	printf("enter number of terms in 2nd polynomial\n");
	scanf("%d",&n);
	accept(p2,n);
	k =poly_add(p1,p2,m,n,p3);
	printf("the sum of 1st and 2nd polynomial is :\n");
	display(p3,k);
	return 0;
}

