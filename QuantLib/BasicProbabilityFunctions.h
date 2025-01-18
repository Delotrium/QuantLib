#pragma once
#include "QuantLib.h"
#include <vector>

namespace QuantLib
{
	double BasicProbabilityRepeat(double ObservedEventProbability, double ObserveredSuccesses);
	double BasicProbability(double ObservedEventProbability, double ObserveredSuccesses, double ObserveredFailures);
	double Factorial(double Num);
	double BinomPDF(double ObservedEventProbability, double NumTrials, double NumSuccesses);
	double BinomCDF(double ObservedEventProbability, double numTrials, double lowerLimit, double UpperLimit);
	double ExpectedValue(const std::vector<double>& values, const std::vector<double>& probabilities);
	double ExpectedValueBinom(double numTrials, double probSuccess);
	double VarBinom(double numTrials, double probSucess);
	double ArithmeticMean(const std::vector<double>&values);
	double VarianceListSample(const std::vector<double>& values);
	double VarianceListPop(const std::vector<double>& values);
	double StandardDeviatonSample(const std::vector<double>& values);
	double StandardDeviatonPop(const std::vector<double>& values);
	double geoMetricMean(const std::vector<double>& values);
	double CompoundAnnualGrowthRate(double initValue, double endValue, double initTime, double endTime);
	double rng(double lowerLimit, double upperLimit);
}