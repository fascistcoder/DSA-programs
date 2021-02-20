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
    struct node *newNode, *temp;
    int data,j;
    
    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
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
                  temp -> next= newNode;
                  temp = temp -> next;
              }        
        }
    } 
}

void insert_beg(int data)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        newNode -> data = data;
        newNode -> next = head;
        head = newNode;
    }
    
}
int count()
{
    int c=0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp -> next;
    }
    return c;
}

void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty ");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
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
        int n,x;
        scanf("%d", &n);
        createlist(n);
        print();
        printf("\n");
        scanf("%d", &x);
        insert_beg(x);
        print();
        printf("\n");
        int total = count();
        printf("%d\n", total);
    }
    return 0;
}