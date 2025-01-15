#pragma once
#include <iostream>
#include <string>
#include "Interest.h"
#include "BasicProbabilityFunctions.h"
#include "bonds.h"


using namespace std;
void runZeroCouponBond()
{
	double faceValue;
	double rate;
	double Time;
	double maturity;
	cout << "Enter the face value of the bond: ";
	cin >> faceValue;
	cout << "Enter the rate of the bond: ";
	cin >> rate;
	cout << "Enter the time of the bond: ";
	cin >> Time;
	cout << "Enter the maturity of the bond: ";
	cin >> maturity;
	cout << "The zero coupon bond is: $" << ZeroCouponBond(faceValue, rate, Time, maturity) << endl;\
}

void runAnnuityValue()
{
	double AnnuityAmount;
	double AmountOfPeriods;
	double rate;
	double PeriodPerYear;
	cout << "Enter the annuity amount: ";
	cin >> AnnuityAmount;
	cout << "Enter the amount of periods: ";
	cin >> rate;
	cout << "Enter the amount of periods per year: ";
	cin >> AmountOfPeriods;
	cout << "Enter the risk-free return rate: ";
	cin >> PeriodPerYear;
	cout << "The annuity value is: $" << AnnuityValue(AnnuityAmount, AmountOfPeriods, rate, PeriodPerYear) << endl;
}

void RunCompoundContinous()
{
	double principal;
	double rate;
	double time;
	cout << "Enter the principal amount: ";
	cin >> principal;
	cout << "Enter the rate: ";
	cin >> rate;
	cout << "Enter the time: ";
	cin >> time;
	double interestAm = CompoundInterestContinuous(principal, rate, time);
	cout << "The total return is: $" << interestAm << endl << "Interest amount: $" << interestAm - principal << endl << "Return: " << (100*(interestAm - principal)) / principal << "%" << endl;
}

void RunCompoundPeriod()
{
	double princpal;
	double rate;
	double Periods;
	double PeriodPerYear;
	cout << "Enter the principal amount: $";
	cin >> princpal;
	cout << "Enter the rate p.a: ";
	cin >> rate;
	cout << "Enter the amount of periods: ";
	cin >> Periods;
	cout << "Enter the amount of periods per year: ";
	cin >> PeriodPerYear;
	double interestAm = CompoundInterestPeriodic(princpal, rate, Periods, PeriodPerYear);
	cout << "The total return is: $" << interestAm << endl << "Interest amount: $" << (interestAm - princpal) << endl << "Return: " << (100 * (interestAm - princpal)) / princpal << "%" << endl;

}

void RunSimpleInterest()
{
	double principal;
	double rate;
	double time;
	cout << "Enter the principal amount: ";
	cin >> principal;
	cout << "Enter the rate: ";
	cin >> rate;
	cout << "Enter the time: ";
	cin >> time;
	double interestAm = SimpleInterest(principal, rate, time);
	cout << "The total return is: $" << interestAm << endl << "Interest amount: $" << interestAm - principal << endl << "Return: " << (100 * (interestAm - principal)) / principal << "%" << endl;
}

void CompareInterestTypes()
{
	double principal;
	double rate;
	double time;
	double CompoundPeriodicPeriodsPerYear;
	cout << "Enter the principal amount: ";
	cin >> principal;
	cout << "Enter the rate: ";
	cin >> rate;
	cout << "Enter the time: ";
	cin >> time;
	cout << "Enter the amount of periods per year: ";
	cin >> CompoundPeriodicPeriodsPerYear;
	double interestAm = SimpleInterest(principal, rate, time);
	double CompoundInterest = CompoundInterestContinuous(principal, rate, time);
	double CompoundPeriodic = CompoundInterestPeriodic(principal, rate, time, CompoundPeriodicPeriodsPerYear);
	cout << "Simple Interest: $" << interestAm << endl << "Compound Interest: $" << CompoundInterest << endl << "Compound Periodic Interest: $" << CompoundPeriodic << endl;
	cout << "Simple Interest Return: " << (100 * (interestAm - principal)) / principal << "%" << endl << "Compound Interest Return: " << (100 * (CompoundInterest - principal)) / principal << "%" << endl << "Compound Periodic Interest Return: " << (100 * (CompoundPeriodic - principal)) / principal << "%" << endl;
}

void RunBinomPDF()
{
	double n;
	double k;
	double p;
	cout << "Enter the number of trials: ";
	cin >> n;
	cout << "Enter the number of successes: ";
	cin >> k;
	cout << "Enter the probability of success: ";
	cin >> p;
	cout << "The probability of " << k << " successes in " << n << " trials is: " << BinomPDF(p, n, k) << endl;
}

void RunBinomCDF()
{
	double n;
	double lowerLimit;
	double upperLimit;
	double p;
	cout << "Enter the number of trials: ";
	cin >> n;
	cout << "Enter the lower limit: ";
	cin >> lowerLimit;
	cout << "Enter the upper limit: ";
	cin >> upperLimit;
	cout << "Enter the probability of success: ";
	cin >> p;
	cout << "The probability of " << lowerLimit << " to " << upperLimit << " successes in " << n << " trials is: " << BinomCDF(p, n, lowerLimit, upperLimit) << endl;
}