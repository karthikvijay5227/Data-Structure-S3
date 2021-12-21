#include<stdio.h>
#include "abc.h"
void Ssort(int [],int);
void Swap(int *,int *);

int main()
{
 int A[100],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
 Ssort(A,n);
 Print(A,n);
 return 0;
}

void Ssort(int A[],int n)
{
 for(int i=0;i<n-1;i++)
 {
  int small=A[i],ind=i;
  for(int j=i+1;j<n;j++)
  {
   if(A[j]<small)
   {
     small=A[j];
     ind=j;
   }
  }
  Swap(&A[i],&A[ind]);
 }
}

void Swap(int *a,int *b)
{
 int t=*a;
 *a=*b;
 *b=t;
}

