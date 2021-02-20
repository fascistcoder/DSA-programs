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

struct node *remove_kth_node(struct node *head, int k)
{
    int c=1;
    struct node *temp = head,*prev;
    if(k==0||head==NULL)
    {
        return head;
    }  

    else if(k==1)
    {
        return NULL;
    }

    while(temp!=NULL)
    {
        if(c%k==0)
        {
            prev -> next = temp->next;
        }

        prev = temp;
        temp = temp -> next;
        c++;
    }
    return head;
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
       int n,k;
       scanf("%d", &n);
       createlist(n);
       scanf("%d", &k);
       struct node *temp = remove_kth_node(head,k);
       print(temp);
       printf("\n");
    }
    return 0;
}