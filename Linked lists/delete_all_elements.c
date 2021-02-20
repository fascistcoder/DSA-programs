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

            if(newNode == NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next =  newNode;
                temp =  temp -> next;
            }
            
        }
    }
    
}

void delete_all()
{
    struct node *del;
    while (head != NULL)
    {
        del = head;
        head = head -> next;
        free(del);
    }
    printf("list is delete successfully\n");
}

void print()
{
    struct node *temp;
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
            temp =  temp -> next;
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
       delete_all();
       print();
       printf("\n");
    }
    return 0;
}