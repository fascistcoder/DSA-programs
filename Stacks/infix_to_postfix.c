#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char infix[50];
char postfix[50];
char opstack[50]; //operator stack
int j,k,top=0;

int lesspriority(char op, char op_at_stack)
{
   int l;
   int pv1; //priority value of op
   int pv2; //priority value of op_at_astack
   char operators[] = {'+','-','*','/','%', '^', '('};
   int priority_value[] = {0,0,1,1,2,3,4};
   if(op_at_stack=='(')
   {
       return 0;
   }

   for(l=0;l<6;l++)
   {
       if(op==operators[l])
       {
           pv1 = priority_value[l];
       }
   }

   for(l=0;l<6;l++)
   {
       if(op_at_stack==operators[l])
       {
           pv2 = priority_value[l];
       }
   }

   if(pv1<pv2)
   {
       return 1;
   }

   else
   {
       return 0;
   }
}
void push(char op)
{
    if(top==0)
    {
        opstack[++top] = op;
    }

    else
    {
        if(op!='(')
        {
           while(lesspriority(op,opstack[top-1])==1&&top>0)
           {
               postfix[j] = opstack[--top];
               j++;
           }
        }
        opstack[top] = op; //pushing onto stack
        top++;
    }
}

int pop()
{
    while(opstack[--top]!='(')
    {
        postfix[j] = opstack[top];
        j++;
    }
}
int main()
{
    //int i,t;
    //scanf("%d\n", &t);
    //for(i=0;i<t;i++)
    //{
       char ch;
       printf("\n Enter Infix Expression : ");
       gets(infix);
       while((ch==infix[k++]!='\0'))
       {
           switch(ch)
           {
               case ' ':break;
               case '(':
               case '+':
               case '-':
               case '*':
               case '/':
               case '^':
               case '%':
                     push(ch);
                     break;
                case ')':
                     pop();
                     break;
             default:
                 postfix[j] = ch;
                  j++;
           }
       }
       while(top>=0)
       {
           postfix[j] = opstack[--top];
           j++;
       }
       postfix[j]= '\0';
       printf("\n Infix expression: %s", infix);
       printf("\n Postfix expression: %s", postfix);
       
    //}
    //getch();
    return 0;
}