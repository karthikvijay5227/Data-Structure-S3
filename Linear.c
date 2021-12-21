#include<stdio.h>

void Read(int[],int);
int Lsearch(int[],int,int);
void Print(int,int);

void main()
{
 int A[100],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
}

void Read(int A[],int n)
{
 int item,k;
 printf("Enter the elements:");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }
 printf("Enter the item to be searched:");
 scanf("%d",&item);
 k=Lsearch(A,n,item);
 
 if(k!=0)
 {
  Print(item,k);
 }
 else
 {
  printf("Element not in the list");
 }
}

int Lsearch(int A[],int n,int item)
{
 for(int i=0;i<n;i++)
 {
  if(A[i]==item)
  {
   return (i+1);
  }
 }
 return 0;
}

void Print(int item,int i)
{
 printf("%d is found at position %d",item,i);
}
