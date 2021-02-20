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
    int data,j;
    struct node *temp, *new;
    head = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
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
            new = (struct node*)malloc(sizeof(struct node));
            if(new==NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);
                new -> data = data;
                new -> next = NULL;
                temp -> next = new;
                temp = temp -> next;
            }
        }
    }
}
int sum_of_nodes(int m)
{
   struct node *temp=head,*current;
   int c=0,sum=0;
   while(temp!=NULL)
   {
       c++;
      temp =  temp->next;
   }
   
   int l = c-m;
   current=head;
   while(l--)
   {
       current = current->next;
   }
   while(current!=NULL)
   {
       sum += current->data;
       current = current->next;
   }

   return sum;
}
int main()
{
   int t,i;
   scanf("%d", &t);
   for(i=0;i<t;i++)
   {
     int n,m;
     scanf("%d", &n);
     createlist(n);
     scanf("%d", &m);
     printf("%d\n",sum_of_nodes(m));
   }
   return 0;
}