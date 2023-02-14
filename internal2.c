//Polynomial addition 
#include<stdio.h>
#define max 20
struct polynomial
{
	int cf,ex;
};
typedef struct polynomial P;
void accept(P p1[max],int terms)
{
	int i;
	for(i=0; i<terms; i++)
	{
		printf("Enter the co-efficient and exponent of a term\n");
		scanf("%d%d",&p1[i].cf,&p1[i].ex);
	}
}
void display(P p1[max], int terms)
{
	int i;
	for(i=0; i<terms; i++)
	{
		if(p1[i].cf>=0)
		printf("+%d x^%d ",p1[i].cf,p1[i].ex);
		else
		printf("%d x^%d ",p1[i].cf,p1[i].ex);
	}
}
int polynomial_add(P p1[max], P p2[max], P p3[2*max],int m,int n)
{
	int i,j,k=0;
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(p1[i].ex == p2[j].ex)
			{
				p3[k].cf=p1[i].cf+p2[j].cf;
				p3[k].ex=p1[i].ex;
				k++;
				p2[j].cf=-999;
				break;
			}
		}
		if(j==n)
		{
			p3[k]=p1[i];
			k++;
		}
	}
	for(j=0; j<n; j++)
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
	P p1[max],p2[max],p3[2*max];
	int m,n,k;
	printf("Enter number of terms in 1st polynomial\n");
	scanf("%d",&m);
	accept(p1,m);
	printf("Enter number of terms in 2nd polynomial\n");
	scanf("%d",&n);
	accept(p2,n);
	printf("The addition of two polynomial \n the resultant is :\n");
	k=polynomial_add(p1,p2,p3,m,n);
	display(p3,k);
	return 0;
}
