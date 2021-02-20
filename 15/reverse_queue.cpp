#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue <ll> rev(queue <ll>q);
int main()
{
    ll test;
    cin >> test;
    for(int i=0;i<test;i++)
    {
        queue <ll> q;
        ll n,var;
        cin>>n;
        while(n--)
        {
            cin >> var;
            q.push(var);
        }
        queue <ll> a=rev(q);
        while(!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
    return 0;
}

queue <ll> rev(queue <ll> q)
{
    //create a stack
    stack <ll> s;
    //first condition when queue is not empty
    while(!q.empty())
    {
        //push elements of queue in stack
        int z = q.front();
        s.push(z);
        //pop elements from queue
        q.pop();
    }
    //make queue again
    while(!s.empty())
    {
        //push elements in queue  
        int x = s.top();
        q.push(x);
        //pop elemnts from stack
        s.pop();
    }
    return q;
}