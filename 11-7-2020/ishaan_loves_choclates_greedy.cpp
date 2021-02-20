#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define size 10000
typedef long long ll;

void ishann_love(ll a[], int n)
{
    sort(a,a+n);

    cout << a[0] << endl;  
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
       ll n,a[size];
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }
        ishann_love(a,n);
    }
    return 0;
}