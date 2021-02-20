#include <iostream>
#include <stdio.h>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int count_reversal_method1(char *exp,int l);
int count_reversal_method2(char *exp,int l);

int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
        char exp[1000];
        gets(exp);

        int l = strlen(exp);
        
        cout << count_reversal_method1(exp,l) << endl;
        cout << count_reversal_method2(exp,l) << endl;
    }
    return 0;
}

//method 1 using stacks space complexity o(n) and time complexity o(n)
int count_reversal_method1(char *exp,int l)
{
     //create a stack
     stack <char> s;

     //length odd return -1
     if(l%2!=0)
     {
         return -1;
     }

     else
     {
         //traverse the exprsession
         for(int j=0;j<l;j++)
         {
             if(!s.empty() && exp[j]=='}')
             {
                 if(s.top()=='{')
                 {
                    s.pop();
                 }
                 else
                 {
                     /* code */
                     s.push(exp[j]);
                 }
             }

             else
             {
                 s.push(exp[j]);
             }
         }
         int reversal_length = s.size();
         int n=0;
         while(!s.empty()&&s.top()=='{')
         {
             s.pop();
             n++;
         }

         return reversal_length/2 + n%2;
     } 
}

//method 2 space complexity o(1) and time complexity o(n)
int count_reversal_method2(char *exp,int l)
{
    int open =0, inversions=0;
    if(l%2!=0)
    {
        return -1;
    }
    else {
    //traverse the list    
    for(int j=0;j<l;j++)
    {
        if(exp[j]=='{')
        {
            open++;
        }

        else
        {
            if(open)
            {
                open = open -1;
            }

            else
            {
                inversions++;
                open = 1;
            }
        }
    }}
    return inversions + open/2;
}