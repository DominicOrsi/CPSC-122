#include <iostream>
using namespace std;

#include "3-ListT.h"

int main()
{ 
  /*
  //Test Constructor (ListT)
  ListT lst;
  cout << "Length: " << lst.GetLength() << "\nHead: " << lst.GetItemH() << "\nTail: " << lst.GetItemT() << endl;
  
   //Test Deconstructor (~ListT)
  ListT* lst1 = new ListT;
  for(int i = 0; i < 6; i++)
    lst1->PutItemT(i);
  lst1->Print();
  cout << "Activating deconstructor\n";
  delete lst1;
  lst1->Print();
  cout << lst1->GetItemH() << " " << lst1->GetItemT();
  
  //Test IsEmpty
 //Use of a static list 
 ListT lst;
 cout << "Testing IsEmpty static list, filling static list\n";
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Static list is empty\n";
 if(lst.IsEmpty() == true)
 {
   cout << "True";
 }
 else if(lst.IsEmpty() == false)
 {
   cout << "False";
 }
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 =  new ListT;
 cout << "Testing IsEmpty dynamic list, not filling dynamic list\n";
 cout << "Dynamic list is empty\n";
 if(lst1->IsEmpty() == true)
 {
   cout << "True";
 }
 else if(lst1->IsEmpty() == false)
 {
   cout << "False";
 }
 cout << endl;
 
  //Test GetLength
 //Use of a static list 
 ListT lst;
 cout << "Testing GetLength static list, filling list with 5 integers\n";
 for (int i = 0; i < 20; i++)
   lst.PutItemH(i);
 cout << "Length of static list is: ";
 cout << lst.GetLength();
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 =  new ListT;
 cout << "Testing GetLength dynamic list, filling with 45 integers\n";
 for (int i = 0; i < 20; i++)
   lst1->PutItemH(i);
 cout << "Length of dynamic list is: ";
 cout << lst1->GetLength();
 cout << endl;
 
 //Test PutItemH
 //Use of a static list
 List lst;
 for (int i = 0; i < 20; i++) 
   lst.PutItemH(i);
 cout << "Making a list of 20 integers\n";
 lst.Print();
 cout << "Adding a 7 to the front of the list using static list\n";
 lst.PutItemH(7);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 43; i++) 
   lst1->PutItemH(i);
 cout << "Making a list of 43 integers\n";
 lst1->Print();
 cout << "Adding a 43 to the front of the list using static list\n";
 lst1->PutItemH(43);
 lst1->Print();
 cout << endl;
 
 // Test GetItemH
 //Use of a static list
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Will get the header of a list of 5 using static list\n";
 cout << lst.GetItemH();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 100; i++) 
   lst1->PutItemH(i);
 cout << "Will get the header of a list of 100 using dynamic list\n";
 cout << lst1->GetItemH();
 cout << endl;
 
 //Test DeleteItemH
 //Use of a static list
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << "Deleting header now using static list\n";
 lst.DeleteItemH();
 cout << "New list without previous header\n";
 lst.Print();
 cout << endl;
 //Use of dynamic list
 List* lst1 =  new List;
 for (int i = 0; i < 12; i++) 
   lst1->PutItemH(i);
 lst1->Print();
 cout << "Deleting header now using dynamic list\n";
 lst1->DeleteItemH();
 cout << "New list without previous header\n";
 lst1->Print();
 cout << endl;
 
 //Test PutItemT
 //Using a static list
 ListT lst;
 cout << "Making a 20 integer list\n";
 for(int i = 0; i < 20; i++)
   lst.PutItemT(i);
 lst.Print();
 cout << "Adding 100 to the tail of the list using static list\n";
 lst.PutItemT(100);
 lst.Print();
 cout << endl;
 //Using a dyamic list
 ListT* lst1 = new ListT;
 cout << "Making a 10 integer list\n";
 for(int i = 0; i < 10; i++)
   lst1->PutItemT(i);
 lst1->Print();
 cout << "Adding 30 to the tail of the list using dyamic list\n";
 lst1->PutItemT(30);
 lst1->Print();
 cout << endl;
 
 //Test GetItemT 
 //Use of a static list
 ListT lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemT(i);
 lst.Print();
 cout << "Will get the tail of a list of 5 using static list\n";
 cout << lst.GetItemT();
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 = new ListT;
 for (int i = 0; i < 100; i++) 
   lst1->PutItemT(i);
 lst1->Print();
 cout << "Will get the header of a list of 100 using dynamic list\n";
 cout << lst1->GetItemT();
 cout << endl;
  
 //Test DeleteItemT
 //Use of a static list
 ListT lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemT(i);
 lst.Print();
 cout << "Deleting tail now using static list\n";
 lst.DeleteItemT();
 cout << "New list without previous tail\n";
 lst.Print();
 cout << endl;
 //Use of dynamic list
 ListT* lst1 =  new ListT;
 for (int i = 0; i < 12; i++) 
   lst1->PutItemT(i);
 lst1->Print();
 cout << "Deleting tail now using dynamic list\n";
 lst1->DeleteItemT();
 cout << "New list without previous tail\n";
 lst1->Print();
 cout << endl;  
  
 //Test Print
 //Use of a static list 
 ListT lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 ListT* lst1 = new ListT;
 for (int i = 0; i < 20; i++)
   lst1->PutItemH(i);
 lst1->Print();
 cout << endl;
 
 //Test FindItem
 //Use of a static list 
 ListT lst;
 cout << "Creating a list from 0-19 then adding 14 to header and tail using static list\n";
 for (int i = 0; i < 20; i++)
   lst.PutItemH(i);
 lst.PutItemT(14);
 lst.PutItemH(14);
 lst.Print();
 cout << "The number 14 is located " << lst.FindItem(14) << " times\n";
 //Use of a dynamic list
 ListT* lst1 = new ListT;
 cout << "Creating a list from 0-9 then adding 8 to the tail using dyamic list\n";
 for(int i = 0; i < 10; i++)
   lst1->PutItemT(i);
 lst1->PutItemT(8);
 lst1->Print();
 cout << "The number 8 is located " << lst1->FindItem(8) << " times\n";
 
 //Test DeleteItem
 //Use of a static list
 ListT lst;
 cout << "Creating a list of 5 integers then adding 3 to the head\n";
 for(int i = 0; i < 5; i++)
   lst.PutItemT(i);
 lst.PutItemH(3);
 lst.Print();
 cout << "Deleting 3 from the linked list using static list\n";
 cout << "Number of threes deleted: " << lst.DeleteItem(3) << endl;
 lst.Print();
 //Use of a dyamic list
 ListT* lst1 = new ListT;
 cout << "Creating a list of 11 integers then adding 10 to the head and tail\n";
 for(int i = 0; i < 11; i++)
   lst1->PutItemT(i);
 lst1->PutItemH(10);
 lst1->PutItemT(10);
 lst1->Print();
 cout << "Deleting 10 from the linked list using dyanmic list\n";
 cout << "Number of threes deleted: " << lst1->DeleteItem(10) << endl;
 lst1->Print();
  */
 delete lst1; //necessary to invoke destructor on dynamic list
 return 0;
}
