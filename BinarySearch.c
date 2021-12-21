#include<stdio.h>

void Read(int [],int);
int Binary(int [],int,int);
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
 k=Binary(A,n,item);
 
 if(k!=0)
 {
  Print(item,k);
 }

 else
 {
  printf("Element not in the list");
 }
}

int Binary(int A[],int n,int item)
{
 int beg=0,end=n-1,mid,loc;
 while(beg<=end)
 {
  mid=(beg+end)/2;
  if(A[mid]==item)
  {
   return(mid+1);
  }
  else if(item>A[mid])
  {
   beg=mid+1;
  }
  else
  {
   end=mid-1;
  }
 }
 return 0;
}

void Print(int item,int loc)
{
 printf("%d is found at position %d",item,loc);
}
