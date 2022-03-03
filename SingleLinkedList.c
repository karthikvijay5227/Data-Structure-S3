#include<stdio.h>
#include<malloc.h>
struct NODE
{
 int info;
 struct NODE *link;
};
typedef struct NODE node;
node *head=NULL,*p;

node *NewNode(int val)
{
 p=(node *)malloc(sizeof(node));
 p->info=val;
 p->link=NULL;
 return p;
}

void InsertFirst(int item)
{
 p=NewNode(item);
 p->link=head;
 head=p;
}

void Display(node *h)
{ 
  node *curr;
  curr=h;
  while(curr!=NULL)
  {
   printf("%d", curr->info);
   curr=curr->link;
   if(curr !=NULL)
       printf(" --> ");
  }
}

void InsertBefore(int item,int item1)
{
 node *curr=head;
 node *prev=NULL;
 while(curr!=NULL && curr->info!=item1)
 {
  prev=curr;
  curr=curr->link;
 }
 if(curr==NULL)
   printf("No such node");
 else
 {
  p=NewNode(item);
  p->link=curr;
 }
 if(curr!=head)
   prev->link=p;
 else
   head=p;
}

void InsertAfter(int item,int item1)
{
 node *curr=head;
 while(curr!=NULL && curr->info!=item1)
 {
  curr=curr->link;
 }
 if(curr==NULL)
    printf("No such node");
 else
 {
  p=NewNode(item);
  p->link=curr->link;
  curr->link=p;
 }
}
  
void Delete(int val)
{
 node *prev=NULL,*curr=head;
 while(curr!=NULL && curr->info!=val)
 {
  prev=curr;
  curr=curr->link;
 }
 if(curr==NULL)
   printf("No such node");
 else
 {
   if(curr!=head)
     prev->link=curr->link;
   else
     head=curr->link;
   free(curr);
 }
}
void main()
{
 int ch,item,item1,val;
 do
 {
  printf("\nLinkedList Operations are:\n");
  printf("1.InsertFirst\n2.InsertBefore\n3.InsertAfter\n4.Delete\n5.Display\n6.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:printf("Enter the item to be  inserted at first:");
           scanf("%d",&item);
           InsertFirst(item);
           break;
   
    case 2:printf("Enter the item to be inserted before:");
           scanf("%d",&item);
           printf("Enter the item before which to enter:");
           scanf("%d",&item1);
           InsertBefore(item,item1);
           break;
           
    case 3:printf("Enter the item to be inserted after:");
           scanf("%d",&item);
           printf("Enter the item after which to enter:");
           scanf("%d",&item1);
           InsertAfter(item,item1);
           break;
           
    case 4:printf("Enter the element to be deleted:");
           scanf("%d",&val);
           Delete(val);
           break;
           
    case 5:printf("Contents are:");
           Display(head);
           break;
         
    case 6:break;
     
    default:printf("Wrong Choice");
            break;
  }
 }while(ch!=6);
}
           
           
 

