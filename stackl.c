#include<stdio.h>
#include<malloc.h>

struct NODE
{
 int info;
 struct NODE *link;
};
typedef struct NODE node;
node *top=NULL,*p;
node *NewNode(int val)
{
 p=(node *)malloc(sizeof(node));
 p->info=val;
 p->link=NULL;
 return p;
}

void Push(int item)
{
 p=NewNode(item);
 if(p==NULL)
    printf("overflow");
 else
 {
	p->info = item;
	p->link = top;
	top = p;
 }
}

void Pop()
{
 node *ptr;
 ptr=top;
 if(ptr==NULL)
   printf("Stack Underflow");
 else
 {
  int item=top->info;
  printf("%d deleted\n",item);
  top=top->link;
  free(ptr);
 }
}
 
void Display()
{
 node *curr;
 curr=top;
 while(curr!=NULL)
 {
    printf("%d",curr->info);
    curr=curr->link;
    if(curr !=NULL)
	  printf(" --> ");
 }
}
 
void main()
{
 int ch,item,val;
 do
 {
  printf("\nStack Operations are:\n");
  printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:printf("Enter the item to be pushed:");
           scanf("%d",&item);
           Push(item);
           break;
   
    case 2:Pop();
           break;
           
    case 3:Display();
           break;
             
    case 4:break;
     
    default:printf("Wrong Choice");
            break;
  }
 }while(ch!=4);
}
