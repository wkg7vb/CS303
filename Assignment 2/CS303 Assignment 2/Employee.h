#pragma once
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
using namespace std;


class Employee
{
	protected:
		double w_pay;
		int v_days;
		double hc_contributions;
	public:
		virtual double weeklyPay() = 0;
		virtual int vacationDays() = 0;
		virtual int HCContributions() = 0;
};

class Professional : public Employee 
{
	private:
		double m_salary;

	public:
		Professional(double msal) { m_salary = msal; };

		double weeklyPay() { w_pay = (m_salary / 30) * 7; return w_pay; };
		int vacationDays() { v_days = 15; return v_days; };
		int HCContributions() { hc_contributions = 5; return hc_contributions; };

		void printData()
		{
			cout << " This worker is set to make " << weeklyPay() << " per week," << endl
				<< " get " << vacationDays() << " days of vacation per year," << endl
				<< " and is expected to contribute " << HCContributions() << " percent of their wages to their health insurance." << endl;
		}
		
		void setSalary(double msal) { m_salary = msal; };
		double getSalary() { return m_salary; };
};

class Nonprofessional : public Employee 
{
	private:
		double w_hours;
		double h_wage;
		int hc_choice;

	public:
		Nonprofessional(double hours, double wage, double choice) { w_hours = hours; h_wage = wage; hc_choice = choice; };

		double weeklyPay()
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
		int vacationDays()
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
				default:
				{
					break;
				}
			}
			return v_days;
		};
		int HCContributions() { hc_contributions = hc_choice; return hc_contributions; };

		void printData()
		{
			cout << " This worker is set to make " << weeklyPay() << " per week," << endl
				<< " get " << vacationDays() << " days of vacation per year," << endl
				<< " and is expected to contribute " << HCContributions() << " percent of their wages to their health insurance." << endl;
		}

		void set_hours(double hrs) { w_hours = hrs; }
		double get_hours() { return w_hours; }
		void set_wage(double wage) { h_wage = wage; }
		double get_wage() { return h_wage; }
		void set_choice(double choice) { hc_choice = choice; }
		double get_choice() { return hc_choice; }
};

#endif