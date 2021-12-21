#include<stdio.h>
#include "abc.h"
void Insort(int [],int);

void main()
{
 int A[100],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
 Insort(A,n);
 Print(A,n);
}


void Insort(int A[],int n)
{
 int i,j,key;
 for(i=1;i<n;i++)
 {
  key=A[i];
  for(j=i-1;j>=0 && A[j]>key;j--)
  {
   A[j+1]=A[j];
  }
  A[j+1]=key;
 }
}

