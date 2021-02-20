#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    struct node *next;
    int data;
};

struct node *head;

void createlist(int n)
{
    int data,j;
    struct node *temp, *new;
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL)
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
            new = (struct node*)malloc(sizeof(struct node));
            if(new == NULL)
            {
                printf("unable to allocate memory");
            }

            else
            {
                scanf("%d", &data);
                new -> data = data;
                new -> next = NULL;
                temp->next = new;
                temp = temp->next;
            }
        }
    }
}

/*int root_nth_node(int n)
{
    struct node *temp;
    int j;
    int res = sqrt(n);
    temp = head;
    for(j=1;j<res;j++)
    {
         temp = temp -> next;
    }
    return temp->data;
}*/

struct node *rootnthnode(struct node *head)
{
    struct node *sqrtn=NULL;
    int i=1,j=1;
    for(;head!=NULL;head=head->next)
    {
        if(i==j*j)
        {
            if(sqrtn==NULL)
            {
                sqrtn = head;
            }

            else
            {
                sqrtn = sqrtn -> next;
            }
            j++;
        }
        i++;
    }
    return sqrtn;
}
void print(struct node *temp)
{
    //struct node *temp;
    printf("%d\n", temp->data);
    //temp = temp->next;
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int n;
       scanf("%d", &n);
       createlist(n);

      // printf("%d\n", root_nth_node(n));
      struct node *temp = rootnthnode(head);
      print(temp);
      
    }
    return 0;
}