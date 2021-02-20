#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define size 1000
using namespace std;
typedef long l;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
       l k,n,a[size];
       cin >> k;
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }

       sort(a,a+n);

       l low = a[0] + k;
       l high = a[n-1] - k;
       l res = high - low;
       cout << res << endl;
    }
    return 0;
}