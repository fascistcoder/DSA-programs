#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    if(str.length() == 0|| str[0] == 'N')
    {
        return NULL;
    }

    vector <string> ip;

    istringstream iss(str);
    for(string str; iss>> str;)
    {
        ip.push_back(str);
    } 

    Node *root = new Node(stoi(ip[0]));

    queue <Node*> queue;
    queue.push(root);

    int i= 1;
    while(!queue.empty() && i<ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if(currVal != "N")
        {
            currNode -> left = new Node (stoi(currVal));

            queue.push(currNode -> left);
        }

        i++;
        if(i >= ip.size())
        {
            break;
        }

        currVal = ip[i];

        if(currVal != "N")
        {
            currNode -> right = new Node(stoi(currVal));
            queue.push(currNode -> right);
        }
        i++;
    }
    return root;
}

int height(struct Node* node)
{
    if(node == NULL)
    {
        return 0;
    }

    else
    {
        int leftheight = height(node -> left);
        int rightheight = height (node -> right);

        int h = max(leftheight, rightheight) + 1;
        return h;
    }
    
}

int main()
{
    int t;
    scanf("%d\n", &t);
    for(int i=0;i<t;i++)
    {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << height(root) << endl;
    }

    return 0;
}