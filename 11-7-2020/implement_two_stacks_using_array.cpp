#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1,top2;

public:
    twoStacks(int n=100){size = n; arr = new int[n]; top1=-1; top2=size;}

    void push1(int x);
    void push2(int x);
    int pop1();
    int pop2();
};

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        twoStacks *sq = new twoStacks();
        int Q;
        cin >> Q;
        while(Q--)
        {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

        if(QueryType==1)
        {
            int a;
            cin >> a;
            if(stack_no==1)
            {
                sq -> push1(a);
            }
            else if(stack_no==2)
            {
                sq -> push2(a);
            }
        }

        else if(QueryType == 2)
        {
                if(stack_no==1)
                {
                    cout << sq->pop1() << " ";
                }

                else if(stack_no==2)
                {
                    cout << sq -> pop2() << " ";
                }
        }
    
      }cout << endl;
    }
}

void twoStacks :: push1(int x)
{
    arr[++top1] = x;
}

void twoStacks :: push2(int x)
{
    arr[--top2] = x;

}

int twoStacks::pop1()
{
    if(top1==-1)
    {
        return -1;
    }

   int x = arr[top1--];
   return x;
}

int twoStacks :: pop2()
{
    if(top2==size)
    {
        return -1;
    }

    int x = arr[top2++];
    return x;
}