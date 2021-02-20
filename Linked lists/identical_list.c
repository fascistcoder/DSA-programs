#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
struct node* head1;
void createlist(int n)
{
    struct node *newNode, *temp;
    int data,j;

    head =  (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
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
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next = newNode;
                temp = temp -> next;
            }
            
        }
    }
    
}
void createlist1(int n)
{
    struct node *newNode, *temp;
    int data,j;

    head1 =  (struct node*)malloc(sizeof(struct node));

    if(head1==NULL)
    {
        printf("Unable to allocate memory");
    }
    else
    {
        scanf("%d", &data);
        head1 -> data = data;
        head1 -> next = NULL;
        temp = head1;
        for(j=2;j<=n;j++)
        {
            newNode = (struct node*)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next = newNode;
                temp = temp -> next;
            }
            
        }
    }
    
}

bool identical_list()
{
    struct node *current, *current1;
    current = head;
    current1 = head1;

    while(current!=NULL && current1!=NULL)
    {
        if(current -> data != current1 -> data)
        {
            return 0;
        }
        current = current -> next;
        current1 = current1 -> next;
    }
    return 1;
}

/*bool identical_list()
{
    struct node *current,*current1;
    current = head;
    current1 = head1;
    
    while(1)
    {
        if(current == NULL && current1 == NULL)
        {
           return 1;
        }
        if(current == NULL && current1 != NULL)
        {
           return 0;
        }
        if(current != NULL && current1 == NULL)
        {
           return 0;
        }
        if(current -> data != current1 -> data)
        {
           return 0;
        }
        current = current -> next;
        current1 = current1 -> next;

    }
}*/

int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        createlist(a);
        createlist1(b);

        if(identical_list()==1)
        {
            printf("Identical list\n");
        }
       
        else
        {
            printf("Non-Identical List\n");
        }
    }

    return 0;
}


