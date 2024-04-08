/*
                          Program No:18
              POLYNOMIAL MULTIPLICATION(Linked List)
              **************************************
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
	newNode=malloc(sizeof(struct poly));
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
void polymultiply(struct poly *head3,struct poly *head4)
{
	float c;
	int e;
	struct poly *ptr1=head3,*head5=NULL;
	while(ptr1!=NULL)
	{
		struct poly *ptr2=head4;
		while(ptr2!=NULL)
		{
			c=ptr1->coef*ptr2->coef;
			e=ptr1->expo+ptr2->expo;
			head5=insert(head5,c,e);
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
	struct poly *ptr3=head5;
	while(ptr3->next!=NULL)
	{
		struct poly *temp=NULL;
		if(ptr3->expo==ptr3->next->expo)
		{
			ptr3->coef=ptr3->coef+ptr3->next->coef;
			temp=ptr3->next;
		        ptr3->next=temp->next;
			free(temp);
			temp=NULL;
		}
		else
		{
			ptr3=ptr3->next;
		}
	}
	printf("\nPOLINOMIAL MULTIPLICATION\n");
	display(head3);
	printf("\n×\n");
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
    polymultiply(head1,head2);
}
/*
OUTPUT
******
POLYNOMIAL 1
ENTER THE NUMBER OF NODES:3
Enter the coefficient for node 1:5
Enter the exponent for node 1  :3
Enter the coefficient for node 2:4
Enter the exponent for node 2  :2
Enter the coefficient for node 3:7
Enter the exponent for node 3  :0
POLYNOMIAL 2
ENTER THE NUMBER OF NODES:3
Enter the coefficient for node 1:8
Enter the exponent for node 1  :3
Enter the coefficient for node 2:7
Enter the exponent for node 2  :2
Enter the coefficient for node 3:9
Enter the exponent for node 3  :1

POLINOMIAL MULTIPLICATION
5.000000(X^3)+4.000000(X^2)+7.000000(X^0)
×
8.000000(X^3)+7.000000(X^2)+9.000000(X^1)
=
40.000000(X^6)+67.000000(X^5)+73.000000(X^4)+92.000000(X^3)+49.000000(X^2)+63.000000(X^1)
*/
