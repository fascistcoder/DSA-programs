#include<iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
#define size 100000
using namespace std;
typedef long long ll;
void next_smaller_left(ll a[], ll n, ll LS[])
{
    stack <ll> ls;
    ll p;
    for(int j=0;j<n;j++)
    {
        while(!ls.empty()&&a[ls.top()]>=a[j])
        {
            ls.pop();
        }
        if(ls.empty())
        {
            p = -1;
        }
        else
        {
            p = ls.top();
        }
        LS[j] =  p;
        ls.push(j);
    }
}
void next_smaller_right(ll a[], ll n, ll RS[])
{
    stack <ll> rs;
    //ll p;
    for(ll j=n-1;j>=0;j--)
    {
        while(!rs.empty()&&rs.top()>=a[j])
        {
            rs.pop();
        }
        if(rs.empty())
        {
            RS[j] = -1;
        }
        else
        {
            RS[j] = rs.top();
        }
        //RS[j] =  p;
        rs.push(j);
    }
  
    //reverse(RS,RS+n);
}

void max_area(ll a[], ll n)
{
    ll LS[size];
    ll RS[size];
   // next_smaller_left(a,n,LS);
    next_smaller_right(a,n,RS);
    for(int j=0;j<n;j++)
    {
       cout << LS[j] << " ";
    }
    cout << endl;
    for(int j=0;j<n;j++)
    {
       cout << RS[j] << " ";
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
        max_area(a,n);
        //cout << max_area(a,n) << endl;
    }
    return 0;
}