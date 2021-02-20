#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 100

int stack[size];
int top=-1;

void push(int item)
{
    if(top==size-1)
    {
        printf("overflow\n");
    }

    else
    {
        stack[++top] = item;
    }
}

int pop()
{
    int item;
    if(top==-1)
    {
        printf("underflow\n");
    }

    else
    {
       item = stack[top--];
       return item;
    }
}
int postfix_eval(char postfix[])
{
    int j;
    char ch;
    int data;
    int a,b;

    for(j=0;postfix[j]!='\0';j++)
    {
        ch = postfix[j];
        if(isdigit(ch))
        {
            push(ch-'0');
        }

        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            a = pop();
            b = pop();

            switch(ch)
            {
                case '*':
                    data = a*b;
                    break;
                case '/':
                    data = b/a;
                    break;
                case '-':
                    data = b-a;
                    break;
                case '+':
                    data = a+b;
                    break;
            }
            push(data);
        }
    }
    return data;
}
int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
       char postfix[size];
       gets(postfix);

       int result = postfix_eval(postfix);
       printf("%d\n", result);
    }
    return 0;
}