#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*void smaller_no_left(ll a[],ll n)
{
    stack <ll> s;
    for(int j=0;j<n;j++)
    {
       while(!s.empty()&&s.top()>=a[j])
       {
          s.pop();}
          if(s.empty())
          {
             cout << "-1" << " "; 
          }
          else
          {
              cout << s.top() << " ";
          }
       s.push(a[j]);
    }
}*/
void smaller_no_left(ll a[],ll n)
{
    stack <ll> s;
    cout << "-1" << " ";
    s.push(a[0]);
    for(int j=1;j<n;j++)
    {
        if(s.top()<a[j])
        {
            cout << s.top() << " "; 
        }
        else
        {
            while(!s.empty()&&s.top()>=a[j])
            {
                s.pop();
            }
            if(s.empty())
            {
                cout << "-1" << " ";
            }

            else
            {
                cout << s.top() << " ";
            }
        }
        s.push(a[j]);
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
       ll n,a[10000];
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }

       smaller_no_left(a,n);
       cout << endl;
    }
    return 0;
}