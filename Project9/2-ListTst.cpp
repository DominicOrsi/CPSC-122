#include <iostream>
using namespace std;

#include "2-List.h"

int main()
{
 /*
 //Test One Print 
 //Use of a static list 
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Putting a list of 5 in and then printing it using static list\n";
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
   lst1->PutItemH(10*i);
 cout << "Putting a list of 5 in times 10 then printing it out using dynamic list\n";
 lst1->Print();
 cout << endl;
 
 //Test Two PutItemH
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
 
 //Test Three GetLength
 //Use of static list
 List lst;
 cout << "Testing GetLength static list, filling list with 5 integers\n";
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Length of static list is: ";
 cout << lst.GetLength();
 cout << endl;
 //Use of a dynamic list
 List* lst1 = new List;
 cout << "Testing GetLength dynamic list, filling with 45 integers\n";
 for (int i = 0; i < 45; i++)
   lst1->PutItemH(i);
 cout << "Length of dynamic list is: ";
 cout << lst1->GetLength();
 cout << endl;
 
 //Test Four IsEmpty
 //Use of static list
 List lst;
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
 List* lst1 = new List;
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
 
 //Test Five GetItemH 
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
 
 // Test Six DeleteItemH
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
 
 //Test Seven DeleteItem
 //Use of static list
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 lst.Print();
 cout << "Deleting number 3 now using static list\n";
 lst.DeleteItem(1);
 cout << "New list without number 3\n";
 lst.Print();
 cout << endl;
 //Use of dynamic list
 List* lst1 =  new List;
 for (int i = 0; i < 12; i++) 
   lst1->PutItemH(i);
 lst1->Print();
 cout << "Deleting number 7 now using dynamic list\n";
 lst1->DeleteItem(4);
 cout << "New list without number 7\n";
 lst1->Print();
 cout << endl;
 
 //Test Eight Find
 //Use of static list
 List lst;
 for (int i = 0; i < 5; i++) 
   lst.PutItemH(i);
 cout << "Finding the postion of 4 in a 5 long list using static list\n";
 cout << lst.Find(4);
 cout << endl;
 //Use of dyanmic list
 List* lst1 = new List;
 for (int i = 0; i < 101; i++)
   lst1->PutItemH(i);
 cout << "Finding the postion of 9 in a 101 long list using dynamic list\n";
 cout << lst1->Find(9);
 cout << endl;
 */
 delete lst1; //necessary to invoke destructor on dynamic list
 return 0;
}
