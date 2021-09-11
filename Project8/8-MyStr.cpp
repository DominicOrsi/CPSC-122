#include <iostream>
using namespace std;

#include "8-MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
  int i = 0;
  while(strIn[i] != '\0')
    i++;
  length = i;
  int l = length + 1;
  str = new char[l];
  for(i = 0; i < l; i++)
    str[i] = strIn[i];
}

//Destructor function
//once you get the constructor working, remove the comments.
MyString::~MyString()
{
  delete []str; 
}

void MyString::myDisplay()
{
  for(int i = 0; i < length; i++)
    cout << str[i];
  cout << endl;
}

void MyString::myStrcpy(char const* strIn)
{
  int i = 0;
  while(strIn[i] != '\0')
    i++;
  length = i;
  int l = length + 1;
  str = new char[l];
  for(i = 0; i < l; i++)
    str[i] = strIn[i];
}

int MyString::myStrlen()
{
  int i = 0;
  while(str[i] != '\0')
  {
    i++;
  }
  return i;
}

bool MyString::isEqual(char const* strIn)
{
  int i = 0, count = 0;;
  for(i = 0; i < length; i++)
    if(str[i] == strIn[i])
      count++;
  if(count == length)
    return true;
  else
    return false;
}

int MyString::find(char const* strIn)
{
  int idx = -1;
  int i = 0;
  for(i = 0; i < length; i++)
    if(strIn[i] == str[i])
    {
      idx = i;
      break;
    }
  if(isSub(strIn, idx) == true)
    return idx;
  else
    return -1;
}

void MyString::concat(char const* strIn)
{
  int i = 0;
  int length2 = length;
  while(strIn[i] != '\0')
    i++;
  length += i;
  char* con = new char[length + 1];
  int idx = 0;
  int length3 = i;
  i = 0;
  while( i < length2)
  {
    con[idx] = str[i];
    idx++;
    i++;
  }
  i = 0;
  while(i < length3)
  {
    con[idx] = strIn[i];
    idx++;
    i++;
  }
  str = new char[length + 1];
  i = 0;
  while( i < length)
  {
    str[i] = con[i];
    i++;
  }
  str[length] = '\0';
}

bool MyString::isSub(char const* strIn, int idx)
{
  int i = 0;
  int count = 0;
  while(strIn[i] != '\0')
    i++;
  int length2 = i;
  i = 0;
  while(i < length2)
  {
    if(strIn[i] == str[idx])
      count++;
    i++;
    idx++;
  }
  if(count == length2)
    return true;
  else
    return false;
}
