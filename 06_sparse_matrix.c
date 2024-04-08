/*
                          Program No:6
                          SPARSE MATRIX
                          *************
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 101
typedef struct
{
    int col,row,value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];
int q=1,w=1;
void convert_sparse(int row1,int col1,int x[100][100],int row2,int col2,int y[100][100])
{
    int i,j;
    a[0].row=row1;
    a[0].col=col1;
    a[0].value=0;
    b[0].row=row2;
    b[0].col=col2;
    b[0].value=0;
    for(i=0;i<row1;i++)
      {
        for(j=0;j<col1;j++)
        {
            if(x[i][j]!=0)
            {
                a[q].row=i;
                a[q].col=j;
                a[q++].value=x[i][j];
                a[0].value++;
            }
         }
      }
     for(i=0;i<row2;i++)
      {
        for(j=0;j<col2;j++)
         {
            if(y[i][j]!=0)
            {
                b[w].row=i;
                b[w].col=j;
                b[w++].value=y[i][j];
                b[0].value++;
            }
        }
     }
}

void display(term d[])
{
    int i;
    printf("\nRow\tColumn\tValue\n");
    for(i=0;i<=d[0].value;i++)
        {
            printf("%d\t%d\t%d\n",d[i].row,d[i].col,d[i].value);
        }
}


void transpose(term a[])
{
    term t[MAX_TERMS];
    int n,i,j,currentt;
    n=a[0].value;
    t[0].row=a[0].col;
    t[0].col=a[0].row;
    t[0].value=n;
    if(n>0)
    {
        currentt=1;
        for(i=0;i<a[0].col;i++)
            for(j=1;j<=n;j++)
                if(a[j].col==i)
                {
                    t[currentt].row=a[j].col;
                    t[currentt].col=a[j].row;
                    t[currentt].value=a[j].value;
                    currentt++;
                }
    }
    printf("Sparse Matrix:\n");
    display(a);
    printf("Transpose of the Matrix:\n");
    display(t);
}

void add()
{
    term r[MAX_TERMS];
    r[0].row=a[0].row;
    r[0].col=a[0].col;
    int i=1,j=1,k=1;
    int n1=a[0].value,n2=b[0].value;
    if(a[0].row==b[0].row && a[0].col==b[0].col)
    {
        while(i<=n1 && j<=n2)
        {
            if(a[i].row==b[j].row && a[i].col==b[j].col)
            {
                r[k].row=a[i].row;
                r[k].col=a[i].col;
                r[k].value=a[i].value+b[j].value;
                i++;
                j++;
                k++;  
            }
            else if(a[i].row==b[j].row && a[i].col<b[j].col)
            {
                r[k].row=a[i].row;
                r[k].col=a[i].col;
                r[k].value=a[i].value;
                i++;
                k++; 
            }
            else if(a[i].row==b[j].row && a[i].col>b[j].col)
            {
                r[k].row=b[j].row;
                r[k].col=b[j].col;
                r[k].value=b[j].value;
                j++;
                k++;  
            }
            else if(a[i].row<b[j].row)
            {
                r[k].row=a[i].row;
                r[k].col=a[i].col;
                r[k].value=a[i].value;
                i++;
                k++; 
            }
            else if(a[i].row>b[j].row)
            {
                r[k].row=b[j].row;
                r[k].col=b[j].col;
                r[k].value=b[j].value;
                j++;
                k++;  
            }
        }
        for(i=i;i<=n1;i++)
        {
            r[k].row=a[i].row;
            r[k].col=a[i].col;
            r[k].value=a[i].value;
            k++;   
        }
        for(j=j;j<=n2;j++)
        {
            r[k].row=b[j].row;
            r[k].col=b[j].col;
            r[k].value=b[j].value;
            k++;   
        }
        r[0].value=k-1;
        display(a);
        printf("\n+\n");
        display(b);
        printf("\n=\n");
        display(r);
    }
    else
        printf("\nMatrix cannot be added\n");
}

void main()
{
    int z,m,n,p,q,i,j,t=0,x[100][100],y[100][100];
    printf("Enter the number of rows and columns in Matrix 1:");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("Enter the Matrix elements:\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            printf("Element at %dx%d: ",i+1,j+1);
            scanf("%d",&x[i][j]);
        }   
    printf("\nEnter the number of rows and columns in Matrix 2:");
    scanf("%d",&p);
    scanf("%d",&q);
    printf("Enter the Matrix elements:\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
        {
            printf("Element at %dx%d: ",i+1,j+1);
            scanf("%d",&y[i][j]);
        }
    convert_sparse(m,n,x,p,q,y);
        while(z!=4)
       { 
    printf("\nSparse Matrix Functions\n_______________________\n\n");
    {
        printf("1.Transpose of a Matrix\n2.Adding 2 Sparse Matrix\n3.Display a Sparse Matrix\n4.Exit\nEnter your choice:");
        scanf("%d",&z);
       
        switch(z)
        {
            case 1:printf("Which Matrix do you want to find transpose for? (1 or 2):");
                scanf("%d",&t);
                if(t==1)
                    transpose(a);
                else if(t==2)
                    transpose(b);
                else
                    printf("Matrix Does'nt Exist");
                break;
            case 2:printf("Adding Matrix 1 and Matrix 2...");
                add();
                break;
            case 3:printf("Which Matrix do you want to display? (1 or 2):");
                scanf("%d",&t);
                if(t==1)
                    display(a);
                else if(t==2)
                    display(b);
                else
                    printf("Matrix Does'nt Exist");
                break;
                
            case 4:exit(0);
                break;
            
            default:printf("*** INVALID CASE ***\n");
        }
       }
    }
}
/*
OUTPUT
******
Enter the number of rows and columns in Matrix 1:3 3
Enter the Matrix elements:
Element at 1x1: 1
Element at 1x2: 0
Element at 1x3: 0
Element at 2x1: 0
Element at 2x2: 2
Element at 2x3: 0
Element at 3x1: 0
Element at 3x2: 0
Element at 3x3: 3

Enter the number of rows and columns in Matrix 2:3 3
Enter the Matrix elements:
Element at 1x1: 0
Element at 1x2: 0
Element at 1x3: 9
Element at 2x1: 0
Element at 2x2: 8
Element at 2x3: 0
Element at 3x1: 7
Element at 3x2: 0
Element at 3x3: 0

Sparse Matrix Functions
_______________________

1.Transpose of a Matrix
2.Adding 2 Sparse Matrix
3.Display a Sparse Matrix
4.Exit
Enter your choice:1
Which Matrix do you want to find transpose for? (1 or 2):2
Sparse Matrix:

Row     Column  Value
3       3       3
0       2       9
1       1       8
2       0       7
Transpose of the Matrix:

Row     Column  Value
3       3       3
0       2       7
1       1       8
2       0       9

Sparse Matrix Functions
_______________________

1.Transpose of a Matrix
2.Adding 2 Sparse Matrix
3.Display a Sparse Matrix
4.Exit
Enter your choice:2
Adding Matrix 1 and Matrix 2...
Row     Column  Value
3       3       3
0       0       1
1       1       2
2       2       3

+

Row     Column  Value
3       3       3
0       2       9
1       1       8
2       0       7

=

Row     Column  Value
3       3       5
0       0       1
0       2       9
1       1       10
2       0       7
2       2       3

Sparse Matrix Functions
_______________________

1.Transpose of a Matrix
2.Adding 2 Sparse Matrix
3.Display a Sparse Matrix
4.Exit
Enter your choice:4
*/
