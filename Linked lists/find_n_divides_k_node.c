#include <stdio.h>
#include <stdlib.h>

struct node
{
   struct node *next;
   int data;
};
struct node *head;
void createlist(int n)
{
    struct node *newNode, *temp;
    int data,j;
    
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("unable to allocate memory");
    }

    else
    {
       scanf("%d", &data);
       head -> data = data;
       head -> next = NULL;

       temp = head;
       for(j=2;j<=n;j++)
       {
          newNode = (struct node*)malloc(sizeof(struct node));
          scanf("%d", &data);
          newNode -> data = data;
          newNode -> next = NULL;
          temp -> next = newNode;
          temp = temp -> next;
       }     
    }
}

/*int countnodes()
{
   struct node *temp;
   int c=0;
   temp = head;
   while(temp!=NULL)
   {
      c++;
      temp = temp -> next;
   }
   return c;
}

int modular(int k)
{
   struct node *temp=head;
   int j;
   int total = countnodes();
   int m = total / k;
   if(total%2==0)
   {
      for(j=1;j<m;j++)
     {
       temp = temp -> next;
     }
   }
   else
   {
      for(j=1;j<=m;j++)
     {
      temp = temp -> next;
     }
   }

   return temp -> data;
}*/

int modular(int k)
{
   struct node *temp1=head;
   int j,m,c=0;
   while(temp1!=NULL)
   {
      c++;
      temp1 = temp1 -> next;
   }
   if(c/k!=0)
   {
       m= c/k+1;
   }
   
   struct node *temp= head;
   while(--m)
   {
       
       temp = temp -> next;
   }
   return temp -> data;
}


int main()
{
   int t,i;
   scanf("%d", &t);
   for(i=0;i<t;i++)
   {
     int n,k;
     scanf("%d", &n);
     createlist(n);
     scanf("%d", &k);

     int node = modular(k);
     printf("%d\n", node);
   }
   return 0;
}