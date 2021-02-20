#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node (int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int findMax (struct node* root);

int findMin(struct node* root);

void insert(struct node *root, int n1, int n2, char lr)
{
    if(root == NULL)
    {
        return;
    }

    if(root -> data == n1)
    {
        switch(lr)
        {
            case 'L' : root -> left = new node(n2);
                    break;
            case 'R' : root -> right = new node(n2);
                   break;
        }
    }

    else
    {
        insert (root -> left, n1 , n2, lr);
        insert (root -> right, n1, n2, lr);
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        struct node *root = NULL;
        while(n--)
        {
            char lr;
            int n1,n2;
            cin >> n1 >> n2;
            cin >> lr;
            if(root == NULL)
            {
                root = new node(n1);
                switch(lr)
                {
                    case 'L' : root -> left = new node (n2);
                    break;
                    case 'R' : root -> right = new node (n2);
                    break;
                }
            }

            else
            {
                insert(root,n1,n2,lr);
            }
            
        }

        cout << findMax(root) << " " << findMin(root) << endl;
    }
    return 0;
}

int findMax(struct node* root)
{
    int max = INT_MIN;
    if(root == NULL)
    {
        return max;
    }

    else
    {
        int res = root -> data;
        int lres = findMax(root -> left);
        int rres = findMax(root -> right);

        if(lres> res)
        {
            res = lres;
        }

        if(rres > res)
        {
            res =  rres;
        }

        return res;
    }
    
}

int findMin(struct node* root)
{
    int min = INT_MAX;

    if(root == NULL)
    {
        return min;
    }

    else
    {
        int res = root -> data;
        int lres =  findMin(root -> left);
        int rres = findMin(root -> right);

        if(lres < res)
        {
            res = lres;
        }

        if(rres < res)
        {
            res = rres;
        }

        return res;
    }
    
}