#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head;

void createlist(int n)
{
    struct node *newNode,*temp;
    int data;
    head = (struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("unable to aloocate memory");
    }

    else
    {
        scanf("%d", &data);
        head -> data = data;
        head -> next = NULL;
        
        temp = head;
        for(int j=2 ;j<=n;j++)
        {
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("umnable to allocate memory");
            }

            else
            {
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next=newNode;
                temp = temp -> next;
            }
        }
    }
}
void reverse(struct node **second_half)
{
    struct node *prev=NULL, *current = *second_half, *next;
    while(second_half!=NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    *second_half = prev;
}
int isPalindrome()
{
    struct node *fast=head, *slow=head, *prev_slow_ptr=head, *midNode=NULL;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        prev_slow_ptr = slow;
        slow = slow ->next;
    }

    if(fast!=NULL)
    {
        midNode = slow;
        slow = slow->next;
    }

    struct node *second_half = slow;
    prev_slow_ptr -> next = NULL;
    reverse(&second_half);
    /*if(midNode!=NULL)
    {
        prev_slow_ptr->next=midNode;
        midNode->next=second_half;
    }
    else
    {
        prev_slow_ptr->next=second_half;
    }*/
    int f;
    while(head!=NULL&&second_half!=NULL)
    {
        if(head->data!=second_half->data)
        {
            return 0;
            
        }
        head = head -> next;
        second_half = second_half->next;
    }
    return 1;}
  
    /*reverse(second_half);
    if(midNode!=NULL)
    {
        prev_slow_ptr ->next = midNode;
        midNode->next = second_half;
    }
    else
    {
        prev_slow_ptr->next= second_half;
    }
      if(f==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}*/
void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("laist is empty");
    }

    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp ->next;
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
       print();
       printf("\n");
       int res =isPalindrome();
       // print();
       //printf("\n");
        printf("%d\n", res);
       if(res==1)
       {
           printf("YES\n");
       }
       else
       {
           printf("NO\n");
       }
    }
    return 0;
}