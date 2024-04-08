/*

                           Program No:1
                          LINEAR SEARCH
                          *************
 */
#include<stdio.h>
void main()
{
	int a[20],n,i,key,flag=0;
	printf("ENTER THE ARRAY SIZE:");
	scanf("%d",&n);
	printf("ENTER THE ARRAY ELEMENTS:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("ENTER THE ELEMENT TO BE SEARCHED:");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("THE ELEMENT %d FOUND IN POSITION %d",key,i);
	}
	else
	printf("THE ELEMENT %d NOT FOUND",key);
}
/*
OUTPUT 1
********
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
ENTER THE ELEMENT TO BE SEARCHED:1
THE ELEMENT 1 FOUND IN POSITION 2

OUTPUT 2
********
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
ENTER THE ELEMENT TO BE SEARCHED:6
THE ELEMENT 6 NOT FOUND
*/
