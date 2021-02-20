#include <stdio.h>
#include <stdlib.h>
//basic structure of a node
struct node
{
    struct node* prev;
    struct node* next;
    int data;
};

struct node *head, *last;

void createlist(int n)
{
    int data,j;
    struct node *new;
    
    head = (struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        printf("unable to allocate memeory");
    }

    else
    {
        //create a link for the head node
        scanf("%d", &data);
        head -> data = data; //link for data
        head -> next = NULL; 
        head -> prev = NULL;
        
        //intialize last address
        last = head;
        
        //create a link rest of the n-1 nodes
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
                new -> data = data; //link the data part
                new -> prev = last; //link newnode with previous node
                new -> next = NULL; //link newnode with next node

                last -> next = new; //link previous node with newnode
                last = new; //make newnode as last/prvious 
            }
            
        }
    }
}

void insert_beg(int data)
{
   struct node *new;
   new = (struct node*)malloc(sizeof(struct node));
   if(head==NULL)
   {
       printf("unable to add");
   }
   else
   {
       /* code */
       new -> data = data; //link the data part
       new -> next = head; //point to next node with is current
       new -> prev = NULL; //previous node of first node is NULL
       //link previous address feild of head with newnode
       head -> prev = new;
       //make new node as head node
       head = new;
   }
   
}

void insert_end(int data)
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    if(last == NULL)
    {
        printf("unable to add");
    }

    else
    {
        /* code */
        new -> data = data;
        new -> next = NULL;
        new -> prev = last;
        last -> next = new;
        new = last;
    }
    
}

void insert_specific_position(int data,int pos)
{
    int j;
    struct node *new, *temp;

    if(head == NULL)
    {
        printf("unable to add");
    }

    else
    {
        new = (struct node*)malloc(sizeof(struct node));

        temp = head;

        for(j=0;j<pos-1;j++)
        {
             temp = temp -> next;
        }
        
        new -> data = data;
        new -> next = temp -> next;
        temp -> next -> prev = new;
        temp -> next = new;
        new -> prev = temp; 
    }
}

void print()
{
    struct node *temp;
    
    if(head==NULL)
    {
        printf("list is empty");
    }

    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
    }
    
}

int main()
{
    int t,i;
    //input for testcases
    scanf("%d", &t);
    //loop for testacases
    for(i=0;i<t;i++)
    {
        int n,x,choose,pos;
        //input for how many nodes we wanted to create
        scanf("%d", &n);
        //function to create double linked lists
        createlist(n);
        //fuction to call print fuction
        print();
        printf("\n");
        //choices to choose which we want tot implement 
        scanf("%d", &choose);
        if(choose==1)
        {
            scanf("%d", &x);
            //fuction for inserting at beg
            insert_beg(x);
        }

        else if(choose==2)
        {
            scanf("%d", &x);
            //fuction for inserting at the end
            insert_end(x);
        }
        
        else
        {
            scanf("%d%d", &x,&pos);
            //fuction to call at specific position
            insert_specific_position(x,pos);
        }
        //again call print fuction
        print();
        printf("\n");
    }
      return 0;
}