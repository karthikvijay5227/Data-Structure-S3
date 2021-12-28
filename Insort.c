#include<stdio.h>

void Read(int [],int);
void Insort(int [],int);
void Print(int [],int);

void main()
{
 int A[100],n;
 printf("Enter the size:");
 scanf("%d",&n);
 Read(A,n);
 Insort(A,n);
 Print(A,n);
}

void Read(int A[],int n)
{
 printf("Enter the elements:");
 for(int i=0;i<n;i++)
 {
  scanf("%d",&A[i]);
 } 
 printf("Array before sorting is:");
 for(int i=0;i<n;i++)
 {
  printf("%d ",A[i]);
 }
}

void Print(int A[],int n)
{
 printf("\nThe sorted array is:");
 for(int i=0;i<n;i++)
 {
  printf("%d ",A[i]);
 }
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

