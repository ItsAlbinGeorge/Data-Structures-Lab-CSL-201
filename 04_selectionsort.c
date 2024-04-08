/*
                          Program No:4
                         SELECTION SORT
                         **************
 */
#include<stdio.h>
void main()
{
	int a[20],n,i,j,temp,pos;
	printf("ENTER THE ARRAY SIZE:");
	scanf("%d",&n);
	printf("ENTER THE ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
			{
				pos=j;
			}
		}
		temp=a[pos];
		a[pos]=a[i];
		a[i]=temp;
	}
	printf("THE SORTED ARRAY IS: \n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
/*
OUTPUT
******
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
*/
