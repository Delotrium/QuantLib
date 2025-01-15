#pragma once

#include <cmath>
#include <iostream>

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
	return (Factorial(NumTrials) / (Factorial(NumTrials - NumSuccesses) * Factorial(NumSuccesses)))* pow(ObservedEventProbability, NumSuccesses)* pow(1 - ObservedEventProbability, NumTrials - NumSuccesses);
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