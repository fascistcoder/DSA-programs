#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void shop_in_candy_store(int a[], int n, int k)
{
    int max=0,min=0,temp=0,temp1=n;
    sort(a,a+n);
    for(int j=0;j<temp1;j++)
    {
        min += a[j];
        temp1 = temp1 - k;
    }

    for(int j=n-1;j>=temp;j--)
    {
        max += a[j];
        temp = temp + k;
    }
    cout << min << " " << max;
}
int main()
{ 
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,k,a[1000];
        cin >> n >> k;
        for(int j=0;j<n;j++)
        {
            cin >> a[j];
        }
        shop_in_candy_store(a,n,k);
        cout <<  endl;
    }
    return 0;
}