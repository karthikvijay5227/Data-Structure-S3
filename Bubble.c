#include<stdio.h>
#include "abc.h"
void Bubble(int [],int);
void Swap(int *,int *);


int main()
{
 int A[100],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
 Bubble(A,n);
 Print(A,n);
 return 0;
}

void Bubble(int A[],int n)
{
 for(int i=0;i<n-1;i++)
 {
  for(int j=0;j<n-1-i;j++)
  {
   if(A[j]>A[j+1])
   {
    Swap(&A[j],&A[j+1]);
   }
  }
 }
}

void Swap(int *a,int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}
