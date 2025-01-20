#pragma once
#include <vector>

namespace QuantLib
{
	double Poisson(double lambda, int x);
	double GaussianDistr(double mean, double sd, double x);
	double Skew(const std::vector<double>& values);
	double Kurtosis(const std::vector<double>& values);
	std::vector<double> DistributionAnalysisSimple(const std::vector<double>&values);
	double normCDF(double x, double mean = 0, double sd = 1);
}