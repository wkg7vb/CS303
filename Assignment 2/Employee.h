#pragma once
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
using namespace std;

//creation of abtsratc class employee
class Employee
{
	protected: // want derived classes to be able to access member data
		double w_pay;
		int v_days;
		int hc_contributions;
	public: //pure virtual functions to be overriden in derived classes
		virtual double weeklyPay() = 0;
		virtual int vacationDays() = 0;
		virtual int HCContributions() = 0;

		//setters and getters, although not used
		void setPay(double pay) { w_pay = pay; };
		double getPay() { return w_pay; };
		void setDays(double days) { v_days = days; };
		int getDays() { return v_days; };
		void setHCC(double hcc) { hc_contributions = hcc; };
		int getHCC() { return hc_contributions; };
};

//creation of derived class professional
class Professional : public Employee 
{
	private: //member data exclusive to this derived class
		double m_salary;

	public:
		Professional(double msal) { m_salary = msal; }; //constructor

		double weeklyPay() { w_pay = (m_salary / 30) * 7; return w_pay; }; //calcualtions based on 30 day month and 7 day week
		int vacationDays() { v_days = 15; return v_days; }; //always 15 days for this class
		int HCContributions() { hc_contributions = 5; return hc_contributions; }; //always 5% for this class

		void printData() //prints the relevant data using cout
		{
			cout << " This worker is set to make " << weeklyPay() << " per week," << endl
				<< " get " << vacationDays() << " days of vacation per year," << endl
				<< " and is expected to contribute " << HCContributions() << " percent of their wages to their health insurance." << endl;
		}
		
		//getter and setters for private data, even though not used.
		void setSalary(double msal) { m_salary = msal; };
		double getSalary() { return m_salary; };
};

class Nonprofessional : public Employee 
{
	private: //member data exclusive to this derived class
		double w_hours;
		double h_wage;
		int hc_choice;

	public:
		Nonprofessional(double hours, double wage, double choice) { w_hours = hours; h_wage = wage; hc_choice = choice; }; //constructor

		double weeklyPay() //calculates pay as hours * wage, ignoring negative hours, and calculating overtime
		{
			if (w_hours < 0)
			{
				w_pay = 0;
			}
			if (w_hours < 40)
			{
				w_pay = w_hours * h_wage;
			}
			else if (w_hours > 40)
			{
				w_pay = (40 * w_hours) + ((w_hours - 40) * (h_wage * 1.5));
			}
			return w_pay;
		};
		int vacationDays() // casts hours as an int to do integer division, for every 10 hours worked per week, you get 2 additional vacation days with a starting amount of 2
		{
			switch (int(w_hours) / 10)
			{
				case 0:
				{
					v_days = 2;
					break;
				}
				case 1:
				{
					v_days = 4;
					break;
				}
				case 2:
				{
					v_days = 6;
					break;
				}
				case 3:
				{
					v_days = 8;
					break;
				}
				case 4:
				{
					v_days = 10;
					break;
				}
				case 5:
				{
					v_days = 12;
					break;
				}
				default: // this case should never be triggered but if it is, someone working less than 0 or more than 60 hours will get no vacation, they either don't work enough or are too vital
				{
					v_days = 0;
					break;
				}
			}
			return v_days;
		};
		int HCContributions() { hc_contributions = hc_choice; return hc_contributions; }; //the employee can choose between 0 and 5 percent.

		void printData() //prints the relevant data using cout
		{
			cout << " This worker is set to make " << weeklyPay() << " per week," << endl
				<< " get " << vacationDays() << " days of vacation per year," << endl
				<< " and is expected to contribute " << HCContributions() << " percent of their wages to their health insurance." << endl;
		}

		//setters and getters, although not used.
		void set_hours(double hrs) { w_hours = hrs; }
		double get_hours() { return w_hours; }
		void set_wage(double wage) { h_wage = wage; }
		double get_wage() { return h_wage; }
		void set_choice(double choice) { hc_choice = choice; }
		double get_choice() { return hc_choice; }
};

#endif