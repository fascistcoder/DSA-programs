#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

stack <int> s;
  
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
        int a[1000],n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
          cin >> a[j];
        }
        for(int j=0;j<n;j++)
        {
          s.push(a[j]);
        }

        for(int k=0;k<n;k++)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
    return 0;
}