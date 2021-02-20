#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
void max_sliding_window(int a[], int n,int k)
{
    deque <int> q(k);
    int j;
    for( j=0;j<k;j++)
    {
        while((!q.empty())&&a[j]>=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(j);
    }
    for(j=k;j<n;j++)
    {
        cout << a[q.front()] << " ";
        while((!q.empty())&&q.front()<=j-k)
        {
            q.pop_front();
        }

        while((!q.empty())&&a[j]>=a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(j);
    }
    cout << a[q.front()] << " ";
}
int main()
{
    int t;
    cin >> t;
    for(int j=0;j<t;j++) {
    int n,k;
    cin >> n;
    
    int a[100000];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cin >> k;
    max_sliding_window(a,n,k);
    cout << endl;}
    return 0;
}