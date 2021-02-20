#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void generate_binary_no(int n)
{
    queue <string> q;
    q.push("1");
    for(int j=1;j<=n;j++)
    {
        string str = q.front();
        q.pop();
        
        cout << str << " ";
        q.push(str + "0");
        q.push(str + "1");
    }
}
int main()
{
    int t,i;
    cin >> t;
    for(int i=0;i<t;i++)
    {
         int n;
         cin >> n;

         generate_binary_no(n);
         cout << endl;
    }
    return 0;
} 