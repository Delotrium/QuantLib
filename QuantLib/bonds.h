#pragma once


namespace QuantLib
{
	double ZeroCouponBond(double faceValue, double rate, double time, double maturity);
	double AnnuityValue(double AnnuityAmount, double AmountOfPeriods, double rate, double PeriodPerYear);
}


