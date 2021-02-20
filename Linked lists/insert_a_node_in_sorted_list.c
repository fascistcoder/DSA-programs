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

void insert_element_in_sorted_list(int data)
{
    struct node *current=head,*prev,*newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(head==NULL)
    {
        return;
    }

    while(current!=NULL&&current->data < newNode->data)
    {
        prev = current;
        current = current -> next;
    }
    if(current==head)
    {
        newNode -> next = head;
        head = newNode;
    }
    else
    {
      newNode ->next = current;
      prev -> next = newNode;
    }
}
void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty ");
    }

    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
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
        int n,c;
        scanf("%d", &n);
        createlist(n);
        scanf("%d", &c);
        insert_element_in_sorted_list(c);
        print();
        printf("\n");
    }
    return 0;
}