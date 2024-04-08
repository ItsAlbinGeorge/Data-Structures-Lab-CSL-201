/*
                          Program No:22
                         INSERTION SORT
                         **************
*/
#include<stdio.h>
int a[20],l;
void insertion_sort()
{
  int i,j,item;
  for(i=0;i<l;i++)
  {
    item=a[i];
    j=i-1;
    while(j>=0&&item<a[j])
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=item;
  }
}
void display()
{
  int i;
  for(i=0;i<l;i++)
  {
    printf("%d   ",a[i]);
  }
}
void main()
{
  int i;
  printf("Enter the size:");
  scanf("%d",&l);
  printf("Enter the array elemets:\n");
  for(i=0;i<l;i++)
  {
    printf("Enter the element %d:",i+1);
    scanf("%d",&a[i]);
  }
  printf("ARRAY IS:\n");
  display();
  insertion_sort();
  printf("\nSORTED ARRAY IS:\n");
  display();
}
/*
OUTPUT
******
Enter the size:5
Enter the array elemets:
Enter the element 1:3
Enter the element 2:7
Enter the element 3:4
Enter the element 4:9
Enter the element 5:1
ARRAY IS:
3   7   4   9   1   
SORTED ARRAY IS:
1   3   4   7   9 
*/
