#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"





int main()
{
	std::cout << "Calculated Call Price: " << QuantLib::Delta(80, 120, 0.5, 0.05, 0.3, 0.05, true) << std::endl;
	std::cout << "Calculated Put Price: " << QuantLib::Delta(80, 120, 0.5, 0.05, 0.3, 0.05, false) << std::endl;
	return 0;
}

