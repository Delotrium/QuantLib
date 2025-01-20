#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"





int main()
{
	std::cout << "Calculated Call Price: $" << QuantLib::SimpleBlackScholes(100, 110, 1, 0.05, 0.2, true) << std::endl;
	std::cout << "Calculated Put Price: $" << QuantLib::SimpleBlackScholes(100, 110, 1, 0.05, 0.2, false) << std::endl;
	return 0;
}

