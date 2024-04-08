/*
                          Program No:2
                          BINARY SEARCH
                          *************
 */
 #include<stdio.h>
void main()
{
	int a[20],n,i,j,temp,key,flag=0,low,mid,high;
	printf("ENTER THE ARRAY SIZE:");
	scanf("%d",&n);
	printf("ENTER THE  ARRAY ELEMENTS:");
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
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key<a[mid])
		{
			high=mid-1;
		}
		else if(key>a[mid])
		{
			low=mid+1;
		}
		else
		{
			printf("THE ELEMENT %d FOUND IN POSITION %d",key,mid);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("THE ELEMENT %d NOT FOUND",key);
	}
	
}
/*
OUTPUT 1
********
ENTER THE ARRAY SIZE:5
ENTER THE  ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
ENTER THE ELEMENT TO BE SEARCHED:7
THE ELEMENT 7 FOUND IN POSITION 3

OUTPUT 2
********
ENTER THE ARRAY SIZE:5
ENTER THE  ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
ENTER THE ELEMENT TO BE SEARCHED:6
THE ELEMENT 6 NOT FOUND
*/
