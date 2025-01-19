#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"





int main()
{
	QuantEngine::GenerateNormalDistribution("output_data.csv", 1, 5, 4, 1000);
	return 0;
}

