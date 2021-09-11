/*
Name: Paul De Palma
Class: CPSC 122, Section 1
Date Submitted: February 18, 2021
Assignment: N/A 
Description: Program illustrates using class MyString 
*/

#include "8-MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

 /*
 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay
 
 //Test if myStrcpy
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrcpy*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 str1.myStrcpy("Hola");
 cout << "output should be the copied string input (Hello)" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  myStrcpy*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 str2->myStrcpy("Adios");
 cout << "output should be the copied string input (Goodbye)" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy
 
 //Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the length of the command line input" << endl;
 cout << str1.myStrlen();
 cout << endl;
 cout << "*****Test 2  myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the length of the command line input" << endl;
 cout << str2->myStrlen();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen
 
 //Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 1 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "output should be 1 (true) if command input is equal to \"hola\" otherwise outputs 0 (false)" << endl;
 cout << str1.isEqual("hola");
 cout << endl;
 cout << "*****Test 2  isEqual*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be 1 (true) if command input is equal to \"bananna bread is the best bread\" otherwise outputs 0 (false)" << endl;
 cout << str2->isEqual("bananna bread is the best bread");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual
 */
 //Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 1 find*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the index where the argument string (xyz) starts if the whole string appears in str1 otherwise outputs -1" << endl;
 cout << str1.find("xyz");
 cout << endl;
 cout << "*****Test 2  find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the index where the argument string (abc) starts if the whole string appears in str2 otherwise outputs -1" << endl;
 cout << str2->find("abc");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find
 /*
 //Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 1 concat*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input" << endl;
 str1.myDisplay();
 str1.concat("Fin");
 cout << "output should be the command line input with \"Fin\" concatenated to it" << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2  concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input" << endl;
 str2->myDisplay();
 str2->concat("flop");
 cout << "output should be the command line input with \"flop\" concatenated to it" << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat
 */
 delete str2;
 return 0;  
}
   
  
