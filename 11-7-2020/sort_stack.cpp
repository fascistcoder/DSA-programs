#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class SortedStack{
    public:
       stack <int> s;
       void sort();
};

void printStack(stack <int> s)
{
    while(!s.empty())
    {
        cout << s.top() << " ";
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
        SortedStack *ss = new SortedStack();
        int n;
        cin >> n;
        for(int j=0;j<n;j++)
        {
            int k;
            cin >> k;
            ss -> s.push(k);
        }
        ss -> sort();
        printStack(ss->s);
    }
}

void sort(stack <int> &s)
{
    int temp;
    if(!s.empty())
    {
      temp = s.top();
      s.pop();
      sort(s);
      sortedInsert(s,temp);
    } 
}
void sortedInsert(stack <int> s, int ele)
{
    if(s.empty()||ele>s.top())
    {
        s.push(ele);
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        sortedInsert(s,ele);
        s.push(temp);
    }
}
