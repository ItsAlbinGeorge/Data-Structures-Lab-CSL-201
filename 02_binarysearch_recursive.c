/*
                          Program No:2
                          BINARY SEARCH
                          *************
 */
#include<stdio.h>
int binarysearch(int arr[],int x,int low,int high);
void main()
{
	int a[20],n,i,j,temp,l,h,s,key;
	printf("ENTER THE ARRAY SIZE:");
	scanf("%d",&n);
	printf("ENTER THE ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("THE SORTED ARRAY IS: \n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
		printf("\nENTER THE ELEMENT TO BE SEARCHED:");
	scanf("%d",&key);
	l=0;
	h=n-1;
	s=binarysearch(a,key,l,h);
	if(s==-1)
	{
		printf("THE ELEMENT %d NOT FOUND",key);
	}
	else
	{
		printf("THE ELEMENT %d FOUND IN POSITION %d",key,s);
	}
}
int binarysearch(int arr[],int x,int low,int high)
{
	if(low>high)
	{
		return -1;
	}
	else
	{
		int mid;
		mid=(low+high)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]>x)
		{
			return binarysearch(arr,x,low,mid-1);
		}
		else
		{
			return binarysearch(arr,x,mid+1,high);
		}
	}
}
/*
OUTPUT 1
********
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
ENTER THE ELEMENT TO BE SEARCHED:7
THE ELEMENT 7 FOUND IN POSITION 3

OUTPUT 2
********
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
ENTER THE ELEMENT TO BE SEARCHED:6
THE ELEMENT 6 NOT FOUND
*/
