/*
*Investment Banking App
*Author: Garrett McEwen
*Version: 1.0
*Designed for Airgead Banking corp. by Chada Tech
*This file contains the function definitions for the InterestRateCalc.h Class*
*/
#include <iostream>
#include <iomanip>
using namespace std;

#include "InterestRateClac.h"

//default contstructor
InterestRateCalc::InterestRateCalc(double t_openingAmount, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears) {
	m_initialInvestment = t_openingAmount;
	m_depositedAmount = t_monthlyDeposit;
	m_interest = t_annualInterest;
	m_years = t_numberOfYears;
}

//function definition sets opening amount
void InterestRateCalc::setOpeningAmount(double t_openingAmount) {
	m_initialInvestment = t_openingAmount;
}

//function definition gets opening amount
double InterestRateCalc::getOpeningAmount() {
	return m_initialInvestment;
}

//function definition sets monthly deposit amount
void InterestRateCalc::setMonthlyDeposit(double t_monthlyDeposit) {
	m_depositedAmount = t_monthlyDeposit;
}

//function definition gets monthly deposit amount
double InterestRateCalc::getMonthlyDeposit() {
	return m_depositedAmount;
}

//function definition sets the annual interest desired
void InterestRateCalc::setAnnualInterest(double t_annualInterest) {
	m_interest = t_annualInterest;
}

//function definition gets annual interest rate specifed
double InterestRateCalc::getAnnualInterest() {
	return m_interest;
}

//function definition sets number of years
void InterestRateCalc::setNumberOfYears(int t_numberOfYears) {
	m_years = t_numberOfYears;
}

//function definition gets number of years
int InterestRateCalc::getNumberOfYears() {
	return m_years;
}

//function definition calculates and displays investment without monthly deposits
void InterestRateCalc::withoutMonthlyDeposits() {
	double totalAmount;
	double initialAmount;
	double yearlyEarnedInterest;
	double earnedInterest = 0;
	double closingBalance = 0;
	int i;
	int j;

	for (i = 0; i < getNumberOfYears(); ++i) {
		initialAmount = getOpeningAmount();
		yearlyEarnedInterest = 0;
		for (j = 0; j < 12; ++j) {
			totalAmount = initialAmount;
			yearlyEarnedInterest += totalAmount * (getAnnualInterest() / 100 / 12);
			earnedInterest = totalAmount * (getAnnualInterest() / 100 / 12);
			closingBalance = totalAmount + earnedInterest;
			initialAmount = closingBalance;
		}
		cout << fixed << setprecision(2) << i + 1 << "          " << "$" << closingBalance << "\t\t  " << "$" << yearlyEarnedInterest << endl;
		setOpeningAmount(closingBalance);
	}
}

//function definition calculates and displays investment with monthly deposits
void InterestRateCalc::withMonthlyDeposits() {
	double totalAmount;
	double initialAmount;
	double yearlyEarnedInterest;
	double earnedInterest = 0;
	double closingBalance = 0;
	int i;
	int j;

	if (getMonthlyDeposit() == 0) {
		closingBalance = 0;
		yearlyEarnedInterest = 0;
		for (i = 0; i < getNumberOfYears(); ++i) {
			cout << fixed << setprecision(2) << i + 1 << "          " << "$" << closingBalance << "\t\t  " << "$" << yearlyEarnedInterest << endl;
		}
	}
	
	else {
		initialAmount = getOpeningAmount();
		for (i = 0; i < getNumberOfYears(); ++i) {
			initialAmount = getOpeningAmount();
			yearlyEarnedInterest = 0;
			for (j = 0; j < 12; ++j) {
				totalAmount = initialAmount + getMonthlyDeposit();
				yearlyEarnedInterest += totalAmount * (getAnnualInterest() / 100 / 12);
				earnedInterest = totalAmount * (getAnnualInterest() / 100 / 12);
				closingBalance = totalAmount + earnedInterest;
				initialAmount = closingBalance;
			}
			cout << fixed << setprecision(2) << i + 1 << "          " << "$" << closingBalance << "\t\t  " << "$" << yearlyEarnedInterest << endl;
			setOpeningAmount(closingBalance);
		}
	}
}

//function definition displays user interface one
void InterestRateCalc::bannerDisplay1() {
	cout << " Airgead Banking Investment App" << endl;
	cout << setfill('*') << setw(33) << " " << endl;
	cout << setfill('*') << setw(33) << " " << endl;
}

//function definition displays user interface two
void InterestRateCalc::bannerDisplay2() {
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(58) << " " << endl;
	cout << "Year" << setfill(' ') << setw(7) << " ";
	cout << "Year End Balance" << setfill(' ') << setw(7) << " ";
	cout << "Year End Earned Interest" << setfill(' ') << setw(7) << " " << endl;
	cout << setfill('-') << setw(58) << " " << endl;
}

//function definition displays user interface three
void InterestRateCalc::bannerDisplay3() {
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setfill('=') << setw(58) << " " << endl;
	cout << "Year" << setfill(' ') << setw(7) << " ";
	cout << "Year End Balance" << setfill(' ') << setw(7) << " ";
	cout << "Year End Earned Interest" << setfill(' ') << setw(7) << " " << endl;
	cout << setfill('-') << setw(58) << " " << endl;
}