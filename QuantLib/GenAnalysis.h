#pragma once

#include <cmath>

namespace QuantLib
{
	double ReturnAmount(double currPrice, double prevPrice);
	double SortinoRatioFromList(std::vector<double> returns, double risk_free_rate);
	double SharpeRatioFromList(std::vector<double> returns, double risk_free_rate);
	double SortinoRatio(double Return, double RiskFreeRate, double volatility);
	double SharpeRatio(double Return, double RiskFreeRate, double volatility);
}