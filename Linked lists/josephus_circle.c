#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createlist(int n)
{
     int data,j;
     struct node *temp,*new;
     head = (struct node*)malloc(sizeof(struct node));
     if(head==NULL)
     {
         printf("unable to allocate meory");
     }

     else
     {
         scanf("%d", &data);
         head->data = data;
         head->next=NULL;
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
                 new->data=data;
                 new->next=NULL;
                 temp->next=new;
                 temp=new;
            }
            temp->next=head;
         }
     }
}
void print()
{
   struct node *temp;
   if(head==NULL)
   {
       printf("list is empty");
   }

   else
   {
       temp=head;
       while(temp->next!=head)
       {
           printf("%d ", temp->data);
           temp=temp->next;
       }
       printf("%d ", temp->data);
   }
}
int josephus_Position(int m,int n)
{
   struct node *p;
   int count,j;
   //elminate every m-th plAYER as long as more than one player remaning
   for(count=n;count>1;--count)
   {
       for(j=0;j<m-1;j++)
       {
           p=p->next;
       }
       p->next=p->next->next;
   }
   return p->data;
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n,m;
       scanf("%d%d", &n,&m);
       createlist(n);
       print();
       printf("\n");
       int josephus = josephus_Position(m,n);
       printf("%d\n", josephus);
    }
    return 0;
}