#pragma once
#include <vector>

namespace QuantLib
{
	double Poisson(double lambda, int x);
	double GaussianDistr(double mean, double sd, double x);
	double Skew(std::vector<double>values);
	double Kurtosis(std::vector<double>values);
	std::vector<double> DistributionAnalysisSimple(std::vector<double>values);
}