#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node
{
    int data;
    struct node *npx;
};


struct node *XOR(struct node *a, struct node *b)
{
    return (struct node*)((uintptr_t)(a) ^ (uintptr_t)(b));
};

struct node *insert(struct node *head, int data)
{
    //create a new node to be inserted
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    //link to the data
    newNode -> data = data;
    //link to address
    newNode -> npx = XOR(NULL,head);

    if(head!=NULL)
    {
        //get address of next node
        struct node *nextNode = XOR(NULL,head->npx);
        
        //store the XOR of newNode and nextNode 
        head->npx = XOR(newNode,nextNode);
    }
    //make the newNode as head
    head = newNode;
}

void printlist(struct node *head)
{
    struct node *current=head, *prev = NULL, *next;
    while(current!=NULL)
    {
        printf("%d ", current->data);
        next = XOR(prev,current->npx);
        prev = current;
        current = next;
    }

    printf("\n");
    current = prev;
    prev = NULL;
    while(current!=NULL)
    {
        printf("%d ", current->data);
        next = XOR(prev,current->npx);
        prev = current;
        current = next;
    }
}
int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
     struct node *head=NULL;
      int n,data;
      scanf("%d", &n);
      while(n--)
      {
          scanf("%d", &data);
          head = insert(head,data);
      }
      printlist(head);
      printf("\n");
    }

    return (0);
}