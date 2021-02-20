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
     struct node *newNode, *temp;
     int data,j;
     head = (struct node*)malloc(sizeof(struct node));
     if(head==NULL)
     {
         printf("Unable to allocate memory");
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
             if(newNode == NULL)
             {
                 printf("unable to allocate memory");
             }
             else
             {
                 scanf("%d", &data);
                 newNode -> data = data;
                 newNode -> next = NULL;
                 temp -> next = newNode;
                 temp = temp -> next;
             }
             
         }
     }
}

struct node *split_list_alternative(struct node *head)
{

}

void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
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
      struct node *temp = split_list_alternative(head);
      print();
      printf("\n");
    }
    return 0;
}