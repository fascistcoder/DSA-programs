#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
int stack[size];
int top =-1;

void push(int c)
{
    
        stack[++top] = c;
}

int pop()
{
    int k;
    k=stack[top--];
    return k;
}

int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
        int c=1;
         char bracket[size];
         gets(bracket);

         int l = strlen(bracket);

         for(int j=0;j<l;j++)
         {
            if(bracket[j]=='(')
            {
                push(c);
                printf("%d ", c);
                c++;
            }

            else if(bracket[j]==')')
            {
                int k = pop();
                printf("%d ",k);
            }
         }
         printf("\n");
    }
    return 0;
}
