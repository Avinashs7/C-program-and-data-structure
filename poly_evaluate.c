#include<stdio.h>
#include<math.h>
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
float evaluate(p p1[20],int terms)
{
	float sum=0;
	int x;
	printf("enter the value of x\n");
	scanf("%d",&x);
	for(int i=0; i<terms; i++)
		sum= sum+p1[i].cf*pow(x,p1[i].ex);
	return sum;
}
int main()
{
	p p1[20];
	int m;
	printf("enter number of terms in 1st polynomial\n");
	scanf("%d",&m);
	accept(p1,m);
	printf("the polynomial which you have entered is \n");
	display(p1,m);
	float sum;
	sum = evaluate(p1,m);
	printf("The evaluation of polynomial is %f\n",sum);
	return 0;
}
