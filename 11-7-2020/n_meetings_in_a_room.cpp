#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define size 100000
using namespace std;

struct Meetings
{
    int start;
    int finish;
    int index;
};
bool meetingsComapre(Meetings s1, Meetings s2)
{
    return s1.finish < s2.finish;
}
void n_meetings_in_a_room(Meetings a[], int n)
{
    sort(a,a+n,meetingsComapre);
    int i=0,c=0;
    cout << a[i].index << " ";
    for(int j=1;j<n;j++)
    {
        a[j].index = i+1;
        if(a[j].start>=a[i].finish)
        {
            c++;
            cout << a[j].index << " ";
            i = j;
        }
    }
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
       int n;
       Meetings a[size];
       cin >> n;
       for(int j=0;j<n;j++)
       {
           cin >> a[j].start;  
       }

       for(int j=0;j<n;j++)
       {
           cin >> a[j].finish;
       }

       n_meetings_in_a_room(a,n);
       cout << endl;
    }
    return 0;
}