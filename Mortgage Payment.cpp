// Mortgage Payment.cpp 
// Levi Seibert
// CS 318
// This program calculates the monthly and total payments of a given loan.

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Open the output file
ofstream output("Mortgage Output.txt");

//Define the class Morgage
class Mortgage
{
public:
	//Constructor
	Mortgage();

	//Setter methods
	void setLoan(float l);
	void setRate(float r);
	void setYears(int y);

	//Getter methods
	float getMonthly();
	float getTotalPaid();

private:
	float payment;
	float loan;
	float rate;
	int years;
};


Mortgage::Mortgage()
{
	payment = 0.0;
	loan = 0.0;
	rate = 0.0;
	years = 0.0;
}

//Set the loan data member
void Mortgage::setLoan(float l)
{
	//Input validation
	if (l >= 0)
		loan = l;
	else
	{
		cout << "Invalid input.  Now exiting...";
		exit(EXIT_FAILURE);
	}
}

//Set the rate data member
void Mortgage::setRate(float r)
{
	//Input validation
	if (r >= 0)
		rate = r;
	else
	{
		cout << "Invalid input.  Now exiting...";
		exit(EXIT_FAILURE);
	}
}

//Set the years data member
void Mortgage::setYears(int y)
{
	//Input validation
	if (y >= 0)
		years = y;
	else
	{
		cout << "Invalid input.  Now exiting...";
		exit(EXIT_FAILURE);
	}
}

//Return the monthly payment
float Mortgage::getMonthly()
{
	return (loan * (rate / 12) * pow((1 + (rate / 12)), (12 * years))) / ((pow((1 + (rate / 12)), (12 * years))) - 1);
}

//Return the payment total
float Mortgage::getTotalPaid()
{
	return (loan * (rate / 12) * pow((1 + (rate / 12)), (12 * years))) / ((pow((1 + (rate / 12)), (12 * years))) - 1) * years * 12;
}

int main()
{
	//Create an instance of the Mortgage class and declare variables
	Mortgage home;
	float loanAmount, interestRate;
	int loanYears;

	//Get input from user
	cout << "Enter the loan amount: ";
	cin >> loanAmount;

	cout << "Enter the interest rate: ";
	cin >> interestRate;
	interestRate /= 100;

	cout << "Enter the length of the loan in years: ";
	cin >> loanYears;

	//Set object's data members
	home.setLoan(loanAmount);
	home.setRate(interestRate);
	home.setYears(loanYears);

	//Output results from member methods
	output << fixed << showpoint << setprecision(2) << "The monthly payment amount is: $" <<  home.getMonthly() << endl;
	output << "The total amount paid at the end of the loan period will be: $" << home.getTotalPaid() << endl;

	//Close the file
	output.close();
	return 0;
}
