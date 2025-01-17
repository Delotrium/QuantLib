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
	double ExpectedValue(std::vector<double> values, std::vector<double> probabilities);
	double ExpectedValueBinom(double numTrials, double probSuccess);
	double VarBinom(double numTrials, double probSucess);
	double ArithmeticMean(std::vector<double> values);
	double VarianceListSample(std::vector<double> values);
	double VarianceListPop(std::vector<double> values);
	double StandardDeviatonSample(std::vector<double> values);
	double StandardDeviatonPop(std::vector<double> values);
	double geoMetricMean(std::vector<double> values);
	double CompoundAnnualGrowthRate(double initValue, double endValue, double initTime, double endTime);
}