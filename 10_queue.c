/*
                           Program No:10
                           SIMPLE QUEUE
                           ************
 */
#include<stdio.h>
#include<stdlib.h>
int queue[100],max_size,key,rear=-1,front=-1;
int isfull()
{
  if(rear>=max_size-1)
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
void enqueue()
{
  if(isfull()==1)
  printf("The queue is full\n");
  else
  {
     printf("Enter the element to insert:");
     scanf("%d",&key);
     {
        if(front==-1&&rear==-1)
        {
           front=0;
         }
        queue[++rear]=key;
      }
  }
}
void dequeue()
{
  if(isempty()==1)
  printf("The queue is empty\n");
  else
  {
    if(front==rear)
    {
      key=queue[front];
      front=-1;
      rear=-1;
    }
    else
    {
     key=queue[front];
     front++;
    }
    printf("The element deleted:%d\n",key);
  }
}
void display()
{
  int i;
  printf("QUEUE IS:\n");
  for(i=front;i<=rear;i++)
  {
    printf("%d\n",queue[i]);
  }
}
void main()
{
  int choice;
  printf("Enter the size of queue:");
  scanf("%d",&max_size);
  while(choice!=6)
  { 
     printf("\nQUEUE OPERATIONS\n");
     printf("1:isFull()\n2:isEmpty()\n3:Enqueue\n4:Dequeue\n5:Display\n6:exit\nENTER YOUR CHOICE:");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:if(isfull()==1)
              printf("The queue is full\n");
              else
              printf("The queue is not full\n");
              break;
       case 2:if(isempty()==1)
              printf("The queue is empty\n");
              else
              printf("The queue is not empty\n");
              break;
       case 3:enqueue();
              break;
       case 4:dequeue();
              break;
       case 5:display();
              break;
       case 6:exit(0);
              break;
       default:printf("Enter valid case\n");
     } 
  }
}
/*
OUTPUT
******
Enter the size of queue:3

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:1
The queue is not full

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:2
The queue is empty

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:9

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:8

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:7

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:4
The element deleted:9

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:5
QUEUE IS:
8
7

QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:6
*/
