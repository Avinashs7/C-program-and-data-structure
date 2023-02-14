#include<stdio.h>
#include<string.h>
#define SIZE 10
void read(int *,int);
void print(int [], int);
struct polynomial
{
	float coef;
	int exp;
};
int main()
{
  struct polynomial term[SIZE];
  int i,n
  printf("enetr the number of terms\n");
  read(&term,n);
  scanf("%d",&n);
  printf("enter the coef and exp\n");
  print(term,n);
  for(i=0;i<n;i++)
    scanf("%f%d",&term.coef,&term.exp);
  for(i=0;i<n;i++)
    printf("%f%d",term.coef,term.exp);
}
void read(int *term,int n)
{
 
}
void print(int term[], int n)
{
 
}
