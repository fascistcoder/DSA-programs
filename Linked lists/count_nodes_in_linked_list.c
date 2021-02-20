#include <stdio.h>
#include <stdlib.h>

struct slinklist 
{
    int data;
    struct slinklist *next;
};
typedef struct slinklist Node;
Node *head = NULL;
Node* getNode()
{
     Node *newNode;
     newNode = (Node*)malloc(sizeof(Node));
     printf("\n eneter data: ");
     scanf("%d", &newNode -> data);
     //printf("%d ", newNode -> data);
     newNode -> next = NULL;
     return newNode;
} ;
int countNode(Node *ptr)
{
    int c=0;
    while(ptr != NULL)
    {
        c++;
        ptr = ptr -> next; 
    }
    return (c);
}
void createlist(int n)
{
    int i;
    Node *newNode;
    Node *temp;
    for(i=0; i<n; i++)
    {
        newNode = getNode();
        if(head==NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while(temp -> next!= NULL)
            {
                temp = temp -> next;
               // temp -> next = newNode;
            }
            temp -> next = newNode;
        }
        
    }
}
int main()
{
    int n;
    if(head == NULL)
    {
        printf("\n no of nodes you want to create: ");
        scanf("%d", &n);
        createlist(n);
        printf("\n list created: ");
    }
    else
    {
        printf("\n list is already created");
    }
    printf("\n no of nodes: %d", countNode(head));
    return 0;
}