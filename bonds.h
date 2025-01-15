#pragma once

#include <cmath>


double ZeroCouponBond(double faceValue, double rate, double time, double maturity)
{
	return faceValue / pow(1 + rate, maturity - time);
}

double AnnuityValue(double AnnuityAmount, double AmountOfPeriods, double rate, double PeriodPerYear)
{
	double GeoR = pow((1 + (rate / PeriodPerYear)), - PeriodPerYear);
	double Sum = GeoR * (1 - pow(GeoR, AmountOfPeriods)) / (1 - GeoR);
	return AnnuityAmount * Sum;
}

