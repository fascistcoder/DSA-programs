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
    struct node *newNode, *temp;
    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("Unabvle to allocate memory");
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

            if(newNode==NULL)
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

void insert_middle(int data, int p)
{
    int j;
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        newnode -> data = data;
        newnode -> next = NULL;
        temp = head;

        for(j=2;j<=p-1;j++)
        {
             temp = temp -> next;
             if(temp == NULL)
             {
                 break;
             }
        }
        if(temp != NULL)
        {
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
        else
        {
            printf("unable to allocate memory");
        }
        
    }
    
}

void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = head;
        while (temp!=NULL)
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
        int n,x,p;
        scanf("%d%d%d", &n,&x,&p);
        createlist(n);
        insert_middle(x,p);
        print();
    }
    return 0;
}