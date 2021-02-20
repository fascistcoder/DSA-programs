#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
long long save_gotham(long long a[], long long n)
{
    long long res=0;
    stack <long long> s;
    s.push(a[0]);
    for(int j=1;j<n;j++)
    {
        while(!s.empty()&&a[j]>s.top())
        {
             res += a[j];
             s.pop();
        }
        s.push(a[j]);
    }
    return res;
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
       long long n,a[100000];
       cin >> n;
       for(int j=0;j<n;j++) 
       {
           cin >> a[j];
       }
    long long sum = save_gotham(a,n) ;

    cout << sum%1000000001 << endl;
    }
    return 0;
}