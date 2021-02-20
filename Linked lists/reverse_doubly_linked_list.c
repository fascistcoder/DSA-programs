#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node* prev;
    struct node* next;
    int data;
};

struct node *head, *last;

void createlist(int n)
{
   int data,j;
    struct node *new;

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
        head -> prev = NULL;

        last = head;


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
                new -> prev = last;
                new -> next = NULL;

                last -> next = new;
                last = new;
            }
            
        }
    }
}

void reverse_link_list()
{
    struct node *current, *temp;
    current = head;

    while(current != NULL)
    {
        temp = current -> next;
        current -> next = current -> prev;
        current -> prev = temp;
        current = temp;
    }

    temp = head;
    head = last;
    last = temp;

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
       temp  = head;
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
    for(i=0;i<t;i++)
    {
       int n;
       scanf("%d", &n);

       createlist(n);
       print();
       printf("\n");

       reverse_link_list();
       print();
       printf("\n");
    }
    return 0;
}