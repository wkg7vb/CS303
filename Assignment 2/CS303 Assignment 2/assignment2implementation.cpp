#include "assignment2implementation.h"
#include "iostream"
using namespace std;

void printData(Professional Worker)
{
	cout << " This worker is set to make " << Worker.getPay() << "," << endl
		<< " get " << Worker.getDays() << " days of vacation," << endl
		<< " and is expected to contribute " << Worker.getHCC() << " of their wage to their health insurance." << endl;
}

void printData(Nonprofessional Worker)
{
	cout << " This worker is set to make " << Worker.getPay() << "," << endl
		<< " get " << Worker.getDays() << " days of vacation," << endl
		<< " and is expected to contribute " << Worker.getHCC() << " of their wage to their health insurance." << endl;
}