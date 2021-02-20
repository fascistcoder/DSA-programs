#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
    private:
        queue<int>q1;
        queue<int>q2;
    public:
        void push(int);
        int pop();
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        QueueStack *qs = new QueueStack();
        int Q;
        cin >> Q;
        while(Q--)
        {
            int QueryType=0;
            cin >> QueryType;
            if(QueryType==1)
            {
                int a;
                cin >> a;
                qs -> push(a);
            }

            else if (QueryType==2)
            {
                cout << qs->pop() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

void QueueStack :: push(int x)
{
    if(q1.empty())
    {
        q2.push(x);
    }
    else
    {
        q1.push(x);
    }
}

int QueueStack :: pop()
{
    int i,size;
    if(q1.empty()&&q2.empty())
    {
        return -1;
    }
    if(!q1.empty())
    {
        size = q1.size();
        for(int i=0;i<size-1;i++)
        {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int y = q1.front();
        q1.pop();
        return y;
    }

    else 
    {
        size = q2.size();
        for(int i=0;i<size-1;i++)
        {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        int y = q2.front();
        q2.pop();
       return y;
   }
}

/*void QueueStack :: push(int x)
{
   q1.push(x);
}

int QueueStack :: pop()
{
    if(q1.empty()&&q2.empty())
    {
        return -1;
    }
    else if(!q2.empty())
    {
        int y = q2.front();
        q2.pop();
        return y;
    }

    else 
    {
        while(!q1.empty())
        {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        int y = q2.front();
        q2.pop();
       return y;
   }
}*/