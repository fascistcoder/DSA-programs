#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_sub_array_sum(ll a[], ll n)
{
    stack<ll>s;
    ll max=0,sum=0;
    s.push(a[0]);
    for(int j=1;j<n;j++)
    {
        sum = a[j] + s.top();
        if(max<sum)
        {
            max = sum;
        }
        s.push(a[j]);
    }
    return max;
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
        ll n,a[10000];
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
        }

        cout << max_sub_array_sum(a,n) << endl;
    }
    return 0;
}