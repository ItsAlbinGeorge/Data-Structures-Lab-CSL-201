/*
                          Program No:11
                          CIRCULAR QUEUE
                          **************
 */
#include<stdio.h>
#include<stdlib.h>
int circularqueue[100],max_size,key,rear=-1,front=-1;
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
void enqueue()
{
  if(isfull()==1)
  printf("The circular queue is full\n");
  else
  {
     printf("Enter the element to insert:");
     scanf("%d",&key);
    {
       if(front==-1)
       {
          front=0;
          rear=0;
          circularqueue[rear]=key;
       }
       else
      {
          rear=(rear+1)%max_size;
          circularqueue[rear]=key;
       }
    }
  }
}
void dequeue()
{
  if(isempty()==1)
  printf("The circular queue is empty\n");
  else
  {
    if(front==rear)
    {
      key=circularqueue[front];
      front=-1;
      rear=-1;
    }
    else
    {
     key=circularqueue[front];
     front=(front+1)%max_size;
    }
    printf("The element deleted:%d\n",key);
  }
}
void display()
{
  int i;
  printf("CIRCULAR QUEUE IS:\n");
  for(i=front;;i=(i+1)%max_size)
  {
    printf("%d\n",circularqueue[i]);
    if(i==rear)
    break;
  }
  
}
void main()
{
  int choice;
  printf("Enter the size of circular queue:");
  scanf("%d",&max_size);
  while(choice!=6)
  { 
     printf("\nCIRCULAR QUEUE OPERATIONS\n");
     printf("1:isFull()\n2:isEmpty()\n3:Enqueue\n4:Dequeue\n5:Display\n6:exit\nENTER YOUR CHOICE:");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:if(isfull()==1)
              printf("The circular queue is full\n");
              else
              printf("The circular queue is not full\n");
              break;
       case 2:if(isempty()==1)
              printf("The circular queue is empty\n");
              else
              printf("The circular queue is not empty\n");
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
Enter the size of circular queue:3

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:1
The circular queue is not full

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:2
The circular queue is empty

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:4

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:5

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:4
The element deleted:4

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:6

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to insert:7

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:5
CIRCULAR QUEUE IS:
5
6
7

CIRCULAR QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:6
*/
