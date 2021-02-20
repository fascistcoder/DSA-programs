#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head;
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
void insert(struct node** headref, int x)
{
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        newNode -> data = x;
        newNode -> next = *headref;
        *headref = newNode;

    }
    
}
void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("LIST IS EMPTY");
    }
    else
    {
       temp = head;
       while(temp != NULL)
       {
        printf("%d ", temp -> data);
        temp = temp -> next;
       }
    } 
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
         int n,x;
         scanf("%d", &n);
         createlist(n);
         scanf("%d", &x);
         insert(&head,x);
         print();
         printf("\n");
    }
    return 0;
}