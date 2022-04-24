#include<stdio.h>
void Delete();
void Insert(int);
void Swap(int *,int *);
void Heapify(int A[],int i,int n);
void Display(int[],int);

#define max 50
int PQ[max];
int Qsize=0,curr,par;

void main()
{
 int ch,item;
 do
 {
  printf("\nPriority Queue Operations!\n");
  printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("Enter the item to be inserted:");
          scanf("%d",&item);
          Insert(item);
          break;
          
   case 2:Delete();
          break;
          
   case 3:Display(PQ,Qsize);
          break;
          
   case 4:break;
   
   default:printf("Wrong Option");
  }
 }while(ch!=4);
}


void Insert(int item)
{
 if(Qsize == max)
    printf("Full");
 else
 {
   Qsize+=1;
   PQ[Qsize]=item;
   curr=Qsize;
   par=Qsize/2;
   while(par>=1 && PQ[par]>PQ[curr])
   {
    Swap(&PQ[par],&PQ[curr]);
    curr=par;
    par=curr/2;
   }
 }
}

void Delete()
{
 if(Qsize<1)
    printf("Empty");
 else
 {
   printf("%d deleted",PQ[1]);
   Swap(&PQ[1],&PQ[Qsize]);
   Qsize--;
   Heapify(PQ,1,Qsize);
 }
}

void Display(int PQ[],int n)
{
 int i;
 printf("Priority Queue Contents are:");
 for(i=1;i<=n;i++)
 {
  printf("%d ",PQ[i]);
 }
 printf("\n");
}
   
void Swap(int *a,int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}

void Heapify(int A[],int i,int n)
{
 int small=i;
 int lc=2*i;
 int rc=2*i+1;
 
 if(lc<=n && A[lc]<A[small])
    small=lc;
 if(rc<=n && A[rc]<A[small])
    small=rc;
    
 if(small!=i)
 {
   Swap(&A[small],&A[i]);
   Heapify(A,small,n);
 }
}
