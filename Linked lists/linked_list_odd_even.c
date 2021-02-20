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
int count()
{
    int c=0;
    struct node* temp;
    temp = head;
    while(temp != NULL)
    {
        c++;
        temp = temp -> next; 
    }
    return c;
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n;
       scanf("%d", &n);
       
       int total;
       createlist(n);
       total = count(n);
       if(total%2==0)
       {
           printf("Even\n");
       }
       else
       {
           printf("Odd\n");
       }
       
    }
    return 0;
}