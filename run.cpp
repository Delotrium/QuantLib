#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"





int main()
{
	std::vector<double> inputData = QuantEngine::csv_read("input.csv");
	QuantEngine::GenerateNormalDistributionFromFile("output_approx.csv", inputData, 4, 1000);
	return 0;
}

