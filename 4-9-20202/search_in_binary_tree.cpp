#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;


node *createNode(int val)
{
    node *newNode = new node;
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void searchnode(node *temp, int value)

int main()
{
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d", &n);
        root = createNode(1);
        root -> left = createNode(2);
        root -> right = createNode(3);
        root -> left -> left= createNode(4);
        root -> right -> left= createNode(5);
        root -> right -> right= createNode(5);

        searchnode(root, n);
    }
    return 0;
}
