/*
Name: Dominic Orsi
Class: CPSC 122 Section 1
Date: Feburary 20, 2021
Assignment: Project 7
Description: Does the transposition cipher but without using a 2d array. Uses two single arrays instead
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void keyGen (string keyFile);
void fileControl (string keyFile, string fileIn, string fileOut, int mode);
char transform(char ch, int encDec[]);
void selection_sort(int enc[], int dec[], int length);
int find_small(int start, int arr[], int length);
void swap(int pos, int idx_small, int arr[]);
void fileOpen(fstream& file, string name, char mode);

const int ALPHMAX = 26;

int main(int argc, char* argv[])
{
  int mode = 0;
  
  mode = (atoi(argv[1]));
  
  // If statement on mode
  if(mode == 0)
  {
    // Function call to keyGen
    keyGen(argv[2]);
    
    //fout.close();
  }
  else if(mode == 1 || mode == 2)
  {
  	// Function call to fileControl
    fileControl(argv[2], argv[3], argv[4], mode);
  }
  
  return 0;
}

/*
Description: Opens key file for writing.  Generates and stores encrypt and decrypt keys in the key file.   This can be stored any way that you like as long as two arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys
*/
void keyGen (string keyFile)
{
  bool validate[ALPHMAX];
  int key[ALPHMAX];
  int dec[ALPHMAX];
  int i = 0;
  int randNum = 0;
  
  srand(time(0));
  
  // For loop to set
  for(i = 0; i < ALPHMAX; i++)
  {
    validate[i] = false;
  }
  
  // For loop to go through key array
  for(i = 0; i < ALPHMAX; i++)
  {
    // While loop to make randNum always get a new number
    while(true)
    {
      randNum = rand() % ALPHMAX;
      
      // If statement to check if validate at randNum is true or flase. Then assigns a value to key at i if validate is false
      if(validate[randNum] == false)
      {
        key[i] = randNum;
        validate[randNum] = true;
        break;
      }
    }
  }
  
  fstream fout;
  
  // Call to function fileOpen to opne keyFile
  fileOpen(fout, keyFile, 'w');
  
  // For loop to print key array to keyFile
  for(i = 0; i < ALPHMAX; i++)
  {
  	fout << key[i] << endl;
  }
  fout << "\n";
  
  // For loop to write i to dec array
  for(i = 0; i < ALPHMAX; i++)
  {
    dec[i] = i;
  }
  // Call to function selection_sort
  selection_sort(key, dec, ALPHMAX);
  
  // For loop to print dec array to keyFile
  for(i = 0; i < ALPHMAX; i++)
  {
    fout << dec[i] << endl;
  }
  
  fout.close();
}

/*
Description: Processes files, invokes function to encrypt/decrypt characters
1. Reads key file. Constructs a two arrays, one for encryption, one for decryption.
2. Closes key file
2. Opens the character input file.  This could be plain text or cipher text.
3. Opens the character output file  This could be plain text or cipher text.
4. Reads the input file a character at a time.  Passes transform (see below) the character to be encrypted/decrypted and a reference to  the encrypt or decrypt array, depending on the mode.
5. Writes a character (encrypted/decrypted/passed over) to the output file.
6. Close the input file and output file
Output: writes a character to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
  int i = 0;
  int enc[ALPHMAX];
  int dec[ALPHMAX];
  char ch = ' ';
  char charTransformed = ' ';
  string fileInString = "";
  
  fstream keyIn;
  fstream fin;
  fstream fout;
  
  // Read in plain text file to then send each char to transform function
  // The fout it to an encrypted text file
  
  fileOpen(keyIn, keyFile, 'r');
  fileOpen(fin, fileIn, 'r');
  fileOpen(fout, fileOut, 'w');
  
  // For loop to read in keyFile and put those ints into an array
  for(i = 0; i < ALPHMAX; i++)
  {
    keyIn >> enc[i];
    //cout << encDec[i];
  }
  
  // For loop to read in keyFile to put into dec array
  for(i = 0; i < ALPHMAX; i++)
  {
    keyIn >> dec[i];
  }
  
  if(mode == 1)
  {
    getline(fin, fileInString);
  
    // For loop to read each char in the string in
    for(i = 0; i < fileInString.length(); i++)
    {
      ch = fileInString[i];
      ch = toupper(ch);
      
      //
      charTransformed = transform(ch, enc);
      fout << charTransformed;
    }
  }
  else if(mode == 2)
  {
    getline(fin, fileInString);
  
    // For loop to read each char in the string in
    for(i = 0; i < fileInString.length(); i++)
    {
      ch = fileInString[i];
      ch = toupper(ch);
      
      // 
      charTransformed = transform(ch, dec);
      fout << charTransformed;
    }
  }
  
}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[])
{
  int charInt = 0;
  int charEncDec = 0;
  
  // If statement to transform only uppercase alphabetic charcters
  if(ch >= 'A' && ch <= 'Z')
  {
    charInt = ch - 65;
    charEncDec = encDec[charInt];
    ch =  charEncDec + 65;
  }
  return ch;
}

/*
Description: outer, control loop for selection sort  
Input: array of integers to be sorted along with its length
Output: array is sorted at the end of function
*/
void selection_sort(int enc[], int dec[], int length)
{
 int start = 0;
 int idx_small; 

 /*There are two ways of thinking about the outer loop
   1) we know we have to make N-1 passes through the array.  Think of this as moving
      horizontally in the example shown on the board. Though this requires redundant
      code, I think it's clearer
   2) we know we are finished when we have compared
      1st to 2nd
      2nd to 3rd
          ...
      next-to-last to last 
      There are N-1 such comparisons
   These are actually the same thing, of course
 */
  while(start < length - 1 ) 
  {
    int idx_small = find_small(start, enc, length);
    swap(start,idx_small,enc);
    swap(start,idx_small,dec);
    start++;
  }
}

/*
Description: linear search through an array looking for smallest element
Input: position to start search, array, length of array
Output: returns smallest element in the array
*/
int find_small(int start, int arr[], int length)
{
  int idx_small = start;  //candidate smallest
  int next = start + 1;    //start searching here
  while(next < length)         
  {
    if (arr[next] < arr[idx_small]) //we've found a new smallest integer
     idx_small = next;
    next++;                        //look at the next position whether or not
                                //we've found a new smallest 
  }
  return idx_small;
}


/*
Description: swaps the contents of two posiitons in an array 
Input: position whose contents is swapped with smallest,  position of smallest, array 
Output: returns smallest element in the array
*/
void swap(int pos, int idx_small, int arr[])
{
  int tmp = arr[pos];
  arr[pos] = arr[idx_small];
  arr[idx_small] = tmp;
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
