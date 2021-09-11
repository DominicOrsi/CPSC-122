/*
Name: Dominic Orsi
Class: CPSC 122 Section 1
Date: Feburary 13, 2021
Assignment: Project 6
Description: Generates an alpha and beta num and then encrypts and decrypts a file read in using the alphine cipher.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void keyGen (string keyFile);
char encrypt (char ch, int alpha, int beta);
char decrypt (char ch, int alpha, int beta, int MI[]);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);
void fileOpen(fstream& file, string name, char mode);

const int p = 650;

int main(int argc, char* argv[])
{
  int mode = 0;
  
  mode = (atoi(argv[1]));
  
  // If statement on mode
  if(mode == 0)
  {
    fstream fout;
    
    // Function call to keyGen
    keyGen(argv[2]);
    
    fout.close();
  }
  else if(mode == 1 || mode == 2)
  {
  	// Function call to fileControl
    fileControl(argv[2], argv[3], argv[4], mode);
  }
  
  return 0;
}

/*
Description: Randomly generates and stores alpha and beta values.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11,17,19,25}
The beta value is randomly drawn from the range: [1..25]  
Output: alpha and beta values on subsequent lines of keyFile
*/
void keyGen (string keyFile)
{
  int alphaNum = 0;
  int betaNum = 0;
  int i = 0;
  int array [8] = {1, 3, 5, 7, 11, 17, 19, 25};
  
  fstream fout;
  
  // Function call to fileOpen
  fileOpen(fout, keyFile, 'w');
  
  srand(time(0));
  
  i = (rand() % 8);
  betaNum = (rand() % (25 - 1 + 1)) + 1;
  alphaNum = array [i];
  fout << alphaNum << endl << betaNum;
}

/*
Description: Encrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values
Returns: encrypted version of ch
*/
char encrypt (char ch, int alpha, int beta)
{
  // If statement to avoid ascii characters outside of uppercase A-Z
  if(ch >= 'A' && ch <= 'Z')
  {
    ch -= 65;
    ch = ((alpha * ch) + beta) % 26;
    ch += 65;
  }
  
  return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the affine cipher
Input: upper case alphabetic character, valid alpha and beta values. Dictionary of multiplicative inverse values mod 26
Returns: decrypted version of input
*/
char decrypt (char ch, int alpha, int beta, int MI[])
{
  // If statement to avoid ascii characters outside of uppercase A-Z
  if(ch >= 'A' && ch <= 'Z')
  {
    ch -= 65;
    ch = ((MI[alpha - 1]) * ch - (MI[alpha - 1] * beta) + p) % 26;
    ch += 65;
  }
  
  return ch;
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
  int i = 0;
  int alphaNum = 0;
  int betaNum = 0;
  int dictionary [26] = {1, 0, 9, 0, 21, 0, 15, 0, 0, 0, 19, 0, 0, 0, 0, 0, 23, 0, 11, 0, 0, 0, 0, 0, 25, 0};
  char readingIn = ' ';
  char encryptChar = ' ';
  char decryptChar = ' ';
  string temp = "";
  
  fstream keyIn;
  fstream fin;
  fstream fout;
  
  // Function call to fileOpen
  fileOpen(keyIn, keyFile, 'r');
  fileOpen(fin, fileIn, 'r');
  fileOpen(fout, fileOut, 'w');
  
  // Reading in of alpha and beta numbers
  keyIn >> alphaNum;
  keyIn >> betaNum;
  
  // Getline to get string in file
  getline(fin, temp);
  
  // If statement to execute encrypt or decrypt functions
  if(mode == 1)
  {
  
    for(i = 0; i < temp.length(); i++)
    {
      readingIn = temp[i];
      
      // If statement to make sure readingIn is uppercase
      // then make it uppercase if it is not
      if(isalpha(readingIn))
      {
        readingIn = toupper(readingIn);
      }
      
      encryptChar = encrypt(readingIn, alphaNum, betaNum);
      fout << encryptChar;
    }
  }
  else if(mode == 2)
  {

   for(i = 0; i < temp.length(); i++)
   {
     readingIn = temp[i];
      
     // If statement to make sure readingIn is uppercase
     // then make it uppercase if it is not
     if(isalpha(readingIn))
     {
       readingIn = toupper(readingIn);
     }
      
     decryptChar = decrypt(readingIn, alphaNum, betaNum, dictionary);
     fout << decryptChar;
   }
  }
  
  keyIn.close();
  fin.close();
  fout.close();
}

/*
Description: function opens a file
Input: file stream object reference, name of the file, mode of open
Output: input file name is opened. 
*/
void fileOpen(fstream& file, string name, char mode)
{
  string fileType;

 if (mode == 'r')
   fileType = "input";
 if (mode == 'w')
   fileType = "output";

 if (mode == 'r')
   file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
   file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
   cout << "Error opening " << fileType << " file" << endl; 
   exit(EXIT_FAILURE);
 }
}
