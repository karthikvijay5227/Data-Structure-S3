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
 if(f==r+1 ||(f==0&&r==n-1))
   return 1;
 else
   return 0;
}

void InsertQ(int item)
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

int DeleteQ()
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

void Display()
{
 if(isempty())
   printf("Queue is empty");
 else 
 {
  printf("Queue contents are:");
  for(int i=f;i!=r;i=(i+1)%n)
  {
   printf("%d ",Q[i]);
  }
  printf("%d",Q[r]);
 }
}

void main()
{
 int ch,val;
 do{
 printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1:printf("Enter the item to be inserted:");
         scanf("%d",&item);
         InsertQ(item);
         break;
  
  case 2:val=DeleteQ();
         if(val!=-1)
           printf("%d deleted",Q[val]);
         break;
  
  case 3:Display();
         break;

  case 4:break;
  
  default:printf("Wrong Option");
          break;
 }}while(ch!=4);
}
