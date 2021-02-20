#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ll n;
        cin >> n;
        //create a stack
        stack <ll> s;

        while(n!=0)
        {
          //find last digit
          ll rem = n%10;
          //push into the stack
          //at first stack is empty
          if(s.empty())
          {
              s.push(rem);
          }
         //next stack is not empty
          else if(s.top()!=rem)
          {
              s.push(rem);
          }
          n = n/10;
        }

        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }

        cout << endl;
    }
    return 0;
}

