#include<stdio.h>
#include<malloc.h>

struct NODE
{
 int info;
 struct NODE *front,*rear,*link;
};
typedef struct NODE node;
node *front=NULL,*rear=NULL,*p;
node *NewNode(int val)
{
 p=(node *)malloc(sizeof(node));
 p->info=val;
 p->link=NULL;
 return p;
}

void InsertQ(int item)
{
 p=NewNode(item);
 if(p==NULL)
    printf("Overflow");
 else
 {
  if(front==NULL)
    front=rear=p;
  else
  {
   rear->link=p; 
   rear=p;
  }
 }
}

void DeleteQ()
{
 if(front == NULL)
   printf("Underflow");
 else
 {
  p=front;
  front=front->link;
  free(p);
 }
}

void Display()
{
 node *curr;
 curr=front;
 while(curr!=NULL)
 { 
	printf("%d", curr->info);
	curr=curr->link;
	if(curr !=NULL)
	   printf(" --> ");
 }
}

void main()
{
  int ch,item;
  do
  { 
      printf("\nQueue Operations are:\n");
	  printf("\n1.Insert \n2.Delete\n3.Display\n4.Quit\nEnter your Choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  { 
			
		case 1:printf("\nvalue to be inserted:");
			   scanf("%d",&item); 
			   InsertQ(item);
			   break;
		case 2:DeleteQ();	
			   break;
				
		case 3:Display();	
			   break;
			   
		case 4: break;
			
		default:printf("Invalid choice");
	 }
 }while(ch!=4);
}


