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
    struct node *temp,*new;
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
            new = (struct  node*)malloc(sizeof(struct node));
            if(new == NULL)
            {
                printf("unable to allocate memory");
            }

            else
            {
                scanf("%d", &data);
                new -> data = data;
                new -> next = NULL;
                temp -> next =  new;
                temp = temp->next;
            }
        }
    }
}

struct node *exchange_even_odd(struct node *head1)
{
    //starting node of list having even and odd values
    struct node *evenliststart=NULL, *oddliststart=NULL;
    //ending node of list having even and odd values
    struct node *evenlistend = NULL, *oddlistend=NULL;
    struct node *temp = head1;
    while(temp!=NULL)
    {
        //int val = temp-> data;
        //if data is even add to even list
       if(temp->data % 2==0)
       {
           if(evenliststart == NULL)
           {
               evenliststart = evenlistend = temp;
           }

           else
           {
               evenlistend -> next = temp;
               evenlistend = temp;
           }
       }
       //if data is odd add to odd lists
       else
       {
           if(oddliststart == NULL)
           {
               oddliststart = oddlistend = temp;
           }

           else
           {
               oddlistend -> next = temp;
               oddlistend = temp;
           }
       }
       //move head pointer to the next
       temp = temp -> next;
    }
    if(evenliststart==NULL||oddliststart==NULL)
    {
        return head1;
    }
    //add odd list after even list
    evenlistend -> next = oddliststart;
    oddlistend -> next = NULL;
    //modify head pointer to starting of even list
    head1 = evenliststart;
    return head1;
}
void print1()
{
   struct node *temp;
   if(head == NULL)
   {
       printf("list is empty");
   }

   else
   {
       temp = head;
       while(temp!=NULL)
       {
           printf("%d ", temp->data);
           temp = temp->next;
       }
   }
}
void print(struct node *temp)
{
   // temp = head;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp -> next;
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
        print1();
        printf("\n");
        struct node *temp = exchange_even_odd(head);
        print(temp);
        printf("\n");
    }
    return 0;
}