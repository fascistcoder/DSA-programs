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
    struct node *new, *temp;
    int data,j;

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

        for (j=2; j<=n; j++)
        {
            new = (struct node*)malloc(sizeof(struct node));

            if(new ==NULL)
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

int modular_node(int key)
{
   struct node *modularnode = head;
   int c=1,t=-1;
   while(modularnode!=NULL)
   {
       //find index which is divisible from end
       if(c%key==0)
       {
           //data on the index
           t = modularnode->data;
       }
       modularnode=modularnode->next;
       c++;
   }
   return t;
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int n,key;
        scanf("%d", &n); 
        createlist(n);
        scanf("%d", &key);
        
       //modular_node(key);

        printf("%d\n", modular_node(key));

    }
    return 0;
}