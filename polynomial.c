#include<stdio.h>
typedef struct
{
 int coeff;
 int exp;
}t;
t term[50];

void main()
{
 int n,i;
 printf("Enter the highest degree:");
 scanf("%d",&n);
 for(i=0;i<=n;i++)
 {
  printf("Enter the coefficient of x^%d:",i);
  scanf("%d",&term[i].coeff);
  printf("Enter the exponent of %d term:",i);
  scanf("%d",&term[i].exp);
 }
 printf("The polynomial is:\n");
 for(i=n;i>0;i--)
 {
  printf("%dx^%d+",term[i].coeff,term[i].exp);
 }
  printf("%d",term[0].coeff);
}
  
