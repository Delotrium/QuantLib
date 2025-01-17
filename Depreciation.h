#pragma once


#include <vector>

namespace QuantLib
{
	double StraightLineDepreciationAmount(double InitialValue, double FinalValue, double UsefulLife);
	std::vector < double> StraightLineDepreciationTotal(double initialValue, double FinalValue, double UsefulLife, double Time);
	double DecliningBalanceDepreciationTotal(double InitialValue, double Time, double Rate);
}