#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	int cf,px,py,pz;
	struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
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
void display(NODE head)
{
	NODE curr=head->link;
	if(curr==head)
	{
		printf("Empty polynomial\n");
		return;
	}
	printf("The polynomial is :\n");
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
void accept(NODE head)
{
	int cf,px,py,pz;
	printf("Enter co-efficient of the term\n");
	scanf("%d",&cf);
	printf("Enter the exponent of x,y,z respectively\n");
	scanf("%d%d%d",&px,&py,&pz);
	insert_front(head,cf,px,py,pz);
}
int evaluate(NODE head)
{
	int result=0,x,y,z;
	NODE curr=head->link;
	printf("Enter the values of x,y,z respectively\n");
	scanf("%d%d%d",&x,&y,&z);
	while(curr!=head)
	{
		result+=(curr->cf)*pow(x,curr->px)*pow(y,curr->py)*pow(z,curr->pz);
		curr=curr->link;
	}
	return result;
}
int main()
{
	int terms;
	NODE head=getnode();
	head->link=head;
	printf("Enter number of terms in polynomial\n");
	scanf("%d",&terms);
	printf("Enter each term:\n");
	for(int i=0; i<terms; i++)
	accept(head);
	printf("Displaying the polynomial\n");
	display(head); 
	int res=evaluate(head);
	printf("The resultant after evaluation is %d\n",res);
	return 0;
}
