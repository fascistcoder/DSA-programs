//Linked List: Insert a node at beginnig
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
// gloabal variable, can be accessed anywhere
struct Node* head;
void Insert(int x)
{
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}
void Print()
{
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp -> next;
    }
    printf("\n");
}
int main()
{
    head = NULL; //empty list
    printf("how many numbers?\n");
    int n,x,i;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    } 
}