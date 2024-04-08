/*
                        Program No:17
               POLYNOMIAL ADDITION(Linked List)
               ********************************
 */
#include<stdlib.h>
#include<stdio.h>
struct poly
{
	float coef;
	int expo;
	struct poly *next;
};
void display(struct poly *head6)
{
	if(head6==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		struct poly *ptr=head6;
		while(ptr->next!=NULL)
		{
			printf("%f(X^%d)+",ptr->coef,ptr->expo);
			ptr=ptr->next;
		}
		printf("%f(X^%d)",ptr->coef,ptr->expo);
	}
}
struct poly *insert(struct poly *head3,float co,int ex)
{
	struct poly *temp=head3;
	struct poly *newNode;
	newNode=(struct poly *)malloc(sizeof(struct poly));
	newNode->coef=co;
	newNode->expo=ex;
	newNode->next=NULL;
	if(head3==NULL)
	{
		head3=newNode;	
	}
	else
	{ 
	    while(temp->next!=NULL&&temp->next->expo>=ex)
	    {
	    	temp=temp->next;
	    }
	    newNode->next=temp->next;
	    temp->next=newNode;
	}
	return head3;	
}
struct poly *create(struct poly *head)
{
	int n,i,exponent;
	float coefficient;
	printf("ENTER THE NUMBER OF NODES:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	   printf("Enter the coefficient for node %d:",i+1);
           scanf("%f",&coefficient);
    	   printf("Enter the exponent for node %d  :",i+1);
    	   scanf("%d",&exponent);
    	   head=insert(head,coefficient,exponent);
	}
	return head;
}
void polyadd(struct poly *head3,struct poly *head4)
{
	struct poly *ptr1=head3,*ptr2=head4,*head5=NULL;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->expo>ptr2->expo)
		{ 
		    head5=insert(head5,ptr1->coef,ptr1->expo);
		    ptr1=ptr1->next;
		}
		else if(ptr1->expo<ptr2->expo)
		{
	            head5=insert(head5,ptr2->coef,ptr2->expo);
		    ptr2=ptr2->next;
		}
		else if(ptr1->expo==ptr2->expo)
		{
		    head5=insert(head5,ptr2->coef+ptr1->coef,ptr2->expo);
		    ptr2=ptr2->next;
		    ptr1=ptr1->next;
		}
	}
	while(ptr1!=NULL)
	{
		head5=insert(head5,ptr1->coef,ptr1->expo);
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		head5=insert(head5,ptr2->coef,ptr2->expo);
		ptr2=ptr2->next;
	}
	printf("\nPOLINOMIAL ADDITION\n");
	display(head3);
	printf("\n+\n");
	display(head4);
	printf("\n=\n");
	display(head5);
}
void main()
{
    struct poly *head1=NULL;
    struct poly *head2=NULL;
    printf("POLYNOMIAL 1\n");
    head1=create(head1);
    printf("POLYNOMIAL 2\n");
    head2=create(head2);
    polyadd(head1,head2);
}
/*
OUTPUT
******
POLYNOMIAL 1
ENTER THE NUMBER OF NODES:3
Enter the coefficient for node 1:4
Enter the exponent for node 1  :3
Enter the coefficient for node 2:6
Enter the exponent for node 2  :2
Enter the coefficient for node 3:7
Enter the exponent for node 3  :1
POLYNOMIAL 2
ENTER THE NUMBER OF NODES:2
Enter the coefficient for node 1:8
Enter the exponent for node 1  :2
Enter the coefficient for node 2:6
Enter the exponent for node 2  :0

POLINOMIAL ADDITION
4.000000(X^3)+6.000000(X^2)+7.000000(X^1)
+
8.000000(X^2)+6.000000(X^0)
=
4.000000(X^3)+14.000000(X^2)+7.000000(X^1)+6.000000(X^0)
*/
