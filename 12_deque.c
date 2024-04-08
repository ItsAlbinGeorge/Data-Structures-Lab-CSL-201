/*
                          Program No:12
                              DEQUE
                              *****
 */
#include<stdio.h>
#include<stdlib.h>
int deque[100],max_size,key,rear=-1,front=-1;
int isfull()
{
  if(front==(rear+1)%max_size)
  return 1;
  else
  return 0;
}
int isempty()
{
  if(front==-1)
  return 1;
  else
  return 0;
}
void inject()
{
  if(isfull()==1)
  printf("The deque is full\n");
  else
  {
     printf("Enter the element to insert:");
     scanf("%d",&key);
     {
       if(front==-1)
       {
          front=0;
          rear=0;
          deque[rear]=key;
        }
        else
        {
           rear=(rear+1)%max_size;
           deque[rear]=key;
        }
     }
  }
}
void pop_dq()
{
  if(isempty()==1)
  printf("The deque is empty\n");
  else
  {
    if(front==rear)
    {
      key=deque[front];
      front=-1;
      rear=-1;
    }
    else
    {
     key=deque[front];
     front=(front+1)%max_size;
    }
    printf("The element deleted:%d\n",key);
  }
}
void push_dq()
{
  int ahead;
  if(front==0)
  {
    ahead=max_size-1;
  }
  else if(front==-1)
  {
      ahead=0;
  }
  else
  {
   ahead=front-1;
  }
  if(ahead==rear)
  {
    printf("Deque is full\n");
  }
  else
  {
    printf("Enter the element to insert:");
    scanf("%d",&key);
    front=ahead;
    deque[front]=key;
  }
}
void eject()
{
  if(front==-1)
  {
   printf("Deque is empty\n");
  }
  else if(front==rear)
  {
    key=deque[rear];
    front=rear=-1;
    printf("The element deleted:%d\n",key);
  }
  else if(rear==0)
  {
   key=deque[rear];
   rear=max_size-1;
   printf("The element deleted:%d\n",key);
  }
  else
  {
    key=deque[rear];
    rear=rear-1;
    printf("The element deleted:%d\n",key);
  }
}
void display()
{
  int i;
  printf("DEQUE IS:\n");
  for(i=front;;i=(i+1)%max_size)
  {
    printf("%d\n",deque[i]);
    if(i==rear)
    break;
  }
}
void main()
{
  int choice;
  printf("Enter the size of deque:");
  scanf("%d",&max_size);
  while(choice!=8)
  { 
     printf("\nDEQUE OPERATIONS\n");             printf("1:isFull()\n2:isEmpty()\n3:Inject\n4:pop_dq\n5:push_dq\n6:Eject\n7:Display\n8:exit\nENTER YOUR CHOICE:");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:if(isfull()==1)
              printf("The deque is full\n");
              else
              printf("The deque is not full\n");
              break;
       case 2:if(isempty()==1)
              printf("The deque is empty\n");
              else
              printf("The deque is not empty\n");
              break;
       case 3:inject();
              break;
       case 4:pop_dq();
              break;
       case 5:push_dq();
              break;
       case 6:eject();
              break;
       case 7:display();
              break;  
       case 8:exit(0);
              break;
       default:printf("Enter valid case\n");
     } 
  }
}
/*
OUTPUT
******
Enter the size of deque:3

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:1
The deque is not full

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:2
The deque is empty

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:3
Enter the element to insert:4

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:5
Enter the element to insert:3

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:3
Enter the element to insert:5

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:7
DEQUE IS:
3
4
5

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:6
The element deleted:5

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:4
The element deleted:3

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:7
DEQUE IS:
4

DEQUE OPERATIONS
1:isFull()
2:isEmpty()
3:Inject
4:pop_dq
5:push_dq
6:Eject
7:Display
8:exit
ENTER YOUR CHOICE:8
*/
