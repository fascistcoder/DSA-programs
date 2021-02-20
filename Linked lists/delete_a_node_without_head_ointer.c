/*We are given a pointer to a node (not the tail node) in a
singly linked list. Delete that node from the linked list.
Solution: To delete a node, we have to adjust the next pointer of the previous
node to point to the next node instead of the current one. Since we don’t have
a pointer to the previous node, we can’t redirect its next pointer. So what do
we do? We can easily get away by moving the data from the next node into the
current node and then deleting the next node.*/
struct Node 
{
    int data;
    struct Node* next;
}

void deleteNode(Node *Node)
{
   // Your code here
   struct Node *temp;
   temp = Node -> next;
   Node -> data = Node -> next -> data;
   Node -> next = temp -> next;
   free(temp);
}