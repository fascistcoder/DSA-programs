#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int valid_substring(char *str,int l)
{
    //create a stack
    stack <char> s;
    int res = 0;
    //push -1 for base
    s.push(-1);
    //traverse the string
    for(int j=0;j<l;j++)
    {
        //if char is opening bracket
        if(str[j]=='(')
        {
            s.push(j);
        }
        //if char is closing bracket
        else
        {
            //pop the first index
            s.pop();
            //check for stack is empty or not
            //if stack is empty
            if(!s.empty())
            {
                //take maximum of previous result and difference of current index and top of the element
                res = max(res,j-s.top());
            }

            else
            {
                s.push(j);
            }
            
        }
        
    }
    //return the result
    return  res;
}
int main()
{
    int t,i;
    scanf("%d\n", &t);
    for(i=0;i<t;i++)
    {
         char s[10000];
         gets(s);
         int l = strlen(s);
         cout << valid_substring(s,l) << endl;
    }
    return 0;
}