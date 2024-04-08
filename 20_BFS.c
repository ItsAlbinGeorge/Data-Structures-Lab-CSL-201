/*
                          Program No:20
                       BREADTH FIRST SEARCH
                       ********************
*/  
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int queue[MAX],front=-1,rear=-1,n;
int adj[MAX][MAX];
int state[MAX];
void insert_queue(int vertex)
{
   if(rear==MAX-1)
   {
      printf("Queue overflow\n");
   }
   else
   {
      if(front==-1)
	  front=0;
      rear=rear+1;
      queue[rear]=vertex;
   }
}
int isEmpty_queue()
{
   if((front==-1)||(front>rear))
     return 1;
   else
     return 0;
}
int delete_queue()
{
   int delete_item;
   if((front==-1)||(front>rear))
   {
      printf("queue underflow");
      exit(1);
   }
   delete_item=queue[front];
   front=front+1;
   return delete_item;
}
void BFS(int v)
{
   int i;
   insert_queue(v);
   state[v]=waiting;
   while(!isEmpty_queue())
   {
     v=delete_queue();
     printf("%d  ",v);
     state[v]=visited;
     for(i=0;i<n;i++)
     {
       if((adj[v][i]==1)&&(state[i]==initial))
       {
	  insert_queue(i);
	  state[i]=waiting;
       }
     }
   }
   printf("\n");
}
void BF_traversal()
{
   int v;
   for(v=0;v<n;v++)
      state[v]=initial;
   printf("Enter start vertex for bfs:");
   scanf("%d",&v);
   printf("The graph traversal is:\n");
   BFS(v);
}
void create_graph()
{
   int i,max_edge,origin,destin;
   printf("Enter no of vertices:");
   scanf("%d",&n);
   max_edge=n*(n-1);
   for(i=1;i<=max_edge;i++)
   {
      printf("Enter the edge %d:",i);
      scanf("%d%d",&origin,&destin);
      if((origin==-1)&&(destin==-1))
         break;
      if((origin>=n)||(destin>=n)||(origin<0)||(destin<0))
      {
	printf("invalid edge\n");
	i--;
      }
      else
      {
	adj[origin][destin]=1;
      }
    }	
}
void main()
{
   create_graph();
   BF_traversal();
}

/*
OUTPUT
******
Enter no of vertices:6
Enter the edge 1:0 1
Enter the edge 2:0 3
Enter the edge 3:1 2
Enter the edge 4:3 4
Enter the edge 5:4 2
Enter the edge 6:5 3
Enter the edge 7:-1 -1
Enter start vertex for bfs:0
The graph traversal is:
0  1  3  2  4  
*/