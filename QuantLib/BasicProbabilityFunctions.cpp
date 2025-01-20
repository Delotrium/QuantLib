#include <cmath>
#include <vector>
#include <random>
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

	double ExpectedValue(const std::vector<double>& values, const std::vector<double>& probabilities)
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

	double ArithmeticMean(const std::vector<double>& values)
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

	double VarianceListSample(const std::vector<double>& values)
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

	double VarianceListPop(const std::vector<double>& values)
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

	double StandardDeviatonSample(const std::vector<double>& values)
	{
		return sqrt(VarianceListSample(values));
	}

	double StandardDeviatonPop(const std::vector<double>& values)
	{
		return sqrt(VarianceListPop(values));
	}

	double geoMetricMean(const std::vector<double>& values)
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
	double rng(double lowerLimit, double upperLimit)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(lowerLimit, upperLimit);
		return dis(gen);
	}
	double chooseNumber(double num1, double num2)
	{
		std::random_device rd;
		std::mt19937 gen(rd()); 
		std::uniform_int_distribution<int> dist(0, 1); 
		double result = (dist(gen) == 0) ? num1 : num2;
		return result;
	}

	double simpleRandomWalk(double negativeValue, double positiveValue, double steps)
	{
		double val = 0;
		for (int i = 0; i < steps; i++)
		{
			val += chooseNumber(negativeValue, positiveValue);
		}
		return val;
	}
	
}