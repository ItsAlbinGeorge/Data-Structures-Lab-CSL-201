/*
                          Program No:23
                           MERGE SORT
                           **********
*/
#include<stdio.h>
int a[20];
int merge(int left1,int right1,int left2,int right2)
{
   int i=left1,j=left2,c[100],k=0;
   while((i<=right1)&&(j<=right2))
   {
      if(a[i]<a[j])
      {
	c[k]=a[i];
	i++;
	k++;
      }
      else
      {
	c[k]=a[j];
	j++;
	k++;
      }
    }
    while(i<=right1)
    {
       c[k]=a[i];
       i++;
       k++;
    }
    while(j<=right2)
    {
       c[k]=a[j];
       j++;
       k++;
    }
    for(i=left1,k=0;i<=right2;i++,k++)
    {
      a[i]=c[k];
    }
    return 1;
}
int merge_sort(int left,int right)
{
   int mid;
   if(right>left)
   {
      mid=(left+right)/2;
      merge_sort(left,mid);
      merge_sort(mid+1,right);
      merge(left,mid,mid+1,right);
   }
   return 1;
} 
void main()
{
   int n,i,j=0;
   printf("Enter the size:");
   scanf("%d",&n);
   printf("Enter the array elements:\n");
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
   merge_sort(j,n-1);
   printf("\nThe sorted array is\n");
   for(i=0;i<n;i++)
   {
      printf("%d   ",a[i]);
   }
}
/*
OUTPUT
******
Enter the size:5
Enter the array elements:
Enter the element 1:2
Enter the element 2:7
Enter the element 3:9
Enter the element 4:3
Enter the element 5:5
The array is:
2   7   9   3   5   
The sorted array is
2   3   5   7   9
*/
