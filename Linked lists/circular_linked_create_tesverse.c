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
   int j,data;
   struct node *temp,*new;
   head=(struct node*)malloc(sizeof(struct node));
   if(head==NULL)
   {
       printf("unable to allocate memory");
   }

   else
   {
       scanf("%d", &data);
       head->data = data;
       head->next = NULL;
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
       }
       temp->next = head;
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
        temp = head;
        while(temp->next!=head)
        {
            printf("%d ", temp-> data);
            temp = temp -> next;
        }
        printf("%d ", temp->data);
    }
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n;
       scanf("%d", &n);
       createlist(n);
       print();
       printf("\n");
    }
    return 0;
}