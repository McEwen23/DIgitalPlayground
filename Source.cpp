/*
*Investment Banking App
Author: Garrett McEwen
*Version: 1.0
*Designed for Airgead Banking corp. by Chada Tech.
*This Program Calculates Investment returns over a period of time.
*/
#include <iostream>
#include <iomanip>
#include <cctype>              //library used for isaslpha function
#include <stdexcept>           //library used for error handling and exceptions
#include "InterestRateClac.h"  //headerfile for InterestRateCalc class
using namespace std;

int main() {
	//variable declarations
	double openingAmount;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;
	char quitCmd = 'c';

	//drives main program
	while (quitCmd != 'q') {

		InterestRateCalc::bannerDisplay1(); //static function displays first user interface

		//validates user input before creating an instance of InterestRateCalc
		try {
			cout << "Initial Investment Amount: $";
			cin >> openingAmount;


			if (openingAmount < 0 || openingAmount == isalpha(openingAmount)) {
				throw runtime_error("Invalid Opening Amount. Amount Must Be A Positve Real Number.");
				cout << endl;
			}

			cout << "Monthly Deposit: $";
			cin >> monthlyDeposit;

			if (monthlyDeposit < 0 || monthlyDeposit == isalpha(monthlyDeposit)) {
				throw runtime_error("Invalid Monthly Deposit Amount. Amount Must Be A Positive Real Number.");
				cout << endl;
			}

			cout << "Annual Interest Rate: (%)";
			cin >> annualInterest;

			if (annualInterest == isalpha(annualInterest)) {
				throw runtime_error("Invalid Input. Interest Rate Must Be A Integer.");
				cout << endl;
			}

			cout << "Number of Years: ";
			cin >> numberOfYears;

			if (numberOfYears < 1 || numberOfYears == isalpha(numberOfYears)) {
				throw runtime_error("Invalid Input. Year Must Be A Positve Whole Number. ");
				cout << endl;
			}

			//instantiates an instance of the InterestRateCalc class
			InterestRateCalc investment1(openingAmount, monthlyDeposit, annualInterest, numberOfYears);

			//static function displays second user interface
			InterestRateCalc::bannerDisplay2();

			//calculates and displays user input without monthly deposits
			investment1.withoutMonthlyDeposits();

			//static function displays third user interface
			InterestRateCalc::bannerDisplay3();

			//calculates and user input with monthly deposits
			investment1.withMonthlyDeposits();
		}
		
		//catch block handles runtime errors and termintates program
		catch (runtime_error& excpt) {
			cout << endl;
			cout << excpt.what() << endl;
			cout << "Cannot Compute Investment. Try Again." << endl;
			break;
		}
		
		//prompts user to calculate another investment or quit program
		cout << endl << "Would You Like To Calculate Another Investment? Type 'q' to quit Or Enter Any Key To Continue.. ";
		cin >> quitCmd;
		system("cls");
	}

	return 0;
}