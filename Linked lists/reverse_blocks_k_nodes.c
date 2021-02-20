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
    struct node *temp, *newNode;
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
                temp -> next = newNode;
                temp = temp -> next;
            }
            
        }
    }   
}

struct node *GetKplusonethNode(int k, struct node *head)
{
    struct node *kth=head;
    int j=0;
    if(!head)
    {
        return head;
    }
    for(j=0; kth&&j<k; j++)
    {
        kth = kth -> next;
    }
    if(j==k&&kth!=NULL)
    {
        return kth;
    }
    return head -> next;
}

int HasKnodes(struct node *head, int k)
{
    int j=0;
    for(j=0;head&&(j<k);j++)
    {
        head = head->next;
    }
    if(j==k)
    {
        return 1;
    }
    return 0;
}
void ReverseBlocknodesinlinkedlist(struct node *head, int k)
{
    struct node *current=head, *temp, *next, *newHead;
    int j;
    if(k==0||k==1)
    {
       // return head;
    }
    if(HasKnodes(current,k-1))
    {
        newHead = GetKplusonethNode(k-1, current);
    }

    else
    {
        newHead = head;
        while(current&&HasKnodes(current,k))
        {
            temp = GetKplusonethNode(k,current);
            j=0;
            while(j<k)
            {
                next = current->next;
                current->next=temp;
                temp=current;
                current=next;
                j++;
            }
        }
      //return newHead;  
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
        while(temp != NULL)
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
        int n,k;
        scanf("%d", &n);
        createlist(n);
        scanf("%d", &k);
        ReverseBlocknodesinlinkedlist(head,k);
        print();
        printf("\n");
    }
    return 0;
}