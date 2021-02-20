#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node
{
    int data;
    struct node* next;
};

struct node* head;

void createlist(int n)
{
    int data,j;
    struct node *new, *temp;

    head = (struct node*)malloc(sizeof(struct node));

    if(head == NULL)
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
            new = (struct node*)malloc(sizeof(struct node));

            if(new == NULL)
            {
                printf("unable to allocate memory");
            }
            else
            {
                scanf("%d", &data);

                new -> data  = data;
                new -> next = NULL;
                temp -> next = new;
                temp = temp -> next;
            }
            
        }
    }
    
}
int search_index(struct node *head,int key)
{
    int c=1;
    struct node *current;
    current = head;
    while (current != NULL)
    {
        if(c==key)
        {
            return current -> data;
        }
        c++;
        current = current -> next;
    }
    return -1;
}
/*int search_index(struct node *head,int key)
{
    struct node *current,*current1;
    int j,c=0;
    current = head;
    while (current != NULL)
    {
        
        c++;
        current = current -> next;
    }

    if(key>c)
    {
        return -1;
    }
    else
    {
        current1 = head;
        for(j=1;j<key;j++)
        {
          current1 = current1 -> next;
        }
        return current1-> data;}
}*/
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n,key;
       scanf("%d%d", &n, &key);

       createlist(n);
       int f = search_index(head,key);
       printf("%d\n", f);

    }
    return 0;
}