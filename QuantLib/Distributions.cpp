#include <cmath>
#include <vector>
#include "QuantLib.h"

namespace QuantLib
{
	double pi = 3.14159265358979323846;

	double Poisson(double lambda, int x)
	{
		return (exp(-lambda) * pow(lambda, x)) / Factorial(x);
	}

	double GaussianDistr(double mean, double sd, double x)
	{
		double GausDst = (1 / (sd * sqrt(2 * pi))) * exp((-pow(x - mean, 2) / (2 * pow(sd, 2))));
		return GausDst;
	}

	double Skew(const std::vector<double>& values)
	{
		double mean = ArithmeticMean(values);
		double sd = StandardDeviatonSample(values);
		double coeff = 1 / (values.size() * pow(sd, 3));
		double skew = 0;
		int i = 0;
		while (i < values.size())
		{
			skew += pow(values[i] - mean, 3);
			i++;
		}
		return skew * coeff;
	}

	double Kurtosis(const std::vector<double>& values)
	{
		double mean = ArithmeticMean(values);
		double sd = StandardDeviatonSample(values);
		double coeff = 1 / (values.size() * pow(sd, 4));
		double skew = 0;
		int i = 0;
		while (i < values.size())
		{
			skew += pow(values[i] - mean, 4);
			i++;
		}
		return skew * coeff - 3;
	}

	std::vector<double> DistributionAnalysisSimple(const std::vector<double>&values)
	{
		std::vector<double>results;
		results.emplace_back(ArithmeticMean(values));
		results.emplace_back(StandardDeviatonSample(values));
		results.emplace_back(Skew(values));
		results.emplace_back(Kurtosis(values));
		return results;
	}
}