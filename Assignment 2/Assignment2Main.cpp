#include "Employee.h"
using namespace std;

int main()
{
	Professional Worker1 = Professional(10000); // this can be edited, it is the monthly salary of the professional employee
	Nonprofessional Worker2 = Nonprofessional(45, 25, 4); // this can be edited, it is the hours, wage, and choice in contribution of the nonprofessional employee

	//prints the data from each employee so that you can see the changes in parameters result in different member data.
	Worker1.printData();
	Worker2.printData();

	return 0;
}