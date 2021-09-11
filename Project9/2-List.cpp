#include <iostream>
using namespace std;

#include "2-List.h"

List::List()
{
  length = 0;
  head = NULL;
}

List::~List()
{
  node* current = head;
  while( current != 0 ) 
  {
    node* next = current->next;
    delete current;
    current = next;
  }
  head = 0;
}

bool List::IsEmpty() const
{
  // If statement to check if head is equal to NULL
  if(head == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int List::GetLength() const
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

void List::PutItemH(const itemType newItem)
{
  node* temp = new node;
  temp->item = newItem;
  temp->next = head;
  head = temp;
  length++;
  temp = NULL;
}

itemType List::GetItemH() const
{
  node* current = head;
  return current->item;
}

void List::DeleteItemH()
{
  node* current = NULL;
  current = head->next;
  free(head);
  head = current;
  length--;
}
	
void List::Print() const
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

int List::Find(const itemType item) const
{
  node* current = head;
  
  // For loop to iterate throught the list
  for(int i = 0; i < length; i++)
  {
    // If statement to check if current item is equal to item
    if(current->item == item)
      return i;
    current = current->next;
  }
  return -1;
}

void List::DeleteItem(const int pos)
{
  int i = 0;
  int retval = -1;
  node* current = head;
  node* temp = NULL;
  
  // If statement to see if pos is header and then delete it
  if (pos == 0) 
  {
    node* current = NULL;
    current = head->next;
    retval = head->item;
    free(head);
    head = current;
    length--;
  }

  // For loop to iterate through position
  for (i = 0; i < pos-1; i++) 
  {
    if (current->next == NULL) 
      break;
    current = current->next;
  }

    temp = current->next;
    retval = temp->item;
    current->next = temp->next;
    free(temp);
    length--;
}
