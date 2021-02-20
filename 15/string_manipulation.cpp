#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define siz 100
int string_manipulation(string str[], int n)
{
    stack <string> s;
    for(int j=0;j<n;j++)
    {
        if(!s.empty()&&s.top()==str[j])
        {
           s.pop();
        }
        else
        {
            s.push(str[j]);
        } 
    }
    int k = s.size();
    return k;
}
int main()
{
    int t;
    scanf("%d\n", &t);
    for(int i=0;i<t;i++)
    {
        int n;
        string str[siz];
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin >> str[j];
        }
        
        cout << string_manipulation(str,n) << endl;
    }
    return 0;
}