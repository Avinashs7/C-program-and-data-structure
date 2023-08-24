#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("MEMORY NOT AVAILABLE\n");
        exit(0);
    }
    return x;
}
NODE insert_front(NODE last,int elem)
{
    NODE temp;
    temp = getnode();
    temp->info=elem;
    if(last == NULL)
    last = temp;
    else
    temp->link=last->link;
    last->link=temp;
    return last;
}
NODE insert_rear(NODE last,int elem)
{
    NODE temp;
    temp = getnode();
    temp->info=elem;
    if(last==NULL)
        temp->link=temp;
    else
    {
        temp->link=last->link;
        last->link=temp;
    }
    return temp;
}
NODE delete_front(NODE last)
{
    NODE first;
    if(last==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("%d is the element deleted\n",last->info);
        free(last);
        return NULL;
    }
    first=last->link;
    last->link=first->link;
    printf("%d is the element deleted\n",first->info);
    free(first);
    return last;
}
NODE delete_rear(NODE last)
{
    NODE pre;
    if(last==NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(last->link==last)
    {
        printf("%d is the element deleted\n",last->info);
        free(last);
        return NULL;
    }
    pre=last->link;
    while(pre->link!=last)
    pre=pre->link;
    pre->link=last->link;
    printf("%d is the element deleted\n",last->info);
    free(last);
    return pre;
}
void display(NODE last)
{
    NODE curr;
    if(last==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        curr = last->link;
        printf("Displaying elements in CLL\n");
        do
        {
            printf("%d\t",curr->info);
            curr=curr->link;
        }while(curr!=last->link);
        printf("\n");
    }
}
int main()
{
    int op,elem;
    NODE last;
    last=NULL;
    while(1)
    {
        op=0;
        printf("1:Insert front\n2:Insert rear\n3:Delete_rear\n4:Delete front\n5:Display\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter an element to be inserted\n");
            scanf("%d",&elem);
            last=insert_front(last,elem);
            break;
            case 2:
            printf("Enter an element to be inserted\n");
            scanf("%d",&elem);
            last=insert_rear(last,elem);
            break;
            case 3:
            last=delete_rear(last);
            break;
            case 4:
            last=delete_front(last);
            break;
            case 5:
            display(last);
            break;
            default:
            printf("Invalid option\n");
            exit(0);
        }
    }
    return 0;
}
