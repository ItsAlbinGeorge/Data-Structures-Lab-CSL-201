/*
                           Program No:13
                          PRIORITY QUEUE
                          **************
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct
{  
   int key,p;
}element;
int max_size,rear=-1,front=-1;
element queue[100];
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
void enqueue(element item)
{
  if(front==-1&&rear==-1)
  {
  	front=0;
  }
  queue[++rear]=item;
}
element dequeue()
{
	int i,j;
	element temp,item;
	for(i=front;i<=rear;i++)
	{
		for(j=i+1;j<=rear;j++)
		{
			temp=queue[j];
			queue[j]=queue[i];
			queue[i]=temp;
		}
	}
	item=queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else
	{
		front++;
	}
	return item;
}
void display()
{
  int i;
  printf("\n PRIORITY QUEUE IS:\n");
  for(i=front;i<=rear;i++)
  {
    printf("Item:%d\n",queue[i].key);
    printf("Priority:%d\n\n",queue[i].p);
  }
}
void main()
{
  int choice;
  element add,remove;
  printf("Enter the size of Priority queue:");
  scanf("%d",&max_size);
  while(choice!=6)
  { 
     printf("\n PRIORITY QUEUE OPERATIONS\n");
     printf("1:isFull()\n2:isEmpty()\n3:Enqueue\n4:Dequeue\n5:Display\n6:exit\nENTER YOUR CHOICE:");
     scanf("%d",&choice);
     switch(choice)
     {
       case 1:if(isfull()==1)
                printf("The Priority queue is full\n");
                else
                printf("The Priority queue is not full\n");
                break;
       case 2:if(isempty()==1)
                printf("The Priority queue is empty\n");
                else
                printf("The Priority queue is not empty\n");
                break;
       case 3:if(isfull()==1)
                 printf("The Priority queue is full\n");
                 else
                 {
                   printf("Enter the element to be added:");
                   scanf("%d",&add.key);
                   printf("Enter the priority:");
                   scanf("%d",&add.p);
                   enqueue(add);
                 }
                break;
       case 4:if(isempty()==1)
                 printf("The Priority queue is  empty\n");
                 else
                 {
                   remove=dequeue();
                   printf("Element deleted:%d\n",remove.key);
                 }
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
Enter the size of Priority queue:3

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:1
The Priority queue is not full

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:2
The Priority queue is empty

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to be added:7
Enter the priority:9

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to be added:6
Enter the priority:7

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:3
Enter the element to be added:3
Enter the priority:4

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:5

 PRIORITY QUEUE IS:
Item:7
Priority:9

Item:6
Priority:7

Item:3
Priority:4


 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:4
Element deleted:3

 PRIORITY QUEUE OPERATIONS
1:isFull()
2:isEmpty()
3:Enqueue
4:Dequeue
5:Display
6:exit
ENTER YOUR CHOICE:6
*/
