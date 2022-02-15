//Not complete more work there.
#include<stdio.h>
#include<malloc.h>
struct NODE
{
	int info;
	struct NODE *prev,*next;
};
typedef struct NODE node;
node *head=NULL;
node *tail=NULL,*p;
node *newnode(int val)
{
	node *p;
	p=(node *)malloc(sizeof(node));
    p->info=val;
    p->prev=NULL;
    p->next=NULL;
}

void InsertFirst(int val)
{
	p=newnode(val);
	p->next=head;
	if(head==NULL)
	   head=tail=p;
	else
    {
    	head->prev=p;
    	head=p;
    }
}

void InsertAfter(int item,int item1)
{
	node *curr=head;
	while(curr!=NULL && curr->info!=item1)
	{
		curr=curr->next;
	}
	if(curr==NULL)
	   printf("No such element or node");
	else
       {
    	p=newnode(item);
    	p->prev=curr;
    	p->next=curr->next;
    	if(curr==tail)
    	   tail=p;
    	else
           curr->next->prev=p;
        curr->next=p;
       }
}

void TraverseRight(node *head)
{
	node *curr;
	curr=head;
	while(curr!=NULL)
	{
		printf("%d",curr->info);
		curr=curr->next;
		if(curr!=NULL)
		    printf("-->");
    }
} 
void TraverseLeft(node *tail)
{
	node *ptr;
	ptr=tail;
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->prev;
		if(ptr!=NULL)
		   printf("<--");
	}
}	

void Delete(int item)
{
  node *curr;
  curr=head;
  while(curr!=NULL && curr->info != item)
		curr = curr->next;
  if(curr->next == NULL)
		printf("No such element or node");
	else 
	{
		if(curr == head)
		   head = curr->next;
		else
		   curr->prev->next=curr->next;
		if(curr == tail)
		   tail = curr->prev;
		else
		   curr->next->prev=curr->prev;
	    free(curr);
    }
}	
int main()
 {
  int ch,po,it;
   do
     {
       printf("\nDoubly LinkedList Operations are:\n");
       printf("\n1.Insfirst\n2.InsAfter\n3.TraverseRight\n4.TraverseLeft\n5.Delete\n6.Exit\n");
       printf("\nEnter your choice:\n");
       scanf("%d",&ch);
       switch(ch)
       { 
         case 1:printf("Enter the value to be inserted first:");
                scanf("%d",&po); 
                InsertFirst(po);                        
                break;
         case 2:printf("Enter item after which an element is to be inserted:");
                scanf("%d",&it);
                printf("value to be inserted:");
                scanf("%d",&po);
                InsertAfter(po,it);                   
                break;
         case 3:TraverseRight(head);
                break;
         case 4:TraverseLeft(tail);
                break;
         case 5:printf("Enter the value to be deleted:");
                scanf("%d",&po);
                Delete(po);
                break;
         case 6:break;
         default:printf("Invalid choice");
        }
    }while(ch!=6);

}
