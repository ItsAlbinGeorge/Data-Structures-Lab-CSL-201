/*
                          Program No:7
                             STACK
                             *****
 */
#include<stdio.h>
#include<stdlib.h>
int stack[100],n,x,c,a,top=-1;
int isFull()
{
  if(top>=n-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int isEmpty()
{
  if(top==-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void push()
{
  if(isFull()==1)
  {
    printf("Stack overflow\n");
  }
  else
  {
   printf("Enter the element to be pushed:");
   scanf("%d",&x);
   top=top+1;
   stack[top]=x; 
  }
}
void pop()
{
  if(isEmpty()==1)
  {
    printf("Stack underflow\n");
  }
  else
  {
     printf("The element poped:%d\n",stack[top]);
     top=top-1;
  }
}
void display()
{
  printf("\n\nSTACK\n");
  int i;
  for(i=0;i<=top;i++)
  {
    printf("%d\n",stack[i]);
  }
}
int main()
{
  printf("Enter the size of the stack:");
  scanf("%d",&n);
  do
  { 
    printf("\nSTACK FUNCTIONS\n");
    printf("1.Push\n2.Pop\n3.Display\n4.IsEmpty\n5.Isfull\n6.Exit\nEnter your choice:");
    scanf("%d",&c);
    switch(c)
    {
      case 1:push();
             break;
      case 2:pop();
             break;
      case 3:display();
             break;
      case 4:if(isEmpty()==1)
             {
               printf("The stack is empty\n");
             }
             else
             {
               printf("The stack is not empty\n");
             }
             break;
       case 5:if(isFull()==1)
             {
               printf("The stack is full\n");
             }
             else
             {
               printf("The stack is not full\n");
             }
             break;
       case 6:exit(0);
              break;
       default:printf("Enter valid case\n");
               break;
             
    }
    
  }while(c!=6);
  return 0;
}
/*
OUTPUT
******
Enter the size of the stack:3

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:4
The stack is empty

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:5
The stack is not full

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:2
Stack underflow

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:1
Enter the element to be pushed:6

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:1
Enter the element to be pushed:4

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:1
Enter the element to be pushed:7

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:1
Stack overflow

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:2
The element poped:7

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:3


STACK
6
4

STACK FUNCTIONS
1.Push
2.Pop
3.Display
4.IsEmpty
5.Isfull
6.Exit
Enter your choice:6
*/
