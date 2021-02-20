#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
    private:
       stack <int> s1;
       stack <int> s2;
    public:
       void push(int B);
       int pop();
};

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
         StackQueue *sq = new StackQueue();
         int Q;
         cin >> Q;
         while(Q--)
         {
             int QueryType = 0;
             cin >> QueryType;
             if(QueryType==1)
             {
                 int a;
                 cin >> a;
                 sq -> push(a);
             }
             else if(QueryType==2)
             {
                 cout << sq->pop() <<" ";
             }
         }
         cout << endl;
    }
    return 0;
}

void StackQueue :: push(int x)
{
    s1.push(x);
}

int StackQueue :: pop()
{
    if(s1.empty()&&s2.empty())
    {
        return -1;
    }
    else if(!s2.empty())
    {
       int x = s2.top();
       s2.pop();
       return x;
    }

    else
    {
        while(!s1.empty())
        {
            int y = s1.top();
            s1.pop();
            s2.push(y);
        }
        int z = s2.top();
        s2.pop();
        return z;
    }
    
}