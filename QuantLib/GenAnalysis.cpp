#include <cmath>
#include "QuantLib.h"


namespace QuantLib
{
	double ReturnAmount(double currPrice, double prevPrice)
	{
		return (currPrice - prevPrice) / (currPrice);
	}
	double SharpeRatio(double Return, double RiskFreeRate, double volatility)
	{
		return (Return - RiskFreeRate) / volatility;
	}
	double SortinoRatio(double Return, double RiskFreeRate, double volatility)
	{
		return (Return - RiskFreeRate) / sqrt(volatility);
	}
	double SharpeRatioFromList(std::vector<double> returns, double risk_free_rate)
	{
		double mean = 0;
		for (int i = 0; i < returns.size(); i++)
		{
			mean += returns[i];
		}
		mean /= returns.size();
		double variance = 0;
		for (int i = 0; i < returns.size(); i++)
		{
			variance += (returns[i] - mean) * (returns[i] - mean);
		}
		variance /= returns.size();
		double std_dev = sqrt(variance);
		return (mean - risk_free_rate) / std_dev;
	}
	double SortinoRatioFromList(std::vector<double> returns, double risk_free_rate)
	{
		double mean = 0;
		for (int i = 0; i < returns.size(); i++)
		{
			mean += returns[i];
		}
		mean /= returns.size();
		double variance = 0;
		for (int i = 0; i < returns.size(); i++)
		{
			variance += (returns[i] - mean) * (returns[i] - mean);
		}
		variance /= returns.size();
		double std_dev = sqrt(variance);
		double downside_dev = 0;
		for (int i = 0; i < returns.size(); i++)
		{
			if (returns[i] < 0)
			{
				downside_dev += returns[i] * returns[i];
			}
		}
		downside_dev /= returns.size();
		downside_dev = sqrt(downside_dev);
		return (mean - risk_free_rate) / downside_dev;
	}
}