#include <iostream>
#include "../QuantLib/QuantLib.h"
#include "QuantEngine.h"

namespace QuantEngine
{
	void analysis(std::vector<double> data)
	{
		
		double Mean = QuantLib::ArithmeticMean(data);
		double StDev = QuantLib::StandardDeviatonPop(data);
		double Variance = QuantLib::VarianceListPop(data);
		double Skew = QuantLib::Skew(data);
		double Kurt = QuantLib::Kurtosis(data);
		double GeoMean = QuantLib::geoMetricMean(data);
		std::cout << "Arithmetic Mean: " << Mean << std::endl << "Standard Deviation: " << StDev << std::endl << "Variance: " << Variance << std::endl << "Skew: " << Skew << std::endl << "Kurtosis: " << Kurt << std::endl << "Geometric Mean: " << GeoMean << std::endl;

	}
}