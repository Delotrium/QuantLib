#include <iostream>
#include "../QuantLib/QuantLib.h"
#include "QuantEngine.h"
#include <chrono>
namespace QuantEngine
{
	void analysis(const std::vector<double>&data)
	{
		
		double Mean = QuantLib::ArithmeticMean(data);
		double StDev = QuantLib::StandardDeviatonPop(data);
		double Variance = QuantLib::VarianceListPop(data);
		double Skew = QuantLib::Skew(data);
		double Kurt = QuantLib::Kurtosis(data);
		double GeoMean = QuantLib::geoMetricMean(data);
		std::cout << "Arithmetic Mean: " << Mean << std::endl << "Standard Deviation: " << StDev << std::endl << "Variance: " << Variance << std::endl << "Skew: " << Skew << std::endl << "Kurtosis: " << Kurt << std::endl << "Geometric Mean: " << GeoMean << std::endl;

	}
	void SimpleRandomWalkGenerator()
	{
		std::cout << "Generating data..." << std::endl;
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<double> data;
		std::vector<double> sqrtValues;
		std::vector<double> NegSqrtValues;
		int num = 10000;
		int i = 0;
		int val = 0;
		while (i < num)
		{
			val += QuantLib::chooseNumber(-1, 1);
			data.emplace_back(val);

			sqrtValues.emplace_back(sqrt(i));
			NegSqrtValues.emplace_back(-sqrt(i));
			i++;
		}
		QuantEngine::create_csv("output_data.csv", data);
		QuantEngine::append_to_csv_line("output_data.csv", 2, sqrtValues);
		QuantEngine::append_to_csv_line("output_data.csv", 3, NegSqrtValues);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
		std::cout << "Data generated and saved to output_data3.csv" << std::endl;
		std::cout << "Duration: " << duration.count() << " milliseconds" << std::endl;
	}
}