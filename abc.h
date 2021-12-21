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
