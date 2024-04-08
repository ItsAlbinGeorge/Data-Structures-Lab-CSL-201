/*
                          Program No:24
                           QUICK SORT
                           **********
*/
#include<stdio.h>
int p,loc;
int partition(int a[],int left,int right)
{
   int temp;
   loc=left;
   while(left<right)
   {
      while((a[loc]<=a[right])&&(loc<right))
      {
	right=right-1;
      }
      if(a[loc]>a[right])
      {
	temp=a[right];
	a[right]=a[loc];
	a[loc]=temp;
	loc=right;
	left=left+1;
      }
      while((a[loc]>=a[left])&&(loc>left))
      {
	left=left+1;
      }
      if(a[loc]<a[left])
      {
	temp=a[left];
	a[left]=a[loc];
	a[loc]=temp;
	loc=left;
	right=right-1;
      }
   }
   return loc;
}
void quicksort(int a[],int low,int high)
{
   if(low<high)
   {
      p=partition(a,low,high);
      quicksort(a,low,p-1);
      quicksort(a,p+1,high);
   }
}


void main()
{
   int low,high,n,i,a[100];
   printf("Enter the size:");
   scanf("%d",&n);
   high=n-1;low=0;
   printf("Enter the elements:\n");
   for(i=0;i<n;i++)
   {
      printf("Enter the element %d:",i+1);
      scanf("%d",&a[i]);
   }
   printf("The array is:\n");
   for(i=0;i<n;i++)
   {
     printf("%d   ",a[i]);
   }
   quicksort(a,low,high);
   printf("\nThe sorted array is:\n");
   for(i=0;i<n;i++)
   {
     printf("%d   ",a[i]);
   }
}
/*
OUTPUT
******
Enter the size:5
Enter the elements:
Enter the element 1:2
Enter the element 2:7
Enter the element 3:9
Enter the element 4:3
Enter the element 5:5
The array is:
2   7   9   3   5   
The sorted array is:
2   3   5   7   9 
*/
