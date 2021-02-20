#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head1,*head2;

void createlist1(int n)
{
     struct node *newNode, *temp;
     int data,j;
     head1 = (struct node*)malloc(sizeof(struct node));
     if(head1==NULL)
     {
         printf("Unable to allocate memory");
     }
     else
     {
         scanf("%d", &data);
         head1 -> data = data;
         head1 -> next = NULL;
         temp = head1;
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

void createlist2(int m)
{
     struct node *newNode, *temp;
     int data,j;
     head2 = (struct node*)malloc(sizeof(struct node));
     if(head2==NULL)
     {
         printf("Unable to allocate memory");
     }
     else
     {
         scanf("%d", &data);
         head2 -> data = data;
         head2 -> next = NULL;
         temp = head2;
         for(j=2;j<=m;j++)
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


struct node *print_dulpicate(struct node *list1,struct node *list2)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *head = temp;
    struct node *new = (struct node*)malloc(sizeof(struct node)); 
    while(list1!=NULL&&list2!=NULL)
    {
        if(list1->data==list2->data)
        {
           // head->next = NULL;
            head -> data = list1->data;
            list1 = list1->next;
            list2 = list2->next;
            head = head->next;
        }

        else if(list2->data < list1->data)
        {
            list1 = list1->next;
        }

        else if(list2->data > list1->data)
        {
           list2 = list2 -> next;
        }
    }
    return head;
}
void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n,m;
       scanf("%d", &n);
       createlist1(n);
       scanf("%d", &m);
       createlist2(m);
       struct node *temp=print_dulpicate(head1,head2);
       print(temp);
       printf("\n");
    }
    return 0;
}