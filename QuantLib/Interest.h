#pragma once

#include <cmath>

namespace QuantLib
{
	double CompoundInterestContinuous(double principal, double rate, double time);
	double CompoundInterestPeriodic(double principal, double rate, double Periods, double PeriodPerYear);
	double SimpleInterest(double principal, double rate, double time);
}