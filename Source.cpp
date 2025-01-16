#include <iostream>
#include "GenAnalysis.h"
#include <cmath>
#include <string>
#include "ProgramIO.h"
#include "Depreciation.h"
#include "Distributions.h"




int main()
{
	std::cout << Skew({ 2,2,3,4,5 }) << std::endl;
	std::cout << Kurtosis({ 2,2,3,4, 5 }); //Choose the function you want to run
	return 0;
}

