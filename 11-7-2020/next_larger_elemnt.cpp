#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
void next_larger_element(int a[], int n)
{
    stack <int> s;
    int a1[1000];
    //iterating from n-1 to 0
    for(int j=n-1;j>=0;j--)
    {
        //we will pop till we get the greater element on top or stack gets empty 
        while(!s.empty()&&a[j]>=s.top())
        {
            s.pop();
        }
        //if stack gots empty means there is no element on right which is greater than current element
        if(s.empty())
        {
            a1[j] = -1;
        }
        //if not empty then the next greater is on top of stack
        else
        {
            a1[j] = s.top();
        }
        s.push(a[j]);
    }
    for(int j=0;j<n;j++)
    {
        cout << a1[j] << " ";
    }
    cout << endl;;
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
       int n,a[1000];
       cin >> n;
       for(int j=0;j<n;j++)
       { 
            cin >> a[j];
       }

       next_larger_element(a,n);
    }
    return 0;
}