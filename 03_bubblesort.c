/*
                          Program No:3
                           BUBBLE SORT
                           ***********
 */
 #include<stdio.h>
void main()
{
	int a[20],n,i,j,temp;
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
}
/*
OUTPUT
******
ENTER THE ARRAY SIZE:5
ENTER THE ARRAY ELEMENTS:3 9 1 5 7
THE SORTED ARRAY IS:
 1  3  5  7  9
*/
