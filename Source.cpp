#include <iostream>
#include "GenAnalysis.h"
#include <cmath>
#include <string>
#include "ProgramIO.h"
#include "Depreciation.h"
#include "Distributions.h"




int main()
{
	std::vector<double> values = { 1,2,3,3,4,5,3,1,1,1,5,2,3,1,2,3,4,5,5,4,3,2,1,2,3,2,2,1,1 };//Choose the function you want to run
	std::vector<double> results = DistributionAnalysisSimple(values);
	std::cout << "Arithmetic Mean: " << results[0] << std::endl << "Standard Deviation: " << results[1] << std::endl << "Skew: " << results[2] << std::endl << "Kurtosis: " << results[3] << std::endl;
	return 0;
}

