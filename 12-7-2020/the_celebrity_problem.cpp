#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAX 501

int getID(int M[MAX][MAX], int n);

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int M[MAX][MAX];
        int n;
        cin >> n;
        memset(M,0,sizeof M);
        for(int j=0;j<n;j++)
        {
           for(int k=0;k<n;k++)
           {
               cin >> M[j][k];
           }
        }

        cout << getID(M,n) << endl;
    }
    return 0;
}

int getID(int M[MAX][MAX], int n)
{
    stack <int> s;
    
    for(int j=0;j<n;j++)
    {
        s.push(j);
    }
    while(s.size()>1)
    {
       int index1 = s.top();
       s.pop();
       int index2 = s.top();
       s.pop();

       if(M[index1][index2]==1)
       {
           s.push(index2);
       }

       else
       {
           s.push(index1);
       }
    }
    //potential candiadate to become celebrity
    int pot = s.top();
    s.pop();
    for(int j=0;j<n;j++)
    {
        if(j!=pot)
        {
            if(M[j][pot]==0||M[pot][j]==1)
            {
                return -1;
            }
        }
    }
    return pot;
}

//method 2 
//two pinter algo
/*
// C++ program to find 
// celebrity in O(n) time 
// and O(1) extra space 
#include <bits/stdc++.h> 
using namespace std; 

// Max # of persons in the party 
#define N 8 

// Person with 2 is celebrity 
bool MATRIX[N][N] = {{0, 0, 1, 0}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}, 
					{0, 0, 1, 0} 
}; 

bool knows(int a, int b) 
{ 
	return MATRIX[a][b]; 
} 

// Returns id of celebrity 
int findCelebrity(int n) 
{ 
	// Initialize two pointers 
	// as two corners 
	int a = 0; 
	int b = n - 1; 

	// Keep moving while 
	// the two pointers 
	// don't become same. 
	while (a < b) 
	{ 
		if (knows(a, b)) 
			a++; 
		else
			b--; 
	} 

	// Check if a is actually 
	// a celebrity or not 
	for (int i = 0; i < n; i++) 
	{ 
		// If any person doesn't 
		// know 'a' or 'a' doesn't 
		// know any person, return -1 
		if ( (i != a) && 
				(knows(a, i) || 
				!knows(i, a)) ) 
			return -1; 
	} 

	return a; 
} 

// Driver code 
int main() 
{ 
	int n = 4; 
	int id = findCelebrity(n); 
	id == -1 ? cout << "No celebrity" : 
			cout << "Celebrity ID "
					<< id; 
	return 0; 
} 
*/