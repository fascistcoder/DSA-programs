#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *rotate (struct Node *head, int k );

void printlist(Node *n)
{
    while(n!=NULL)
    {
        cout << n-> data << " ";
        n = n-> next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n,val,k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for(int i=0;i<n-1;i++)
        {
            cin >> val;
            tail -> next = new Node(val);
            tail = tail -> next;
        }

        cin >> k;
        head = rotate(head,k);
        printlist(head);
    }
    return 1;
}

Node *rotate(Node *head, int k)
{
    if(k==0||head==NULL)
    {
        return NULL;
    }
   int key = k-1; 
    Node *current = head;
    while(key--)
    {
        current = current -> next;
    }

    struct Node *kthNode = current;

    while(current -> next != NULL)
    {
        current = current-> next;
    }

    current -> next = head;
    head = kthNode -> next;
    kthNode -> next = NULL;

    return head;
}