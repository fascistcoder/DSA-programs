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

struct node  *reverse(struct node **head2)
{
    struct node *curr = *head2, *prev = NULL, *next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    *head2 = prev;
    return *head2;
}
int palindrome(struct node *head)
{
    if(head -> next == NULL)
    {
        return 1;
    }
    //middle elemnts by 2 pointer algo
    struct node *fast = head, *slow = head, *prev = NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
       fast = fast -> next -> next;
       prev = slow;
       slow = slow -> next;
    }
    
    struct node *head2;
    if(fast!=NULL)
    {
        slow  = slow->next;
       // prev -> next = NULL;
    }
    head2 = slow;

    //reverse the second half
    struct node *pre = reverse(&head2);

    //compare both elements
    struct node *curr = head;
    while(curr!=NULL&&pre!=NULL)
    {
        if(curr->data != pre -> data)
        {
            return 0;
        }
        curr = curr -> next;
        pre = pre -> next;
    }
    return 1;
}
/*void print(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
    }
}*/

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
      int n;
      scanf("%d", &n);
      createlist(n);
      int f = palindrome(head);
      if(f==0)
      {
          printf("NOT PALINDROME");
      }
      else
      {
          printf("PALINDROME");
      }
      printf("\n");
    }
    return 0;
}