#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"



int main()
{
	int i = 0;
	while (i < 20)
	{
		std::cout << "Trial: " << i << std::endl;
		std::cout << "****************************************************************" << std::endl;
		QuantEngine::analysis(QuantEngine::generate_points(0, 100, 500));
		std::cout << "****************************************************************" << std::endl << "\n\n\n";
		i++;
	}
	return 0;

}

