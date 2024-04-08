/*
                          Program No:5
                       POLYNOMIAL ADDITION
                       *******************
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
typedef struct
{
 float coef;
 int expon;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;
int compare(int a,int b)
{
	if(a>b)
	return -1;
	else if(a==b)
	return 0;
	else
	return 1;
}
void displaypoly(int min,int max)
{
	for(int i=min;i<=max;i++)
	{
		printf("%f(x^%d)",terms[i].coef,terms[i].expon);
		if(i<max)
		printf("+");
	}
	printf("\n");
}
void attach(float coefficient,int exponent)
{
	if(avail>=MAX_TERMS)
	{
		printf("Too many terms in the polynomial\n");
		exit(0);
	}
	terms[avail].coef=coefficient;
	terms[avail].expon=exponent;
	avail++;
}
void padd(int starta,int finisha,int startb,int finishb,int startd,int finishd)
{
	float coefficient;
	startd=avail;
	while(starta<=finisha&&startb<=finishb)
	{     
		switch(compare(terms[starta].expon,terms[startb].expon))
		{
			case -1:attach(terms[starta].coef,terms[starta].expon);
			          starta++;
			          break;
			case 0:coefficient=terms[starta].coef+terms[startb].coef;
			          if(coefficient)
			          attach(coefficient,terms[startb].expon);
			          starta++;
			          startb++;
			          break;
			case 1:attach(terms[startb].coef,terms[startb].expon);
			          startb++;
			          break;
		}
	}
	for(;starta<=finisha;starta++)
	attach(terms[starta].coef,terms[starta].expon);
	for(;startb<=finishb;startb++)
	attach(terms[startb].coef,terms[startb].expon);
	finishd=avail-1;
	displaypoly(startd,finishd);
}
void main()
{
	 int n=0,expon,m,starta,finisha,startb,finishb;
	 float coef;
	 printf("OPERATIONS:\nAdd two polynomials\n");
	 printf("Enter terms in first polynomial\n");
	 printf("Enter coefficient=0 and exponent=0 to stop attaching terms\n");
	 starta=avail;
	 while(1)
	  {
	   	printf("\nEnter term to attach the polynomial\n");
	   	printf("Enter the coefficient:");
	   	scanf("%f",&coef);
	   	printf("Enter exponent:");
	   	scanf("%d",&expon);
	   	n++;
	   	if(coef==0&&expon==0)
	   	break;
	   	else
	   	attach(coef,expon);
	  }
	  finisha=n-2;
	  printf("\nEnter terms in second polynomial:\n");
	  printf("Enter coefficient=0 and exponent=0 to stop attaching terms\n");
	  startb=avail;
	  while(1)
	  {
	  	printf("\nEnter the term to attach to the polynomial\n");
	  	printf("Enter the coefficient:");
	  	scanf("%f",&coef);
	  	printf("Enter the exponent:");
	  	scanf("%d",&expon);
	  	n++;
	  	if(coef==0&&expon==0)
	  	break;
	  	else
	  	attach(coef,expon);
	  }
	  finishb=n-3;
	  printf("\nFirst polynomial:\n");
	  displaypoly(starta,finisha);
	  printf("\nSecond polynomial:\n");
	  displaypoly(startb,finishb);
	  printf("\nAdding two polynomials\n");
	  displaypoly(starta,finisha);
	  printf("+\n");
	  displaypoly(startb,finishb);
	  printf("=\n");
	  padd(starta,finisha,startb,finishb,0,0);	  
}
/*
OUTPUT
******
OPERATIONS:
Add two polynomials
Enter terms in first polynomial
Enter coefficient=0 and exponent=0 to stop attaching terms

Enter term to attach the polynomial
Enter the coefficient:9
Enter exponent:4

Enter term to attach the polynomial
Enter the coefficient:5
Enter exponent:2

Enter term to attach the polynomial
Enter the coefficient:6
Enter exponent:1

Enter term to attach the polynomial
Enter the coefficient:0
Enter exponent:0

Enter terms in second polynomial:
Enter coefficient=0 and exponent=0 to stop attaching terms

Enter the term to attach to the polynomial
Enter the coefficient:5
Enter the exponent:3

Enter the term to attach to the polynomial
Enter the coefficient:4
Enter the exponent:2

Enter the term to attach to the polynomial
Enter the coefficient:1
Enter the exponent:0

Enter the term to attach to the polynomial
Enter the coefficient:0
Enter the exponent:0

First polynomial:
9.000000(x^4)+5.000000(x^2)+6.000000(x^1)

Second polynomial:
5.000000(x^3)+4.000000(x^2)+1.000000(x^0)

Adding two polynomials
9.000000(x^4)+5.000000(x^2)+6.000000(x^1)
+
5.000000(x^3)+4.000000(x^2)+1.000000(x^0)
=
9.000000(x^4)+5.000000(x^3)+9.000000(x^2)+6.000000(x^1)+1.000000(x^0)
*/
