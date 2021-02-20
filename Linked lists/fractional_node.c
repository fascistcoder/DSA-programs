#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;

void createlist(int n)
{
   int data,j;
   struct node *new,*temp;
   head = (struct node*)malloc(sizeof(struct node));
   if(head==NULL)
   {
       printf("unable to allocate memory");
   }

   else
   {
      scanf("%d", &data);
      head->data = data;
      head -> next = NULL;

      temp = head;
      for(j=2;j<=n;j++)
      {
          new = (struct node*)malloc(sizeof(struct node));
          if(new==NULL)
          {
              printf("unable to allocate memory");
          }
          else
          {
              scanf("%d", &data);
              new ->data = data;
              new -> next = NULL;
              temp->next = new;
              temp = temp->next;
          }
      }
   }
}

int fractional_node(int k)
{
    struct node *temp=head;
    int fractionalnode,c=0;
    if(k<=0)
    {
        return 0;
    }

    while(temp!=NULL)
    {
        c++;
        temp = temp->next;
    }
    if(c%k==0)
    {
        fractionalnode = (c/k);
    }

    else
    {
        fractionalnode = (c/k)+1;
    }
    temp = head;
    for(int j=1;j<fractionalnode;j++)
    {
        temp = temp->next;
    }

    return temp->data;
}

/*struct node  *fractionalnode_(struct node *head,int key)
{
  struct node *fractionalnode=NULL;
  int i=0;
  if(key<=0)
  {
      return NULL;
  }

  for(;head!=NULL;head=head->next)
  {
      if(i%key==0)
      {
          if(fractionalnode==NULL)
          {
              fractionalnode = head;
          }

          else
          {
              fractionalnode = fractionalnode -> next;
          }
          i++;
      }
     // head = head -> next;
  }
  return fractionalnode;
}*/

/*void print(struct node *temp)
{
    printf("%d\n", temp->data);
}*/
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int n,key;
        scanf("%d", &n);
        createlist(n);
        scanf("%d", &key);
        printf("%d\n", fractional_node(key));
      // struct node *temp = fractionalnode_(head,key);
      // print(temp);
    }
    return 0;
}