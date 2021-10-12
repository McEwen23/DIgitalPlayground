/*
*Investment Banking App
*Author: Garrett McEwen
*Version: 1.0
*Designed for Airgead Banking corp. by Chada Tech
*This file constructs and contains the function declarations for the InterestRateCalc.h Class*
*/
#pragma once
#ifndef INTERESTRATECALC_H
#define INTERESTRATECALC_H

class InterestRateCalc {
	public:
		//default constructor decalration
		InterestRateCalc(double t_openingAmount, double t_monthlyDeposit, double t_annualInterest, int t_numberOfYears);
	
		//InterestRateCalc class funciton declarations
		void setOpeningAmount(double t_openingAmount);
		double getOpeningAmount();
	
		void setMonthlyDeposit(double t_monthlyDeposit);
		double getMonthlyDeposit();
	
		void setAnnualInterest(double t_annualInterest);
		double getAnnualInterest();
	
		void setNumberOfYears(int t_numberOfYears);
		int getNumberOfYears();

		void withoutMonthlyDeposits();

		void withMonthlyDeposits();

		static void bannerDisplay1();

		static void bannerDisplay2();

		static void bannerDisplay3();
	
	private:
		//private member variables
		double m_initialInvestment;
		double m_depositedAmount;
		double m_interest;
		int m_years;

		

};

#endif // !INTERESTRATECALC_H
