#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define size 100000
typedef long long ll;
using namespace std;

ll min_the_sum_of_products(ll a[], ll b[], ll n)
{
    ll sum=0;
    sort(a,a+n);
    sort(b,b+n,greater<ll>());
    
    for(int j=0;j<n;j++)
    {
       sum += a[j]*b[j]; 
    }

    return sum;
}
int main() 
{
	//code
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
      ll n,a[size],b[size];
      cin >> n;
      for(int j=0;j<n;j++)
      {
          cin >> a[j];
      }

       for(int k=0;k<n;k++)
      {
          cin >> b[k];
      }

      ll res = min_the_sum_of_products(a,b,n);
      cout << res << endl;
    }
	return 0;
}