#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

bool pairwiseConsecutive(stack <int> s)
{
    if(s.size()%2==1)
    {
        s.pop();
    }

    while(!s.empty())
    {
        int a = s.top();
        s.pop();
        if(a+1==s.top()||a-1==s.top())
        {
           s.pop();
           continue;
        } 
        else
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    for(int j=0;j<t;j++)
    {
        stack <int> s;
        int n,x;
        cin >> n;
        while(n--)
        {
            cin >> x;
            s.push(x);
        }

       if(pairwiseConsecutive(s))
       {
           cout << "YES" << endl;
       }

       else
       {
           cout << "No" << endl;
       }
       
    }
    return 0;
}