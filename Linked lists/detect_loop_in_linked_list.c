//fast algorithm using harare and tortoise algorithm
//Floyd Circle Alogorithm
//Find a loop in linked list

/*
{
  struct node *fast = head, *slow = head;
  while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)
  {
      fast = fast->next->next;
      slow = slow->next;
      if(fast==slow)
      {
          return 1;
      }
  }
  return 0;
}*/

//start node of the loop
/* struct node *fast = head, *slow = head;
  while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)
  {
      fast = fast->next->next;
      slow = slow->next;
      if(fast==slow)
      {
          break
      }
  }
  if(slow==fast)
  {
    slow = head;
    while(slow!=fast)
    {
      fast = fast -> next;
      slow = slow -> next;
    }
    return slow;
  }
  return NULL;*/

  //length of the  loop
/* struct node *fast = head, *slow = head;
  while(fast!=NULL&&slow!=NULL&&fast->next!=NULL)
  {
      fast = fast->next->next;
      slow = slow->next;
      if(fast==slow)
      {
          break
      }
  }
  if(slow==fast)
  {
    fast = fast -> next;
    while(slow!=fast)
    {
      fast = fast -> next;
      c++;
    }
    return c;
  }
  return NULL;*/

