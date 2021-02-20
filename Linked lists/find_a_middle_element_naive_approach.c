#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head;

void creatlist(int n)
{
    int data,j;
    struct node *new, *temp;

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
            if(new==NULL)
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

int count_nodes()
{
    struct node *temp;
    int c=0;
    temp = head;
    while(temp!=NULL)
    {
        c++;
        temp = temp -> next;
    }

    return c;
}

int middle_element()
{
    struct node *temp;
    int total,j;
    total = count_nodes();
    temp = head;
    for(j=0;j<total/2;j++)
    {
       temp = temp -> next;
    }

    return temp -> data;
    
}


int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int n,m;
        scanf("%d", &n);
        creatlist(n);
        m = middle_element();
        //m = count_nodes();
        printf("%d\n", m);
    }
    return 0;
}