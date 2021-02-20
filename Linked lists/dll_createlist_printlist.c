#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* prev;
    struct node* next;
    int data;
};
struct node *head,*last;

void createlist(int n)
{
    int j,data;
    struct node *new;
    
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
        head -> prev = NULL;

        last = head;

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
                new -> prev = last;
                new -> next = NULL;

                last -> next = new;
                last = new;
            }
            
        }
    }
}

void print()
{
    struct node *temp;
    
    if(head==NULL)
    {
        printf("list is empty");
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

void print1()
{
    struct node *temp;

    if(last==NULL)
    {
        printf("list is empty");
    }

    else
    {
        temp = last;

        while (temp != NULL)
        {
            /* code */
            printf("%d ", temp -> data);
             temp = temp -> prev;
        }

    }
    
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int n,choice;
        scanf("%d%d", &n, &choice);
        
        createlist(n);

        if(choice==1)
        {
            print();
            printf("\n");
        }

        else
        {
            print1();
            printf("\n");
        }
        
    }
    return 0;
}