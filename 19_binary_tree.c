/*
                          Program No:19
                           BINARY TREE
                           ************
*/
#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *lchild,*rchild;
};
struct Tree * root;
struct Tree *create()
{
	struct Tree *ptr;
	int item;
	printf("Enter the data(-1 for null):");
	scanf("%d",&item);
	if(item==-1)
	return NULL;
	ptr=malloc(sizeof(struct Tree));
	ptr->data=item;
	printf("Enter the left child of %d:\n",ptr->data);
	ptr->lchild=create();
	printf("Enter the right child of %d:\n",ptr->data);
	ptr->rchild=create();
	return ptr;
}
void preorder(struct Tree *ptr2)
{
	if(ptr2!=NULL)
	{
		printf("%d   ",ptr2->data);
		preorder(ptr2->lchild);
		preorder(ptr2->rchild);
	}
}
void inorder(struct Tree *ptr2)
{
	if(ptr2!=NULL)
	{
		inorder(ptr2->lchild);
		printf("%d   ",ptr2->data);
		inorder(ptr2->rchild);
	}
}
void postorder(struct Tree *ptr2)
{
	if(ptr2!=NULL)
	{
		postorder(ptr2->lchild);
		postorder(ptr2->rchild);
		printf("%d   ",ptr2->data);
	}
}
void main()
{
	int choice;
	while(choice!=5)
	{
		printf("\nOPERATIONS\n1:Create Tree\n2:Preorder\n3:Inorder\n4:Postorder\n5:Exit\nENTÉR YOUR CHOICE:");
		scanf("%d",&choice);
		switch(choice)
		{
	            case 1:root=create();
			   break;
		    case 2:printf("\nPREORDER:");
		           preorder(root);
		           break;
		    case 3:printf("\nINORDER:");
		           inorder(root);
		           break;
		    case 4:printf("\nPOSTORDER:");
		           postorder(root);
		           break;
		    case 5:exit(0);	
		           break;
		    default:printf("ENTER VALID CASE\n");
		}
	}
}
/*
OUTPUT
******
OPERATIONS
1:Create Tree
2:Preorder
3:Inorder
4:Postorder
5:Exit
ENTÉR YOUR CHOICE:1
Enter the data(-1 for null):1
Enter the left child of 1:
Enter the data(-1 for null):5
Enter the left child of 5:
Enter the data(-1 for null):2
Enter the left child of 2:
Enter the data(-1 for null):7
Enter the left child of 7:
Enter the data(-1 for null):-1
Enter the right child of 7:
Enter the data(-1 for null):-1
Enter the right child of 2:
Enter the data(-1 for null):-1
Enter the right child of 5:
Enter the data(-1 for null):-1
Enter the right child of 1:
Enter the data(-1 for null):3
Enter the left child of 3:
Enter the data(-1 for null):-1
Enter the right child of 3:
Enter the data(-1 for null):4
Enter the left child of 4:
Enter the data(-1 for null):6
Enter the left child of 6:
Enter the data(-1 for null):-1
Enter the right child of 6:
Enter the data(-1 for null):-1
Enter the right child of 4:
Enter the data(-1 for null):8
Enter the left child of 8:
Enter the data(-1 for null):9
Enter the left child of 9:
Enter the data(-1 for null):-1
Enter the right child of 9:
Enter the data(-1 for null):-1
Enter the right child of 8:
Enter the data(-1 for null):-1

OPERATIONS
1:Create Tree
2:Preorder
3:Inorder
4:Postorder
5:Exit
ENTÉR YOUR CHOICE:2

PREORDER:1   5   2   7   3   4   6   8   9   
OPERATIONS
1:Create Tree
2:Preorder
3:Inorder
4:Postorder
5:Exit
ENTÉR YOUR CHOICE:3

INORDER:7   2   5   1   3   6   4   9   8   
OPERATIONS
1:Create Tree
2:Preorder
3:Inorder
4:Postorder
5:Exit
ENTÉR YOUR CHOICE:4

POSTORDER:7   2   5   6   9   8   4   3   1   
OPERATIONS
1:Create Tree
2:Preorder
3:Inorder
4:Postorder
5:Exit
ENTÉR YOUR CHOICE:5
*/
