/*
                          Program No:25
                             HASHING
                             *******
*/  
#include<stdio.h>
void main()
{
  int n,H[100],A[50],i,m,j,h,e,flag=0;
  printf("Enter the number of elements in the array:");
  scanf("%d",&n);
  printf("Enter %d elements:\n",n);
  for(i=0;i<n;i++)
  {
     printf("Enter element %d:",i+1);
     scanf("%d",&A[i]);
  }
  printf("Enter the size of the Hash table:");
  scanf("%d",&m);
  for(i=0;i<m;i++)
    H[i]=-1;
  for(i=0;i<n;i++)
  {
     j=0;h=-1;
     hash:
     h=((A[i]%m)+j)%m;
     if(h<m)
     {
	if(H[h]=-1)
	   H[h]=A[i];
	else
	{
	   j++;
	   goto hash;
	}
     }
     else
	goto hash;
  }
  printf("Hash table is:\n");
  for(i=0;i<m;i++)
  {
     if(H[i]==-1)
        printf("-");
     else
	printf("%d  ",H[i]);
  }
  printf("\nEnter the number to be searched:");
  scanf("%d",&e);
  for(i=0;i<m;i++)
  {
    if(H[i]==e)
    {
       flag=1;
       break;
    }
  }		
  if(flag==1)
    printf("The element %d is found. \nPosition:%d\nArray index:%d ",e,i+1,i);
  else
    printf("The element %d is not found!!!!!",e);
}
/*
OUTPUT
******
Enter the number of elements in the array:4
Enter 4 elements:
Enter element 1:4
Enter element 2:5
Enter element 3:6
Enter element 4:7
Enter the size of the Hash table:4
Hash table is:
4  5  6  7  
Enter the number to be searched:5
The element 5 is found. 
Position:2
Array index:1 
*/
