/*
                          Program No:8
                       POSTFIX EVALUATION
                       ******************
 */
#include<stdio.h>
#include<stdlib.h>
typedef enum
{
   lparen,rparen,plus,minus,times,divide,mod,eos,operand
}precedence;
int stack[100];
char expr[100];
char symbol;
int top=-1;
int n=0;
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
int eval()
{
    precedence token;
    int op1,op2;
    token=get_token();
    while (token!=eos)
    {
        if (token==operand)
        push(symbol-'0');
       else
       {
           op2=pop();
           op1=pop();
           switch(token)
           {
               case plus:push(op1+op2);break;
               case minus:push(op1-op2);break;
               case times:push(op1*op2);break;
               case divide:push(op1/op2);break;
               case mod:push(op1%op2);break;
           }
       }
       token=get_token();
    }
    return pop();
}
void main()
{
     int result;
     printf("Enter the postfix expression:");
     scanf("%s",expr);
     result=eval();
     printf("The result of %s is %d \n",expr,result);
}
/*
OUTPUT
******
Enter the postfix expression:56*3+
The result of 56*3+ is 33
*/
