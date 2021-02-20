#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct Activity
{
    int start;
    int finish;
};
bool activityCompare(Activity s1, Activity s2)
{
    return s1.finish < s2.finish;
}
int activity_selection_greedy(Activity a[], int n)
{
    //sort the actvity according to finish time
    sort(a,a+n,activityCompare);

    int k=0;
    int c= 1;
    for(int j=1;j<n;j++)
    {
        if(a[j].start>=a[k].finish)
        {
            c++;
            k=j;
        }
    }
    return c;
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
        int n;
        cin >> n;
        Activity a[10000];
        for(int j=0;j<n;j++)
        {
            cin >> a[j].start;
        }

        for(int j=0;j<n;j++)
        {
            cin >> a[j].finish;
        }

        cout << activity_selection_greedy(a,n) << endl;
    }
    return 0;
}