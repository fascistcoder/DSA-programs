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
    struct node *newNode, *temp;
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
 void reverse(struct node **head2)
 {
     struct node *curr = *head2, *prev = NULL, *next;
     while(curr!=NULL)
     {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
     } 
     *head2 = prev; 
 }
struct node *reorder_list(struct node *head)
{
    if(head==NULL||head->next==NULL)
    {
        return NULL;
    }
    //middle element
    struct node *fast=head,*slow=head, *prev=NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
    }
    struct node *head2;
    if(fast==NULL) // even no of nodes
    {
      head2 = slow;
      prev -> next = NULL;
    }

    else  //odd no of nodes
    {
        head2 = slow -> next;
        slow -> next = NULL;
    }

    //reverse the second half
    reverse(&head2);

    //merge two lists
    struct node *curr = head,*next;
    while(curr!=NULL && curr->next!=NULL)
    {
       next = curr->next;
       curr -> next = head2;
       head2= head2 -> next;
       curr -> next -> next = next;
       curr = curr -> next -> next; 
    }
    curr -> next = head2;
    return head;
}

void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
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
        struct node *temp = reorder_list(head);
        print(temp);
        printf("\n");
    }
    return 0;
}