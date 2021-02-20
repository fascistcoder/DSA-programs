#include <stdio.h>
#include <stdlib.h>
#define max_size 100
//create a stack
int stack[max_size];
//intially stack is empty
int top = -1;
void push(int data)
{
   if(top == max_size-1)
   {
       printf("Error: stack overflow");
       return;
   }

   else
   {
       top++;
       stack[top] = data;

       //stack[++top] = data;

       printf("data pushed into the stack\n");
   }
}

void pop()
{
    if(top==-1)
    {
        printf("Error: stack underflow");
        return;
    }

        stack[top--];
}
void display()
{
    int j;
    if(top==-1)
    {
        printf("stack is empty\n");
        return;
    }

    else
    {
        for(j=0;j<=top;j++)
        {
            printf("%d ", stack[j]);
        }
    }
}
int main()
{
    int t,i;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
       int choice, data;
       while(1)
       {
           printf("1. Push\n");
           printf("2. Pop\n");
           printf("3. Size\n");
           printf("4. Display\n");
           printf("5. Exit\n");
           printf("\nEnter you choice: ");

           scanf("%d", &choice);
           switch(choice)
           {
               case 1: 
                 scanf("%d", &data);
                 push(data);
                 break;

                case 2:
                    pop();
                    break;

                case 3:
                   printf("%d\n", top+1);
                   break;

                case 4:
                   display();
                   break;

                case 5:
                   exit(0);
                   break;

                default:
                    printf("Invalid choice\n");  
           }
           printf("\n");
       }
    }
    return 0;
}


