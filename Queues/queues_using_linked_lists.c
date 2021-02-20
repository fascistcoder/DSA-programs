#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front, *rear;

void enQueue()
{
    int data;
    struct node *new = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &data);
    new -> data = data;
    new -> next = NULL;
    if(rear==NULL)
    {
        front = new;
        rear = new;
    }

    else
    {
        rear -> next = new;
        rear = new;
    }
}

void deQueue()
{
    if(front == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        struct node *temp = front;
        front = front -> next;
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    if(front == NULL)
    {
        printf("Queue is empty");
    }

    else
    {
        while(temp!=NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("1. insertion 2. Deletion 3. Display 4. exit");
        printf("\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            exit(0);
        
        default:
            break;
        }
    }
   // return 0;
}