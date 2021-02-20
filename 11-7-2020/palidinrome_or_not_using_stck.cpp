#include <iostream>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node *head;

void createlist(int n)
{
    int data,j;
    node *newNode, *temp;
    head = (node*)malloc(sizeof(node));
    if(head==NULL)
    {
        cout << "unable to allocate memory" << endl;
    }

    else
    {
        cin >> data;
        head -> data = data;
        head -> next = NULL;

        temp = head;
        for(j=2;j<=n;j++)
        {
            newNode = (node*)malloc(sizeof(node));
            if(newNode==NULL)
            {
                cout << "unable to allocate memory" << endl;
            }

            else
            {
                cin >> data;
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next = newNode;
                temp = temp-> next;
            }
            
        }
    }
    
}

bool isPalindrome(struct node *head)
{
    //construct an empty stack
    stack <int> s;
    
    //push all elemnts of the linked list into the stack
    node *temp = head;
    while(temp!=NULL)
    {
        s.push(temp->data);
        temp = temp -> next;
    }

    //traverse the linked list
    temp = head;
    while(temp!=NULL)
    {
        int top = s.top();
        s.pop();

        //compare the popped elemnt with curremt node's data
        if(top != temp->data)
        {
            return false;
        }
        temp = temp -> next;
    }

    return true;
}
int main()
{
    int t,i;
    cin >> t;
    for(i=0;i<t;i++)
    {
       int n;
       cin >> n;
       createlist(n);

       if(isPalindrome(head))
       {
           cout << 1 << endl;
       }

       else
       {
           cout << 0 << endl;
       }
       
    }
    return 0;
}