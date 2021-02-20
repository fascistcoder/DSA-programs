#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node *head;

void createlist(int n)
{
    int data,j;
    struct node *new, *temp;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
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
            new = (struct node*)malloc(sizeof(struct node));

            if(new == NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);

                new -> data  = data;
                new -> next = NULL;
                temp -> next = new;
                temp = temp -> next;
            }
            
        }
    }
    
}
void reverse_pairing()
{
      struct node *current = head;

      while(current!=NULL&&current->next!=NULL)
      {
          int temp;
          temp = current -> data;
          current -> data = current -> next -> data;
          current -> next-> data = temp;
          current = current -> next -> next;
      }
      /* struct node *cur=head;
      while(cur!=NULL && cur->next!=NULL)
      {
         int temp=cur->data;
         cur->data=cur->next->data;
         cur->next->data=temp;
         cur=cur->next->next;
     }*/

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
        while(temp!=NULL)
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
       int n;
       scanf("%d", &n);
       createlist(n);
       reverse_pairing();
       print();
       printf("\n");
    }
    return 0;
}