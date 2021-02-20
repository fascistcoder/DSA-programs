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
    int data,j;
    struct node *newNode, *temp;
    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("Unabvle to allocate memory");
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

            if(newNode==NULL)
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

void insert_element(int x)
{
    struct node *fast=head, *slow=head, *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    /*if(head-> next == NULL)
    {
        newNode -> data = x;
        newNode -> next = head;
        head = newNode;
    }*/
    while(fast->next!=NULL && fast->next->next!= NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    newNode -> data = x;
    newNode -> next = slow -> next;
    slow -> next = newNode;
    //return head;
}
void print()
{
    struct  node *temp;

    if(head == NULL)
    {
        printf("list is empty");
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
        scanf("%d%d", &n,&x);
        createlist(n);
        insert_element(x);
        print();
    }
    return 0;
}