#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
//structure of a stack node
struct snode
{
    char data;
    struct snode *next;
};
void push(struct snode **top_ref, int data)
{
      struct snode *newNode;
      newNode = (struct snode*)malloc(sizeof(struct snode));
      if(newNode==NULL)
      {
          printf("stack overflow\n");
          getchar();
          exit(0);
      }   

      else
      {
          newNode->data=data;
          newNode->next = *top_ref;
          *top_ref = newNode;
      }
}

int pop(struct snode **top_ref)
{
     char res;
     struct snode *top;
     if(*top_ref==NULL)
     {
         printf("stack underflow\n");
         getchar();
         exit(0);
     }

     else
     {
         top = *top_ref;
         res = top->data;
         *top_ref = top->next;
         free(top);
         return res;
     }
}
bool isMatchingPair(char character1, char character2)
{
    if(character1 == '(' && character2 == ')')
    {
        return 1;
    }

    else if(character1 == '{' && character2 == '}')
    {
        return 1;
    }

    else if(character1 == '[' && character2 == ']')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
bool areParentheisBalnaces(char exp[])
{
    int j=0;
    //decalre an empty stack
    struct snode *stack=NULL;
    //Traverse the given expression to check matching parenthesis
    while(exp[j])
    {
        //if open parenthesis push in to the stack
        if(exp[j]=='{'|| exp[j]=='(' || exp[j]=='[')
        {
            push(&stack,exp[j]);
        }
        if(exp[j]=='}'|| exp[j]==')' || exp[j]==']')
        {
            if(stack==NULL)
            {
                return 0;
            }

            else if(!isMatchingPair(pop(&stack), exp[j]))
            {
                return 0;
            }
        }
        j++;
    }

    if(stack==NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
       char exp[100];
       gets(exp);

       if(areParentheisBalnaces(exp))
       {
          printf("Balanced\n");
       }
       else
       {
           printf("Not balanched\n");
       }
    }
    return 0;
}