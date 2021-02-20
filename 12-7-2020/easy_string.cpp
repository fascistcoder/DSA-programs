#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void Easy_string(string str, int l)
{
    stack <char> s;
    //push string into the stack
    for(int j=l-1;j>=0;j--)
    {
        if(str[j]>=97 && str[j]<=122)
        {
            s.push(str[j]);
        }

        else
        {
            s.push(str[j]+32);
        }
    }
    int c=1;
    char x = s.top();
    //pop first element  from the stack
    s.pop();
    while(!s.empty())
    {
        if(x==s.top())
        {
            c++;
        }

        else
        {
            cout << c << x;
            x = s.top();
            c = 1; 
        }

        s.pop();
    }
    //condition for last character because our stack is empty 
    if(str[l-1]>=97&&str[l-1]<=122)
    {
        cout << c << str[l-1];
    }

    else
    {
        char y = str[l-1]+32;
        cout << c << y;
    }
}
int main()
{
    int t;
    scanf("%d\n", &t);
    for(int i=0;i<t;i++)
    {
        char str[1000];
        gets(str);
        
        int l = strlen(str);
        Easy_string(str,l);
        cout << endl;
    } 
    return 0;
}

/*
using namespace std;
#define mod 1000000007


int main()
 {
	int t ;
	cin >> t ;
	while(t--){
	    string s ;
	    char curr ;
	    cin >> s ;
	   // cout << s << endl ;
	    int n = s.length() , i , c = 1 ;
	    for(i=0;i<n;i++){
	        if(s[i] < 97){
	            s[i] += 32 ;
	        }
	    }
	    curr = s[0] ;
	    for(i=1;i<=n;i++){
	        if(s[i] != s[i-1]){
	            cout << c ;
	            cout << curr ;
	            curr = s[i] ;
	            c = 1 ;
	        }
	        else{
	            c++ ;
	        }
	    }
	    
	    cout << endl ;
	}
	
	return 0;
}*/