/*
                             Program No:15
                          CIRCULAR LINKED LIST
                          ********************
 */
#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};
int Item,i,count=0;
struct Node *head=NULL;
void insert_beginning()
{ 
  struct Node *newNode;
  newNode=(struct Node *)malloc(sizeof(struct Node));
  printf("Enter the data:");
  scanf("%d",&Item);
  newNode->data=Item;
  if(head==NULL)
  {
   head=newNode;
   newNode->next=head;
   count=count+1;
  }
  else
  {
    struct Node *temp=head;
    while(temp->next!=head)
    {
     temp=temp->next;
    }
    newNode->next=head;
    head=newNode;
    temp->next=head;
    count++;
  }
}
void insert_end()
{
 struct Node *newNode;
  newNode=(struct Node *)malloc(sizeof(struct Node));
  printf("Enter the data:");
  scanf("%d",&Item);
  newNode->data=Item;
  if(head==NULL)
  {
   head=newNode;
   newNode->next=head;
   count=count+1;
  }
  else
  {
    struct Node *temp=head;
    while(temp->next!=head)
    {
     temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    count++;
  }
}
void insert_specified()
{
  struct Node *newNode;
  newNode=(struct Node *)malloc(sizeof(struct Node));
  printf("Enter the data:");
  scanf("%d",&Item);
  newNode->data=Item;
  if(head==NULL)
  {
   head=newNode;
   newNode->next=head;
   count++;
  }
  else
  {
    int position;
    struct Node *temp=head,*prev=head;
    printf("Enter the position:");
    scanf("%d",&position);
    if(position==1)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newNode->next=head;
        head=newNode;
        temp->next=head;
        count++;
    }
    else if(position==(count+1))
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=head;
        count++;
    }
    else if(position<=count)
    {
        for(i=1;i<position;i++)
        {
           prev=temp;
           temp=temp->next;
        }
        newNode->next=temp;
        prev->next=newNode;
        count++;
    }
    else
    {
     printf("Previous positions are empty\n");
    }
  }
}

void delete_beginning()
{
  if(head==NULL)
  {
    printf("Linked list is empty\n");
  }
  else
  {
    struct Node *temp=head,*temp1=head;
    if(temp->next==head)
    	head=NULL;
    else
    {
        while(temp1->next!=head)
        {
            temp1=temp1->next;
        }
        head=head->next;
        temp1->next=head;
    }
    printf("The deleted data=%d\n",temp->data);
    free(temp);
    count--;
  }
}

void delete_specified()
{
   if(head==NULL)
   {
       printf("Linked list is empty\n");
   }
   else
   { 
       int position;
       struct Node *temp=head,*prev,*temp1=head;
       printf("Enter the position:");
       scanf("%d",&position);
       if(position==1)
       {
            if(temp->next==head)
            {
           	head=NULL;
            }
            else
            {
                while(temp1->next!=head)
                {
                     temp1=temp1->next;
                }
                head=head->next;
                temp1->next=head;
            }
            printf("The deleted data=%d\n",temp->data);
            free(temp);
            count--;
      }
      else  if(position<=count)
      {
          for(i=1;i<position;i++)
          {
               prev=temp;
               temp=temp->next;
          }
          if(temp->next==head)
          {
               prev->next=head;
          }
          else
               prev->next=temp->next;
          printf("The deleted data=%d\n",temp->data);
          free(temp);
          count--;
      }
      else
          printf("Position not found\n"); 
    }
}
void delete_end()
{
    if(head==NULL)
    {
        printf("Linked list is empty\n");
    }
    else
    {
        struct Node *temp=head,*prev;
        if(temp->next==head)
          head=NULL;
        else
        {
            while(temp->next!=head)
            {
               prev=temp;
               temp=temp->next;
            }
            prev->next=head;
        }
        printf("The deleted data=%d\n",temp->data);
        free(temp);
        count--;
     }
}
void display()
{ 
   if(head==NULL)
   printf("Linked list is empty\n");
   else
   {
    printf("Circular Linked list is:\n");
    struct Node *temp=head;
    printf("HEAD-->");
    while(temp->next!=head)
    {
       printf("%d-->",temp->data);
       temp=temp->next;
     }
     printf("%d-->HEAD\n",temp->data);
   }
}
void main()
{
 int choice;
 while(choice!=8)
 {
  printf("\nLINKED LIST OPERATIONS\n1:Insertion at beginning\n2:Insertion at specified position\n3:Insertion at end\n4:Deletion from begining\n5:Deletion from specified position\n6:Deletion from end\n7:Display\n8:Exit\nENTER YOUR CHOICE:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:insert_beginning();
          break;
   case 2:insert_specified();
          break;
   case 3:insert_end();
          break;     
   case 4:delete_beginning();
          break;  
   case 5:delete_specified();
          break;
   case 6:delete_end();
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
LINKED LIST OPERATIONS
1:Insertion at beginning
2:Insertion at specified position
3:Insertion at end
4:Deletion from begining
5:Deletion from specified position
6:Deletion from end
7:Display
8:Exit
ENTER YOUR CHOICE:1
Enter the data:4

LINKED LIST OPERATIONS
1:Insertion at beginning
2:Insertion at specified position
3:Insertion at end
4:Deletion from begining
5:Deletion from specified position
6:Deletion from end
7:Display
8:Exit
ENTER YOUR CHOICE:2
Enter the data:5
Enter the position:2

LINKED LIST OPERATIONS
1:Insertion at beginning
2:Insertion at specified position
3:Insertion at end
4:Deletion from begining
5:Deletion from specified position
6:Deletion from end
7:Display
8:Exit
ENTER YOUR CHOICE:3
Enter the data:1

LINKED LIST OPERATIONS
1:Insertion at beginning
2:Insertion at specified position
3:Insertion at end
4:Deletion from begining
5:Deletion from specified position
6:Deletion from end
7:Display
8:Exit
ENTER YOUR CHOICE:7
Circular Linked list is:
HEAD-->4-->5-->1-->HEAD

LINKED LIST OPERATIONS
1:Insertion at beginning
2:Insertion at specified position
3:Insertion at end
4:Deletion from begining
5:Deletion from specified position
6:Deletion from end
7:Display
8:Exit
ENTER YOUR CHOICE:8

*/
