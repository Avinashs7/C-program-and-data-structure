#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *llink,*rlink;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Memory not allocated\n");
		exit(1);
	}
	return x;
}
NODE insert(NODE root,int elem)
{
	NODE temp,curr,pre;
	temp=getnode();
	temp->info=elem;
	temp->llink=temp->rlink=NULL;
	curr=root;
	pre=NULL;
	if(root==NULL)
	return temp;
	while(curr!=NULL)
	{
		pre=curr;
		if(curr->info<elem)
		curr=curr->rlink;
		else
		curr=curr->llink;
	}
	if(pre->info<elem)
	pre->rlink=temp;
	else
	pre->llink=temp;
	return root;
}
void preorder(NODE root)
{
	if(root==NULL)
	return;
	printf("%d\t",root->info);
	preorder(root->llink);
	preorder(root->rlink);
}
void inorder(NODE root)
{
	if(root==NULL)
	return;
	inorder(root->llink);
	printf("%d\t",root->info);
	inorder(root->rlink);
}
void postorder(NODE root)
{
	if(root==NULL)
	return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->info);
}
int main()
{
	NODE root;
	root=NULL;
	int op,elem;
	while(1)
	{
		printf("Enter an option\n");
		printf("1: Insert to bst\n2: preorder\n3: inorder\n4: postorder\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter an element\n");
			scanf("%d",&elem);
			root=insert(root,elem);
			break;
			case 2:
			printf("The BST in preorder traversal\n\n");
			preorder(root);
			break;
			case 3:
			printf("The BST in inorder traversal\n\n");
			inorder(root);
			break;
			case 4:
			printf("The BST in postorder traversal\n\n");
			postorder(root);
			break;
			default:
			printf("Invalid option\n");
			exit(0);
		}
	}
}
