#include <iostream>
using namespace std;

#include "3-ListT.h"

ListT::ListT()
{
  length = 0;
  head = NULL;
  tail = NULL;
}

ListT::~ListT()
{
  node* current = head;
  while( current != NULL ) 
  {
    node* next = current->next;
    delete current;
    current = next;
    length--;
  }
  head = NULL;
  tail = NULL;
}

bool ListT::IsEmpty() const
{
  // If statement to check if head is equal to NULL
  if(head == NULL && tail == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int ListT::GetLength() const
{
  node* current = head;
  int i = 0;
  
  // While loop to iterate through the list
  while(current != NULL)
  {
    i++;
    current = current->next;
  }
  
  return i;
}

void ListT::PutItemH(const itemType newItem)
{
  node* temp = new node;
  temp->item = newItem;
  temp->next = head;
  head = temp;
  
  // If statement to assign tail to head if length is 0
  if(length == 0)
    tail = head;
  length++;
  temp = NULL;
}

itemType ListT::GetItemH() const
{
  node* current = head;
  
  // If statement to test if head is equal to NULL
  if(head == NULL)
    return -1;
  else
    return current->item;
}

void ListT::DeleteItemH()
{
  node* current = NULL;
  current = head->next;
  free(head);
  head = current;
  length--;
}

void ListT::PutItemT(const itemType itemIn)
{
  //If statement to see if length is zero then insert the itemIn at head instead of tail
  if(length == 0)
    PutItemH(itemIn);
  else
  { 
    node* temp = new node;
    temp->item = itemIn;
    tail->next = temp;
    tail = temp;
    length++;
    temp = NULL;
  }
}

itemType ListT::GetItemT() const
{
  node* current = tail;
  
  // If statement to test if tail is equal to NULL
  if(tail == NULL)
    return -1;
  else
    return current->item;
}

void ListT::DeleteItemT()
{
  node* current = new node;
  node* previous = new node;
  current = head;
  
  // While loop to run through current pointing to next till it hits NULL
  while(current->next != NULL)
  {
    previous = current;
    current = current->next;	
  }
  tail = previous;
  previous->next = NULL;
  length--;
  delete current;
}

void ListT::Print() const
{
  node* current = head;
  
  //While loop to iterate and print list
  while(current != NULL)
  {
    cout << current->item << " ";
    current = current->next;
  }
  cout << endl;
}

int ListT::FindItem(const itemType target) const
{
  node* current = head;
  int count = 0; 
  
  // For loop to iterate throught the list
  for(int i = 0; i < length; i++)
  {
    // If statement to check if current item is equal to target
    if(current->item == target)
      count++;
    current = current->next;
  }
  return count++;
}

int ListT::DeleteItem(const itemType target)
{
  node* temp;
  node* prev = NULL;
  node* next;
  int count = 0;

  // For loop to run through the linked list
  for (temp = head;  temp != NULL;  temp = next) 
  {
    next = temp->next;
    
    // If statement to see if temp pointing to item is equal target
    if (temp->item != target) 
    {
      prev = temp;
      continue;
    }

    // If statement to check if prev is equal to NULL
    if (prev != NULL)
      prev->next = next;
    else
      head = next;
    delete temp;
    count++;
  }
  return count;
}

node* ListT::PtrTo()
{
  node* current = new node;
  node* previous = new node;
  current = head;
  
  // While loop to run through current pointing to next till it hits NULL
  while(current->next != NULL)
  {
    previous = current;
    current = current->next;	
  }
  return previous;
}

