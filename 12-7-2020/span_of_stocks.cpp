#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
#define size 10000
using namespace std;
typedef long long ll;

void Finding_spans(ll a[], ll n)
{
    stack <ll> s;
    ll p,S[size];
    for(int j=0;j<n;j++)
    {
        while(!s.empty()&&a[j]>=a[s.top()])
        {
            s.pop();
        }
        if(s.empty())
        {
            p = -1;
        }
        else
        {
            p = s.top();
        }
        S[j] = j-p;
        s.push(j);
    }
    for(int j=0;j<n;j++)
    {
        cout << S[j] << " ";
    }
}
int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
       ll n,a[size];
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }
       Finding_spans(a,n);
       cout << endl;
    }
    return 0;
}