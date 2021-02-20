#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 1000
char stack[size];
int top = -1;

//define push operation
void push(char item)
{
    if(top>=size-1)
    {
        printf("overflow\n");
    }

    else
    {
        stack[++top] = item;
    }
}

//define pop operation
char pop()
{
    char item;
    if(top<0)
    {
        printf("underflow\n");
        getchar();
    }

    else
    {
        item = stack[top--];
        return (item);
    }
}


/*define fuction that is used to detremine whether any symbol is opeartor or not
(that is symbol is operand) 
this function return 1 if symbol is operator else return 0*/

int is_operator(char symbol)
{
    if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-')
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precendence(char symbol)
{
    if(symbol == '^')
    {
        return (3);
    }

    else if(symbol == '*' || symbol == '/')
    {
        return (2);
    }

    else if(symbol=='+' || symbol=='-')
    {
        return (1);
    }

    else
    {
        return 0;
    }
}

/*void reverse(char a[])
{
    int i,j;
    char temp[size];

    for(i=strlen(a)-1,j=0;i+1!=0;--i,++j)
    {
        temp[j] = a[i];
    }

    temp[j] = '\0';
    strcpy(a,temp);
}*/

void Infix_to_postfix(char infix_exp[], char postfix_exp[])
{
   int i=0,j=0;
   char item;
   char x;
   
   push('('); //push '(' onto stack
   strcat(infix_exp,")"); //add')' to infix expression
   
   item = infix_exp[i]; //intiliaze before loop
   while(item != '\0') //run loop till end of infix expression
   {
       if(item=='(')
       {
           push(item);
       }

       else if(isdigit(item)||isalpha(item))
       {
           postfix_exp[j] = item; //add operand symbol to postfix expr
           j++;
       }

       else if(is_operator(item) == 1)
       {
           x = pop();
           while(is_operator(x) == 1 && precendence(x) >= precendence(item))
           {
               postfix_exp[j] = x; //so pop all higher precendence operator and
               j++;
               x = pop();  //add them to postfix expression
           }

           push(x); //because just above while loop will terminate we have popped one extra
           //item for which condition fials and loop terminates, so that one

           push(item); 

       }

       else if(item == ')')
       {
           x = pop();
           while(x!='(')
           {
               postfix_exp[j] = x;
               j++;
               x = pop();
           }
       }

       else
       {
           //if current symbol is neither operabd not '('')' and nopr opeartor
           printf("Invalid infix exprssion.");
           //getchar();
            exit(1);
       }
       i++;

       item = infix_exp[i]; //go to next symbol of infix exprssion
   }

   if(top>0)
   {
       printf("Invalid infix expression.");
       getchar();
       exit(1);
   }

   postfix_exp[j] = '\0';
   //add sentinal else puts() fuction
   //will print entire postfix[] array upto size
}


int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
        
        //printf("Enter infix expression: ");
        char infix[size],postfix[size];
        gets(infix);
       // reverse(infix);
        Infix_to_postfix(infix,postfix); //call to convert
        //reverse(postfix);
       // printf("\n");
       // printf("Postfix expression: "); 
        puts(postfix); //print postfix expression
       // printf("\n");
    }
    return 0;
}