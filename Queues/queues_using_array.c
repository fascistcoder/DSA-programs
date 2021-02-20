#include <stdio.h>
#include <stdlib.h>
#define max 100
int front;
int rear;
int Q[max]; 

void EnQueue()
{
    int data;
    if(rear == max)
    {
        printf("overflow\n");
    }

    else
    {
        scanf("%d", &data);
        Q[rear] = data;
        rear++;
    }
}

void DeQueue()
{
    int data;
    if(rear==front)
    {
        printf("Underflow");
    }

    else
    {
        data = Q[front];
        front++;
    }
}

void display()
{
    int i;
    if(front == rear)
    {
        printf("Queue is empty");
    }

    else
    {
        for(i=front;i<rear;i++)
        {
            printf("%d ", Q[i]);
        }
    }
}

int main()
{
   int choice;
  
   while(1)
   {
       printf("1. insert 2. Delete 3. Display 4. exit");
       printf("\n");
        scanf("%d", &choice);
       switch(choice)
       {
           case 1:
               EnQueue();
               break;
            case 2:
                DeQueue();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
               exit(0);
            default:
              printf("Inavlid choice\n Try again");
              break;
       }
   }
}