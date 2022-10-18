#include "Employee.h"
using namespace std;

int main()
{
	Professional Worker1 = Professional(10000);
	Nonprofessional Worker2 = Nonprofessional(45, 25, 4);

	Worker1.printData();
	Worker2.printData();

	return 0;
}