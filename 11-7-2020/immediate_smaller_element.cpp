#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
void immediate_smaller_element(int a[], int n)
{
    stack <int> s;
    s.push(a[0]);
    
    for(int j=1;j<n;j++)
    {
        if(a[j]<s.top())
        {
            cout << a[j] << " ";
            s.pop();
            s.push(a[j]);
        }

        else
        {
            cout << "-1" << " ";
            s.pop();
            s.push(a[j]);
        }
        
    }
    while(!s.empty())
    {
        cout << "-1" << " ";
        s.pop();
    }
    cout << endl;

}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n, a[10000];
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j];
       }

       immediate_smaller_element(a,n);
    }
    return 0;
}