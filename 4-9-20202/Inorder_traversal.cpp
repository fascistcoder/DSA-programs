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
};

vector <int> inOrder(struct Node *root);

Node *newNode (int val)
{
    Node *temp = new Node;
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

//Function to build a tree
Node *buildTree(string str)
{
    if(str.length() == 0 || str[0]== 'N')
    return NULL;

    //Creating vector of strings from input
    //string after spiliting by space
    vector <string> ip;
    istringstream iss(str);
    for(string str; iss>> str; )
    {
        ip.push_back(str);
    }

    Node *root = newNode(stoi(ip[0]));

    //push the root to the queue
    queue<Node*>queue;
    queue.push(root);

    //starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();

        string currVal  = ip[i];

        //if the left child is not null
        if(currVal != "N")
        {
             currNode -> left = newNode(stoi(currVal));
             queue.push(currNode->left);
        }

        i++;
        if(i >= ip.size())
        {
            break;
        }
        currVal = ip[i];

        if(currVal != "N" )
        {
            currNode -> right = newNode(stoi(currVal));
            queue.push(currNode -> right);
        }
        i++;
    }

    return root;

} 

int main()
{
    int t;
    scanf("%d ", &t);
    for(int i=0;i<t;i++)
    {
        string s;
        getline(cin,s);
        Node *root = buildTree(s);
        vector <int> res = preorder(root);
        for(int i : res)
        {
            cout << i << " ";
        }

        cout << endl;
    }
    return 0;
}

vector <int> res;
vector <int> inOrder(Node* root)
{
    if(root == NULL)
    {
        return res;
    }
    else
    {
        inOrder(root->data);
        cout << root->data << " ";
        inOrder(root->right);
        return res;
    }
    
}