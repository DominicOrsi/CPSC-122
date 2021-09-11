
#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"

template <typename T>
ListD<T>::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template <typename T>
ListD<T>::ListD(ListD* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
ListD<T>::~ListD()
{
 for(int i = 0; i < length; i++)
   Delete(i);
 delete head;
 delete tail;
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 //Inserting at the tail is a special case.  It can be made much more efficient than
 //this.
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename T>
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::Delete(int pos)
{
 doubleNode<T>* cur = FindPosition(pos)->next;
 cur->prev->next = cur->next;
 cur->next->prev = cur->prev;
 delete cur;
 length--;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
 int count = 0;
 int i = 0;
 doubleNode<T>* cur = head;
 while(cur != NULL)
 {
   if(cur->item == item)
   {
   	Delete(i-count);
    count++;
   }
   cur = cur->next;
   i++;
 }
 return count;
}

template <typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>*  cur = head->next;

 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template <typename T>
void ListD<T>::PrintBackward()
{
 doubleNode<T>* cur = tail->prev;
 
 int i = 0;
 while(i < length)
 {
   cout << cur->item << endl;
   cur = cur->prev;
   i++;
 }
}

template <typename T>
void ListD<T>::Sort()
{
 int start = 1;
 while(start < length)
 {
   int small = FindSmallest(start);
   Swap(start, small);
   start++;
 }
}

template <typename T>
int ListD<T>::FindSmallest(int start)
{
 doubleNode<T>* cur = FindPosition(start)->next;
 int small = cur->item;
 int idx = start;
 for(int i = start; i <= length; i++)
 {
   if(cur->item <= small)
   {
     small = cur->item;
     idx = i;
   }
   cur = cur->next;
 }
 return idx;
}

template <typename T>
void ListD<T>::Swap(int pos, int small)
{
 doubleNode<T>* cur = FindPosition(pos)->next;
 doubleNode<T>* smallest = FindPosition(small)->next;
 int temp = cur->item;
 cur->item = smallest->item;
 smallest->item = temp;
}
