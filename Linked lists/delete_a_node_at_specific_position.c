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
void delete_element(int x)
{
    struct node *del,*prev;
    del = head;
    int j;
    if(x==1)
    {
        head = del -> next;
        free(del);
    }

    else
    {
        for(j=0;j<x-2;j++)
        {
           del = del -> next;
        }
        prev = del -> next;
        del -> next = prev -> next;
        free(prev);
    }

}
void print()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("unable to allocate memory");
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
       delete_element(x);
       print(); 
       printf("\n"); 
    }
    return 0;
}