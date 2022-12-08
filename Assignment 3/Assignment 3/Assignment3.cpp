#pragma once
#include "Assignment3.h"
using namespace std;

//make the whole of part 2 a function to do twice, once for a palindrome and once for not

int main()
{
	//Part 1
	queue<int> qTest;				//creates a queue to test the function move_to_rear()

	qTest.push(1);
	qTest.push(2);
	qTest.push(3);
	qTest.push(4);
	qTest.push(5);					//queue should contain 1, 2, 3, 4, 5

	cout << "PART 1" << endl
		<< "Given the queue 12345, the function move_to_rear() changes the queue to ";

	move_to_rear(qTest);			//queue should now contain 2, 3, 4, 5, 1

	for (int i = 0; i < 5; i++)		//will output the queue to confirm above result
	{
		cout << qTest.front();
		qTest.pop();
	}
	cout << "." << endl << endl;

	//Part 2
	cout << "PART 2" << endl;
	Part2();
	Part2();

	//Part 3 and 4 are presented in a .dox uploaded to github
	cout << "PART 3 & 4 can be found in the .dox on github" << endl << endl;
	
	//Part 5
	cout << "PART 5" << endl;
	map<string, string> mTest				//creates map to test and initializes with some states and capitols
	{ { "Nebraska", "Lincoln"}, {"New York", "Albany"}, {"Ohio", "Columbus"}, {"California", "Sacramento"}, {"Massachusetts", "Boston"}, {"Texas", "Austin"} };

	cout << "The map with no changes is as follows:" << endl;
	printMap(mTest);						//print map before making any changes

	mTest["California"] = "Los Angeles";	//changes capitol of California to Los Angeles
	cout << "Updating capitol of California to Los Angeles" << endl << endl;

	cout << "The updated map is as follows:" << endl;
	printMap(mTest);						//print map to ensure changes are made

	findCapByState(mTest);					//allows the user to ask for a state and get the capitol back
	findCapByState(mTest);					//doing this twice for testing purposes
}
