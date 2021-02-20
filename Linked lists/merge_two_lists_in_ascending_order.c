#include <stdio.h>
#include <stdlib.h>

struct node 
{
   int data;
   struct node *next;
};
struct node *head1, *head2;

void createlist1(int n)
{
    int data,j;
    struct node *temp,*new;
    head1 = (struct node*)malloc(sizeof(struct node));
    if(head1==NULL)
    {
        printf("unable to allocate memory");
    }

    else
    {
        scanf("%d", &data);
        head1->data=data;
        head1->next=NULL;

        temp=head1;
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

void createlist2(int m)
{
    int data,j;
    struct node *temp,*new;
    head2 = (struct node*)malloc(sizeof(struct node));
    if(head2==NULL)
    {
        printf("unable to allocate memory");
    }

    else
    {
        scanf("%d", &data);
        head2->data=data;
        head2->next=NULL;

        temp=head2;
        for(j=2;j<=m;j++)
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

struct node *Alternate_merge(struct node *list1, struct node *list2)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    new -> next = NULL;
    temp = new;
    while(list1!=NULL&&list2!=NULL)
    {
        temp -> next = list1;
        temp = temp -> next;
        list1 = list1 -> next;
        temp -> next = list2;
        list2 = list2 -> next;
        temp = temp -> next;
    }

    if(list1!=NULL)
    {
        temp -> next = list1;
    }

    else
    {
        temp -> next = list2;
    }
    temp = new -> next;
    free(new);
    return temp;
}

void print(struct node *temp)
{
   while(temp!=NULL)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
}
void print1()
{
    struct node *temp;
    if(head1==NULL)
    {
        printf("list is empty");
    }

    else
    {
        temp = head1;
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
void print2()
{
    struct node *temp;
    if(head2==NULL)
    {
        printf("list is empty");
    }

    else
    {
        temp = head2;
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int t,i;
    scanf("%d", &t);

    for(i=0;i<t;i++)
    {
        int n,m;
        scanf("%d", &n);
        createlist1(n);
        print1();
        printf("\n");
        scanf("%d", &m);
        createlist2(m);
        print2();
        printf("\n");
        struct node *temp = Alternate_merge(head1,head2);
        print(temp);
        printf("\n");
    }
}