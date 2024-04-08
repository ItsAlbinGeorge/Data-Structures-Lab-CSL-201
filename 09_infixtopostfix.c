/*
                          Program No:9
                 INFIX TO POSTFIX CONVERSION
                 ***************************
 */
#include<stdio.h>
#include<stdlib.h>
typedef enum
{
   lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
precedence stack[100];
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
char symbol,expr[100];
int n=0,top=0;
int pop()
{
   return stack[top--];
}
void push(int item)
{
   stack[++top]=item;
}
precedence get_token()
{
   symbol=expr[n++];
   switch(symbol)
   {
       case '(':return lparen;break;
       case ')':return rparen;break;
       case '+':return plus;break;
       case '-':return minus;break;
       case '/':return divide;break;
       case '*':return times;break;
       case '%':return mod;break;
       case '\0':return eos;break;
       default:return operand;
   }
}
void print_token(precedence S)
{
   switch(S)
   {
       case 2:printf("+");break;
       case 3:printf("-");break;
       case 4:printf("*");break;
       case 5:printf("/");break;
       case 6:printf("%%");break;
   }
}
void postfix()
{
	precedence token;
	stack[0]=eos;
	for(token=get_token();token!=eos;token=get_token())
	{
		if(token==operand)
		printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
			print_token(pop());
			pop();
		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			print_token(pop());
			push(token);
		}
	}
	while((token=pop(top))!=eos)
	print_token(token);
	printf("\n");
}
void main()
{
	printf("ENTER THE EXPRESSION:");
	scanf("%s",expr);
	printf("THE POSTFIX EXPRESSION IS: ");
	postfix();	 
}
/*
OUTPUT
******
ENTER THE EXPRESSION:(5+2)/8+7
THE POSTFIX EXPRESSION IS: 52+8/7+

[Program finished]
*/
