/*
Name: Dominic Orsi
Class: CPSC 122, Section 1
Date; January 29, 2021
Assignment: Project 4
Description: Takes in user input from the command line on how many prime numbers they want displyed across how many
colums and then outputs that to an outout file.
isPrime Function: My function is one that checks for corner cases (1 and 3) first and if the number input is below or equal to them it says that that number is not a prime. Next it checks for the modulos of two and three and if the number intput into isPrime returns a zero on either of those it says that that number is not prime. Next it checks for five in a for loop and adds 6 to i each time it executes. Next an if statement is used to take the num being tested for prime and then moduloed against i to see if it is equal to 0. The if statement also checks for the num and modulo of i + two to see if that equals 0. If the number passes all those tests it comes out as true to being prime.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isPrime(int num);

int main(int argc, char* argv[])
{
	int primeNumbers = 0;
	int columsDisplayed = 0;
	int primesGotten = 0;
	int i = 2;
	int k = 0;
	
	ofstream fout;
	
	fout.open(argv[1]);
	
	// If statement to check how many arguments there are in the command line
	// If not equal to 2 arguments it throws up an error
	if(argc != 2)
    {
     cout << "Requires 1 arguments, an output file\n";
     return(EXIT_FAILURE); 
    }
    
	// Asking to command line for how many prime numbers and colums wanted by user
	cout << "How many prime numbers do you want to be generated?" << endl;
	cin >> primeNumbers;
	cout << "How many colums do you want the prime numbers displayed across?" << endl;
	cin >> columsDisplayed;
	
	// While loop check how many primes we have compared to how many user wants
	while(primesGotten != primeNumbers) 
	{
		// If statment to add one to primesGotten if isPrime function is true
		if(isPrime(i) == true)
		{
			primesGotten++;
			k++;
			
			// If statement to check on colums displayed and then put the prime numbers
			// into those colums
			if(k == columsDisplayed) 
			{
				fout << setw(5) << i << endl;
				k = 0;
			}
			else
			{
				fout << setw(5) << i;
			}
		}
		i++;
	}
	
	return 0;
}
	
/*
Description: Determines whether input integer is prime
Input: integer whose primality is to be judged
Returns: true if num is prime, false otherwise
*/
bool isPrime(int num) 
{
	int i = 0;
	
	for(i = 2; i < num; i++)
	{
		if(num % i == 0)
		{
			return false;
		}
	}
	
	return true;
}

