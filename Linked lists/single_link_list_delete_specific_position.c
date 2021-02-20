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

     if (head == NULL)
     {
         /* code */
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
             if(new == NULL)
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

void delete_specific_position(int x)
{
    struct node *del, *prev;
    del = head;
    int j;
    if(x==1)
    {
        head = del -> next;
        free(del);
    }
    
    else
    {
        for(j=0;j<x-2;j++)
        {
            del = del -> next;
        }

        prev = del -> next;
        del -> next = prev -> next;
        free(prev); 
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
        int n, x;
        scanf("%d%d", &n, &x);

        createlist(n);
        delete_specific_position(x);
        print();
        printf("\n");
    }
    return 0;
}