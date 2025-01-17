#include <cmath>
#include <vector>
#include "QuantLib.h"


namespace QuantLib 
{
	double StraightLineDepreciationAmount(double InitialValue, double FinalValue, double UsefulLife)
	{
		return (InitialValue - FinalValue) / UsefulLife;
	}

	std::vector < double> StraightLineDepreciationTotal(double initialValue, double FinalValue, double UsefulLife, double Time)
	{
		double depr = StraightLineDepreciationAmount(initialValue, FinalValue, UsefulLife) * Time;
		return std::vector<double>(depr, initialValue - depr);
	}

	double DecliningBalanceDepreciationTotal(double InitialValue, double Time, double Rate)
	{
		double depr = (InitialValue) * (pow(1 - Rate, Time));
		return depr;
	}
}
