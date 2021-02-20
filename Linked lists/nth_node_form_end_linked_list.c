#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
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
        for(j=2;j<=n;j++)
        {
            new = (struct node*)malloc(sizeof(struct node));
            if(new == NULL)
            {
                printf("Unable to allocate memory");
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

//naive_approach
/*int countnode()
{
    struct node *temp;
    int c=0;
    temp = head;
    while(temp != NULL)
    {
        c++;
        temp = temp -> next;
    }
    return c;
}

int find_node(int x)
{
    struct node *temp;
    int j,k,l;
    k = countnode();
    temp = head;
    for(j=1;j<k-x+1;j++)
    {
        temp = temp -> next;
    }

    return temp -> data;
}*/

//two_pointer algorithm
int find_node(int x)
{
   int c=0;
   struct node *ref=head, *main=head;
   if(head != NULL)
   {
       while (c<x)
       {
           ref = ref -> next;
           c++;
       } 
   }

   while (ref!=NULL)
   {
       /* code */
       main = main -> next;
       ref = ref -> next;
   }

   return main -> data;
   
}

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int n,x,m;
        scanf("%d%d", &n,&x);
        createlist(n);
        /*if(x>n)
        {
            printf("-1\n");
        }

        else
        {*/
            m = find_node(x);
            printf("%d\n",m);
        //}
    }
    return 0;
}