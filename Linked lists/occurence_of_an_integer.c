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

int search(int key)
{
    int c=0;
    struct node *current;
    current = head;
    while (current != NULL)
    {
        if(current -> data == key)
        {
            c++;
        }

        current = current -> next;
    }
    return c;
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n,key;
       scanf("%d%d", &n, &key);

       createlist(n);
       int f = search(key);

       printf("%d\n", f);
    }
    return 0;
}