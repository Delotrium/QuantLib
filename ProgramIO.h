#pragma once
#include <iostream>
#include <string>
#include <cmath>
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