#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int cf,px,py,pz;
	struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x= (NODE)malloc(sizeof(struct node));
	if(x== NULL)
	{
		printf("Memory not available\n");
		exit(0);
	}
	return x;
}
void insert_front(NODE head,int cf,int px,int py,int pz)
{
	NODE temp;
	temp=getnode();
	temp->cf=cf;
	temp->px=px;
	temp->py=py;
	temp->pz=pz;
	temp->link=head->link;
	head->link=temp;
}
void accept(NODE head)
{
	int cf,px,py,pz;
	printf("Enter the term to be inserted in polynomial\n");
	printf("It's co-efficient\n");
	scanf("%d",&cf);
	printf("It's power to x,y,z\n");
	scanf("%d%d%d",&px,&py,&pz);
	insert_front(head,cf,px,py,pz);
}
void display(NODE head)
{
	NODE curr=head->link;
	if(curr==head)
	{
		printf("empty polynomial \n");
		return;
	}
	printf("The polynomial is:\n");
	while(curr!=head)
	{
		if(curr->cf>=0)
		printf("+%d x^%dy^%dz^%d\t",curr->cf,curr->px,curr->py,curr->pz);
		else
		printf("%d x^%dy^%dz^%d\t",curr->cf,curr->px,curr->py,curr->pz);
		curr=curr->link;
	}
	printf("\n");
}
int evaluate(NODE p)
{
	int x,y,z,sum=0;
	NODE curr=p->link;
	printf("Enter the values of x,y,z respectively\n");
	scanf("%d%d%d",&x,&y,&z);
	while(curr!=p)
	{
		sum+=(curr->cf)*pow(x,curr->px)*pow(y,curr->py)*pow(z,curr->pz);
		curr=curr->link;
	}
	return sum;
}
int main()
{
	NODE p1;
	p1=getnode();
	p1->link=p1;
	int terms;
	printf("Enter the number of terms in polynomial\n");
	scanf("%d",&terms);
	for(int i=0; i<terms; i++)
	accept(p1);
	display(p1);
	int result = evaluate(p1);
	printf("The evaluation of polynomial results to %d\n",result);
	return 0;
}
