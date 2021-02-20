#include <iostream>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
typedef int ll;

int maxArea(int M[MAX][MAX], int n, int m);
int max_area_hist(int a[], ll n);
void next_smaller_left(int a[], ll n, ll LS[]);
void next_smaller_right(int a[], ll n, ll RS[]);

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,m;
        int M[MAX][MAX];

        cin >> n >> m;
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> M[k][j];
            }
        }
        cout << maxArea(M,n,m) << endl;
    }
    return 0;
}

void next_smaller_right(int a[], ll n, ll RS[])
{
    stack <ll> rs;
    int p;
    for(int j=n-1;j>=0;j--)
    {
        while(!rs.empty()&&a[j]<=a[rs.top()])
        {
           rs.pop();
        }
        if(rs.empty())
        {
            p = n;
        }
        else
        {
            p = rs.top();
        }
        RS[j] = p;
        rs.push(j);
    }
}

void next_smaller_left(int a[], ll n, ll LS[])
{
    stack <ll> ls;
    int p;
    for(int j=0;j<n;j++)
    {
        while(!ls.empty()&&a[j]<=a[ls.top()])
        {
            ls.pop();
        }
        if(ls.empty())
        {
            p = -1;
        }
        else
        {
            p = ls.top();
        }
        LS[j] = p;
        ls.push(j);
    }
}

int max_area_hist (int a[], ll n)
{
    ll RS[MAX], LS[MAX], width[MAX],mul,max=0;
    next_smaller_left(a,n,LS);
    next_smaller_right(a,n,RS);

    for(int j=0;j<n;j++)
    {
        width[j] = RS[j] - LS[j] -1;
    }

    for(int j=0;j<n;j++)
    {
        mul = a[j] * width[j];
        if(max<mul)
        {
            max = mul;
        }
    }
    return max;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int max = -1;
    //int r = m;
    ll row[m] = {0};
    for(int k=0;k<n;k++)
    {
        for(int j=0;j<m;j++)
        {
          if(M[k][j]==0)
          {
                row[j] = 0;
          }

          else
          {
              row[j] += M[k][j];
          }
        }
        int result = max_area_hist(row,m);
        if(result > max)
        {
            max = result;
        }
    }
    return max;
}

/*
    stack<int>st;
    int i=0,x,maxx=0,area;
    while(i<m){
        if(st.empty() || hist[st.top()]<=hist[i]){
            st.push(i++);
        }
        else{
            x=st.top();
            st.pop();
            area=hist[x]*(st.empty()?i:i-st.top()-1);
            if(maxx<area)
            maxx=area;
    }
    }
    while(!st.empty()){
        x=st.top();
        st.pop();
        area=hist[x]*(st.empty()?i:i-st.top()-1);
        if(area>maxx)
        maxx=area;
    }
    return maxx;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    int histo[m],i,j,hist,maxhist,maxx=0;
    memset(histo,0,sizeof(histo));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(M[i][j]==0)
                histo[j]=0;
            else
                histo[j]+=1;
        
        }
        maxhist=histogram(histo,m);
        if(maxhist>maxx)
        maxx=maxhist;
    }
    return maxx;
}*/

/*
    int maxx[n];
    int val,final_val;
    for(int i=0;i<n;i++)
        maxx[i] = INT_MIN;
    stack<int>st;
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<n;i++)
    {
        st.push(0);
        if(i+1 < n && M[i+1][0]!=0)
            M[i+1][0] = M[i][0]+M[i+1][0];
        v1.push_back(-1);
        for(int j=1;j<m;j++)
        {
            //cout <<"M[i][j] = "<< M[i][j] << " \n";
            if(i+1 < n && M[i+1][j]!=0)
                M[i+1][j] = M[i+1][j] + M[i][j];
            while(!st.empty() && M[i][st.top()] >= M[i][j])
                st.pop();
            if(st.empty())
                v1.push_back(-1);
            else
                v1.push_back(st.top());
            st.push(j);
        }
        while(!st.empty())
            st.pop();
        v2.push_back(m);
        for(int k=0;k<m;k++)
            arr[k] = M[i][k];
        st.push(0);
        reverse(arr,arr+m);
        for(int k=1;k<m;k++)
        {
            while(!st.empty() && arr[st.top()] >= arr[k])
                st.pop();
            if(st.empty())
                v2.push_back(m);
            else
                v2.push_back(st.top());
            st.push(k);
        }
        reverse(v2.begin(),v2.end());
        for(int k=0;k<m;k++)
            if(v2[k]!=m)
                v2[k] = m-1-v2[k];
        for(int k=0;k<m;k++)
        {
            val = v2[k] - v1[k] - 1;
            final_val = val * M[i][k];
            if(final_val > maxx[i])
                maxx[i] = final_val;
        }
        v1.erase(v1.begin(),v1.end());
        v2.erase(v2.begin(),v2.end());
        while(!st.empty())
            st.pop();
    }
    int final_maxx=INT_MIN;
    for(int i=0;i<n;i++)
        if(final_maxx < maxx[i])
            final_maxx = maxx[i];
    return final_maxx;
}
*/
