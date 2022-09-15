// WALTER GILLIAM COMP SCI 303 ASSIGNMENT 1 DUE 9/20/22
#include "assignment1header.h"
using namespace std;

int main()
{
	int arr[200]; //the size of 200 allows for the file of 100 elements and then the user to add up to 100 more elements to the array
	int arrsize = readFile("input.txt", arr); //calls the readFile function and grabs the number of elements in the given array
	int input;
	string inputstr;
	bool again = true; //allows recursion of the menu when true, allows main to return 


	do
	{
		//used to test, allowed me to read the array after each iteration of the do while loop
		/*
		for (int i = 0; i < 200; i++)
		{
			if (i % 10 == 0)
			{
				cout << endl;
			}
			cout << arr[i] << " ";
		}
		cout << endl << endl;
		//*/
		
		//displays menu to user and accepts the input
		cout << endl << "Select from the following options" << endl
		<< "1: Search the Array for an Integer" << endl
		<< "2: Modify an Element of the Array" << endl
		<< "3: Add an Element to the Array" << endl
		<< "4: Remove an Element from the Array" << endl
		<< "5: Quit" << endl
		<< "(use numbers 1-5 to make your selection)" << endl << endl;

		cin >> inputstr;			
		cout << endl;

		//verifies that user input is an integer
		if (isInt(inputstr) == false)
		{
			cout << "Invalid input, please use only integer values." << endl << endl;
		}
		else
		{
			input = stoi(inputstr);
			switch (input)
			{
				case 1:
				{
					searchArray(arr, arrsize);
					break;
				}
				case 2:
				{
					changeElement(arr, arrsize);
					break;
				}
				case 3:
				{
					newElement(arr, arrsize);
					break;
				}
				case 4:
				{
					removeElement(arr, arrsize);
					break;
				}
				case 5:
				{
					again = false;
					break;
				}
				default:
				{
					cout << "Invaid input. Please try again using a number 1-5." << endl << endl;
					break;
				}
			}
		}
	} while (again);

	return 0;
}

//reads from a file into an arrAy, returns number of elements in array
int::readFile(string filename, int (&arr)[200])
{
	// input file
	ifstream fin("input.txt");

	// throw error if can't open input file
	if (!fin)
	{
		cout << "Error opening input file!";
		system("pause");
		return 0;
	}

	// while there's data in the file, read in a line and add it to the array
	int inputs = 0;

	while (fin.good())
	{
		fin >> arr[inputs];
		inputs++;
	}

	//fill the rest of the excessivly large array with 0s (this will allow a certain degree of maliability of the size of the array)
	for (int i = inputs; i < 200; i++)
	{
		arr[i] = -1;
	}

	// close file
	fin.close();

	// quit without error
	return (inputs);
}

//searches the array for a user input integer
void::searchArray(int (&arr)[200], int size)
{
	int input;
	string inputstr;
	bool found = false;

	//asks for and receives user input
	cout << "What integer would you like to search for?" << endl;
	cin >> inputstr;
	cout << endl;

	//verifies that user input is an integer
	if (isInt(inputstr) == false)
	{
		cout << "Invalid input, please use only integer values." << endl;
		searchArray(arr, size);
	}
	else
	{
		input = stoi(inputstr);
	}

	//uses a linear search to look for the user input value
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == input)
		{
			cout << input << " found at index " << i << "." << endl;
			found = true;
		}
	}
	if (found == false)
	{
		cout << input << " not found in array." << endl;
	}
}

//modifies an element of the array
void::changeElement(int (&arr)[200], int size)
{
	int input1, input2;
	string inputstr1, inputstr2;

	//asks for and receives user input
	cout << "What element would you like to modify?" << endl;
	cout << "Select element 0 through " << (size - 1) << "." << endl;
	cin >> inputstr1;
	cout << endl;

	//verifies that user input is an integer
	if (isInt(inputstr1) == false)
	{
		cout << "Invalid input, please use only integer values." << endl;
		changeElement(arr, size);
	}
	else
	{
		input1 = stoi(inputstr1);
	}

	//verifies that the input element exists on the array
	if (input1 >= size || input1 < 0)
	{
		cout << "No element exists at index " << input1 << "." << endl;
	}
	else
	{
		//asks for and receives user input
		cout << "What would you like to change the element at index " << input1 << " to?" << endl;
		cin >> inputstr2;
		cout << endl;

		//verifies that user input is an integer
		if (isInt(inputstr2) == false)
		{
			cout << "Invalid input, please use only integer values." << endl;
			changeElement(arr, size);
		}
		else
		{
			input2 = stoi(inputstr2);
		}

		//informs the user of the chosen index, as well as the elements previous value and new value
		cout << "Changed element at index " << input1 << " from " << arr[input1] << " to " << input2 << "." << endl;
		arr[input1] = input2;
	}
}

//adds a new element to the array
void::newElement(int (&arr)[200], int &size)
{
	int input;
	string inputstr;

	//asks for and receives user input
	cout << "What is the integer value you would like to add to the array?" << endl;
	cin >> inputstr;
	cout << endl;

	//verifies that user input is an integer
	if (isInt(inputstr) == false)
	{
		cout << "Invalid input, please use only integer values." << endl;
		newElement(arr, size);
	}
	else
	{
		input = stoi(inputstr);
	}

	//informs user of their choice and updates the array size
	arr[size] = input;
	cout << "Added " << input << " to the end of the array at index " << size << "." << endl;
	size++;
}

//removes an existing element from the array
void::removeElement(int (&arr)[200], int &size)
{
	int input;
	string inputstr;

	//asks for and receives user input
	cout << "What element would you like to remove from the array?" << endl;
	cout << "Select element 0 through " << (size - 1) << "." << endl;
	cin >> inputstr;
	cout << endl;

	//verifies that user input is an integer
	if (isInt(inputstr) == false)
	{
		cout << "Invalid input, please use only integer values." << endl;
		removeElement(arr, size);
	}
	else
	{
		input = stoi(inputstr);
	}

	//verifies that user input exists on the array
	if (input > size || input < 0)
	{
		cout << "No element exists at index " << input << "." << endl;
	}
	else
	{
		//removes element by overwriting with the next elemenet until the array is fully iterated
		for (int i = input; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}

		//informs the user of their choice
		cout << "Removed the element at index " << input << " from the array." << endl;
		size--;
	}
}

//checks if string is integer
bool::isInt(string input)
{
	for (unsigned int i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]) == false)
		{
			return false;
		}
	}
	return true;
}