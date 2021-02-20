#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
#define size 10000
using namespace std;
typedef long long ll;

ll maximize_toys(ll a[], ll n, ll k)
{
    ll sum=0,c=0;
    sort(a,a+n);
    for(int j=0;j<n;j++)
    {
        sum += a[j];
        if (sum<=k)
        {
            c++;
        }
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
       ll n,k,a[size];
       cin >> n >> k;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }

       cout << maximize_toys(a,n,k) << endl;
    }
    return 0;
}