#include<stdio.h>

void Read(int [],int);
int Binary(int [],int,int,int,int);
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
 int item,k,beg=0,end=n-1;
 printf("Enter the elements:");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 }
 printf("Enter the item to be searched:");
 scanf("%d",&item);
 k=Binary(A,n,beg,end,item);

 if(k!=0)
 {
  Print(item,k);
 }
 else
 {
  printf("Element is not in the list");
 }
}

int Binary(int A[],int n,int beg,int end,int item)
{
 int mid=(beg+end)/2;
 while(beg<=end)
 {
  if(A[mid]==item)
  {
   return (mid+1);
  }
  else if(item>A[mid])
  {
   return Binary(A,n,mid+1,end,item);
  }
  else
  {
   return Binary(A,n,beg,mid-1,item);
  }
 }
 return 0;
} 

void Print(int item,int loc)
{
 printf("%d is found at position %d",item,loc);
}
