#include <stdio.h>
#include <stdlib.h>
#define size 1000

//int top= 0;
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;

void push(int data)
{
    struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
    scanf("%d", &data);
    /*if(top==NULL)
    {
        newNode -> data;
        newNode -> next = NULL;
        top = newNode;
    }*/

    //else
    //{
       newNode -> data = data;
       newNode -> next = top;
       top = newNode;
       //top++;
       //printf("data pushed to stack");
//    }
}
int pop()
{
    int data;
    struct stack *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
       //  return INT_MIN;
    }
     temp = top;
     top = temp -> next;
     //temp -> next =NULL;
     data = temp -> data;
     free(temp);
     return data;

} 
void display()
{
    struct stack *temp;
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp = top;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
              temp = temp->next;
            //  c++;
        }
    }
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        int choice,data;
        while(1)
        {
            printf("1.Push 2.Pop 3.Display 4.Exit  ");
            printf("Enter your choice: ");

            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                push(data);
                break;
            case 2:
                pop();
                break;

            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choive\n");
            }
        }
    }
    return 0;
}