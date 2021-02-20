#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    struct node *next;
    int data;
};

struct node *head;

void creatlist(int n)
{
    int data,j;
    struct node *new, *temp;

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

void reverse(struct node *second_half)
{
   struct node *prev=NULL, *current = second_half, *next;
   while(second_half!=NULL)
   {
       next = current->next;
       current->next = prev;
       prev = current;
       current = next;
   }
   second_half=prev;
}
int compare(struct node *first_half, struct node *second_half)
{
    struct node *head1 = first_half, *head2 = second_half;
    if(head1==NULL&&head2==NULL)
    {
        return 1;
    }
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data==head2->data)
        {
             head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return 0;
    }
    return 1;
}
int palidrone()
{
    struct node *fast = head, *slow = head, *prev_node_slow=head;
    //using two pointer algorithm find middle of the list
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast -> next -> next;
        prev_node_slow = slow;
        slow = slow -> next;
    }
    // if list is odd we have to move pointer
    if(fast!=NULL)
    {
        slow = slow -> next;
    }

    //store the address to make new head of second list
    struct node *second_half = slow;
    struct node *first_half = head;
    prev_node_slow -> next = NULL;
    reverse(second_half);
    int r = compare(first_half,second_half);
    return r;
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n;
       scanf("%d", &n);
       creatlist(n);
       int m =palidrone();
       printf("%d\n", m);
    }
    return 0;
}