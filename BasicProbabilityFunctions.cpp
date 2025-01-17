#include <cmath>
#include <vector>
#include "QuantLib.h"
#include "basicProbabilityFunctions.h"
namespace QuantLib
{
	double BasicProbabilityRepeat(double ObservedEventProbability, double ObserveredSuccesses)
	{
		return pow(ObservedEventProbability, ObserveredSuccesses);
	}

	double BasicProbability(double ObservedEventProbability, double ObserveredSuccesses, double ObserveredFailures)
	{
		return pow(ObservedEventProbability, ObserveredSuccesses) * pow(1 - ObservedEventProbability, ObserveredFailures);
	}

	double Factorial(double Num)
	{
		double Factorial = 1;
		for (int i = 1; i <= Num; i++)
		{
			Factorial *= i;
		}
		return Factorial;
	}

	double BinomPDF(double ObservedEventProbability, double NumTrials, double NumSuccesses)
	{
		return (Factorial(NumTrials) / (Factorial(NumTrials - NumSuccesses) * Factorial(NumSuccesses))) * pow(ObservedEventProbability, NumSuccesses) * pow(1 - ObservedEventProbability, NumTrials - NumSuccesses);
	}

	double BinomCDF(double ObservedEventProbability, double numTrials, double lowerLimit, double UpperLimit)
	{
		double CDF = 0;
		while (lowerLimit < UpperLimit)
		{
			CDF = CDF + BinomPDF(ObservedEventProbability, numTrials, lowerLimit);
			lowerLimit++;
		}
		return CDF;
	}

	double ExpectedValue(std::vector<double> values, std::vector<double> probabilities)
	{
		int i = 0;
		double val = 0;
		while (i < values.size())
		{
			val = val + (values[i] * probabilities[i]);
			i++;
		}
		return val;
	}

	double ExpectedValueBinom(double numTrials, double probSuccess)
	{
		return numTrials * probSuccess;
	}

	double VarBinom(double numTrials, double probSucess)
	{
		return numTrials * probSucess * (1 - probSucess);
	}

	double ArithmeticMean(std::vector<double> values)
	{
		int i = 0;
		int val = 0;
		while (i < values.size())
		{
			val = val + values[i];
			i++;
		}
		return (val / values.size());
	}

	double VarianceListSample(std::vector<double> values)
	{

		int i = 0;
		double val = 0;
		double arith = ArithmeticMean(values);
		while (i < values.size())
		{
			val += (pow(values[i] - arith, 2));
			i++;
		}
		return val / (values.size() - 1);
	}

	double VarianceListPop(std::vector<double> values)
	{

		int i = 0;
		double val = 0;
		double arith = ArithmeticMean(values);
		while (i < values.size())
		{
			val += (pow(values[i] - arith, 2));
			i++;
		}
		return val / (values.size());
	}

	double StandardDeviatonSample(std::vector<double> values)
	{
		return sqrt(VarianceListSample(values));
	}

	double StandardDeviatonPop(std::vector<double> values)
	{
		return sqrt(VarianceListPop(values));
	}

	double geoMetricMean(std::vector<double> values)
	{
		int i = 0;
		double val = 1;
		while (i < values.size())
		{
			val *= values[i];
			i++;
		}
		return pow(val, 1.0 / values.size());
	}

	double CompoundAnnualGrowthRate(double initValue, double endValue, double initTime, double endTime)
	{
		return (pow(endValue / initValue, 1 / (endTime, initTime))) - 1;
	}
}