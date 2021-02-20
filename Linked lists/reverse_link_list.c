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
    struct node *temp, *newNode;
    int data,j;
    
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

void reverse(struct node **head)
{
    struct node *current, *prev=NULL, *next;

    current = *head;

    while (current != NULL)
    {
        
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next; 
    }

   *head = prev;
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
       while (temp != NULL)
       {
           /* code */
           printf("%d ", temp -> data);
           temp = temp -> next;
       }
       
   }
   
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for ( i = 0; i < t; i++)
    {
        /* code */
        int n;
        scanf("%d", &n);

        createlist(n);
        reverse(&head);
        print();
        printf("\n");
    }
    return 0;
}