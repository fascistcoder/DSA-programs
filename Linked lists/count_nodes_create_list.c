#include <stdio.h>
#include <stdlib.h>
//structure of a node
struct  node
{
    //data
    int data;
    //address
    struct  node *next;
};
//global variable acces anywhere
struct node *head;

void createlist(int n)
{
    //address
    struct node *newNode, *temp;
    int data, j;
    //dynamic allocated memory
    head = (struct node*)malloc(sizeof(struct node));
    //unable to allocate memory
    if(head==NULL)
    {
        printf("unable to allocate memory");
    }
    else
    {
        //read the data of node from the browser
        scanf("%d", &data);
        //link data field with data
        head -> data = data;
        //link address field to NULL
        head -> next = NULL;
        temp = head;
        //create n nodes and adds to linked list
        for(j=2;j<=n;j++)
        {
            //dynamic allocate memory to newNode
            newNode = (struct node*)malloc(sizeof(struct node));
            //if memory is not allocated for newNode
            if(newNode == NULL)
            {
                printf("Unable to allocate memory");
            }
            //otherwise
            else
            {
                scanf("%d", &data);
                //link data to newNode
                newNode -> data = data;
                //link address to newNode
                newNode -> next = NULL;
                //link previous node i.e temp
                temp -> next = newNode;
                temp = temp -> next;
            }
            
        }
    }
    
}
int countnode()
{
    int c=0;
    struct node *temp;
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
    //input for testcases
    scanf("%d", &t);
    //loop for testcases
    for(i=0;i<t;i++)
    {
        int n,total;
        //no of elements in list
        scanf("%d", &n);
        //function for list creation
        createlist(n);
        //function to count no of elements in a single linked list
        total = countnode();
        printf("%d\n", total);
    }
    return 0;
}

