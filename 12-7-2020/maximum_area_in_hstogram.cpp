#include<iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
#define size 1000
using namespace std;
typedef long long ll;
void next_smaller_left(ll a[], ll n, ll LS[])
{
    stack <ll> ls;
    int p;
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
    int p;
    for(int j=n-1;j>=0;j--)
    {
        while(!rs.empty()&&a[rs.top()]>=a[j])
        {
            rs.pop();
        }
        if(rs.empty())
        {
            p = n;
        }
        else
        {
            p = rs.top();
        }
        RS[j] =  p;
        rs.push(j);
    }
}

ll max_area(ll a[], ll n)
{
    ll RS[size],LS[size],width[size],mul,max=0;
    next_smaller_left(a,n,LS);
    next_smaller_right(a,n,RS);

    for(int j=0;j<n;j++)
    {
        width[j] = RS[j] - LS[j] -1;
    }
    for(int j=0;j<n;j++)
    {
        mul = a[j]*width[j];
        if(max<mul)
        {
            max = mul;
        }
    }
    return max;
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
        //max_area(a,n);
        cout << max_area(a,n) << endl;
    }
    return 0;
}