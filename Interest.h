#pragma once

#include <cmath>
#include <iostream>

double CompoundInterestContinuous(double principal, double rate, double time)
{
	return principal * exp(rate * time);
}

double CompoundInterestPeriodic(double principal, double rate, double Periods, double PeriodPerYear)
{
	return principal * pow(1 + (rate / PeriodPerYear), Periods * PeriodPerYear);
}

double SimpleInterest(double principal, double rate, double time)
{
	return (principal * ((rate) * time))+principal;
}