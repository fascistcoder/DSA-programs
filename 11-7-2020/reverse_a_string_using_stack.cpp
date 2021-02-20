#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void reverse(char *str, int len);

int main()
{
   ll t;
   cin >> t;
   for(int j=0;j<t;j++)
   {
       char str[100000];
       cin >> str;

       ll len = strlen(str);
       reverse(str,len);
       cout << str;
       cout << endl;
   }

   return 0;
}

void reverse(char *str, int len)
{
    stack <char> s;
    for(int i=0;i<len;i++)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        /* code */
        str[i] = s.top();
        s.pop();
    }
}