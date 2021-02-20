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

void delete_beg()
{
   struct node *temp;

   temp = head;

   head = head -> next;

   if(temp != NULL)
   {
       head -> prev = NULL;
       free(temp);
   }
}

void delete_end()
{
    struct node *temp;

    temp = last;

    last  = last -> prev;

    if(temp!=NULL)
    {
        last -> next = NULL;
        free(temp);
    }
}

void delete_specific_pos(int pos)
{
    struct node *temp;
    int j;
    temp = head;

    if(pos==1)
    {
        delete_beg();
    }

    else
    {
        /* code */
        for(j=0;j<pos-1&&temp!=NULL;j++)
        {
              temp = temp -> next;
        }

        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;

        free(temp);
    }
    

}

void print()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("unable to allocate memory");
    }

    else
    {
        /* code */
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
        int n,choose,pos;
        scanf("%d", &n);

        createlist(n);
        print();
        printf("\n");
        scanf("%d", &choose);

        if(choose==1)
        {
            delete_beg();
        }

        else if(choose==2)
        {
            delete_end();
        }

        else
        {
            scanf("%d", &pos);
            delete_specific_pos(pos);
        }
        print(); 
        printf("\n");      
 
    }
    return 0;
}