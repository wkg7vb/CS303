#pragma once
#include "Assignment3.h"
using namespace std;

//Part 1
void move_to_rear(queue<int>& qName)
{
	qName.push(qName.front());	//places the front element to the rear.
	qName.pop();				//removes front element
}

//Part 2
bool checkPalindrome(string toCheck)
{
	int length = toCheck.length();									//finds the length of the input string

	if (length == 1 || length == 0)									//checks if the length is 1 or 0 as "x" or "" would be a palindrome
	{
		return true;
	}
	else if (toCheck[0] == toCheck[length - 1])							//compares first and last elements of string
	{
		return checkPalindrome(toCheck.substr(1, length - 2));		//recursivly calls with first and last elements removed
	} 
	else															//if the first and last don't match, it cannot be a palindrome.
	{
		return false;
	}
}

void Part2()	//made a serparate function for this so that I could repeat it to test without repeating code
{
	string pTest;
	string result = " ";

	cout << "Input a string to test if it is a palindrome." << endl;							//requests and receives user input
	cin >> pTest;

	if (!checkPalindrome(pTest))																//tests using created method
	{
		result = " not ";																		//adds "not" to the output string if not a palindrome
	}

	cout << "Your word, '" << pTest << "', is" << result << "a palindrome." << endl << endl;		//outputs results

}

//Part 3 and 4 are presented in a .dox uploaded to github

//Part 5
void printMap(map<string, string> mName)
{
	map<string, string>::iterator iter;

	for (iter = mName.begin(); iter != mName.end(); iter++)
	{
		cout << iter -> first << ", " << iter -> second << endl;
	}
	cout << endl;
}

void findCapByState(map<string, string> mName)
{
	string sName;

	cout << "Input state name." << endl;
	cin >> sName;

	cout << "The capitol of " << sName << " is " << mName[sName] << endl << endl;
}