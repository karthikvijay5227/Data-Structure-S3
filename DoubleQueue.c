#include<stdio.h>

#define n 50
int f=-1,r=-1,item;
int Q[n];

int isempty()
{
 if(f==-1)
   return 1;
 else
   return 0;
}

int isfull()
{
 if((f==r+1)||(f==0&&r==n-1))
   return 1;
 else
   return 0;
}

void InsertRear(int item)
{
 if(isfull())
   printf("Queue is full");
 else
 {
  if(f==-1)
    f=r=0;
  else
    r=(r+1)%n;
  Q[r]=item;
 }
}

int DeleteFront()
{
 int index = -1;
 if(isempty())
   printf("Queue is empty");
 else
 {
   index = f;
   if(f == r)
     f = r = -1;
   else
     f = (f+1)%n;
 }
 return index;
}

void InsertFront(int item)
{
 if(isfull())
		printf("Queue is full");
	else
		if(isempty())
			f=r=0;
		else
			f = (f+n-1)%n;
		Q[f]= item;
}

int DeleteRear()
{
 int index = -1;
	if(isempty())
		printf("Queue is empty");
	else
		index = r;
	if(f == r)
		f = r = -1;
	else
		r = (r + n-1)%n;
	return index;
}

void Display()
{
 if(isempty())
   printf("Queue is empty");
 else 
 {
  printf("Queue contents are:");
  for(int i=f;i!=r+1;i=(i+1)%n)
  {
   printf("%d ",Q[i]);
  }
 }
}

void main()
{
 int ch,val;
 do{
 printf("\nQueue Operations are:\n");
 printf("\n1.InsertRear\n2.DeleteFront\n3.InsertFront\n4.DeleteRear\n5.Display\n6.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:printf("Enter the item to be inserted from rear:");
         scanf("%d",&item);
         InsertRear(item);
         break;
  
  case 2:val=DeleteFront();
         if(val!=-1)
           printf("%d deleted from front",Q[val]);
         break;
  
  case 3:printf("Enter the item to be inserted from front:");
         scanf("%d",&item);
         InsertFront(item);
         break;

  case 4:val=DeleteRear();
         if(val!=-1)
           printf("%d deleted from rear",Q[val]);
         break;
  
  case 5:Display();
         break;

  case 6:break;

  default:printf("Wrong Option");
          break;
 }}while(ch!=6);
}

