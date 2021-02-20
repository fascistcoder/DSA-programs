#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define size 100
char stack[size];
int top = -1;


void infix_to_prefix(char infix_op[], char prefix_op[])
{

}
int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
        char infix[size], prefix[size];
        gets(infix);

        infix_to_prefix(infix,prefix);
        puts(prefix);
    }
    return 0;
}
