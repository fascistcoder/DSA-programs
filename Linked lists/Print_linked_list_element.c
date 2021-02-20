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
//iterative method
/*void print()
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
}*/

//recursive method
void print(struct node* temp)
{
    
    if(temp==NULL)
    {
        return;
    }
    printf("%d ", temp->data);  
    print(temp->next);    
}
//print list in reverse order using recursion
void print1(struct node* temp)
{
    if(temp == NULL)
    {
        return;
    }

    print1(temp -> next);
    printf("%d ", temp->data);
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
         print(head);
         printf("\n");
         print1(head);
         printf("\n");
    }
    return 0;
}