#include<stdio.h>
#include "abc.h"
void Mergesort(int [],int,int);
void SimpleMerge(int [],int,int,int);

void main()
{
 int A[50],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
 Mergesort(A,0,n-1);
 Print(A,n);
}

void Mergesort(int A[],int beg,int end)
{
 if(beg<end)
 {
  int mid=(beg+end)/2;
  Mergesort(A,beg,mid);
  Mergesort(A,mid+1,end);
  SimpleMerge(A,beg,mid+1,end);
 }
}

void SimpleMerge(int A[],int f,int s,int t)
{
 int temp[100],i=f,j=s,k=0;

 while(i<s && j<=t)
 {
  if(A[i]<A[j])
  {
   temp[k++]=A[i++];
  }
  else
  {
   temp[k++]=A[j++];
  }
 }

 while(i<s)
 {
  temp[k++]=A[i++];
 }
 while(j<=t)
 {
  temp[k++]=A[j++];
 }
 
 for(i=f,j=0;j<k;)
 {
  A[i++]=temp[j++];
 }
}

