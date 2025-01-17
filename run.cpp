#include <iostream>
#include "QuantLib/QuantLib.h"
#include "QuantEngine/QuantEngine.h"



int main()
{
	int i = 0;
	while (i < 1)
	{
		std::cout << "Trial: " << i << std::endl;
		std::cout << "****************************************************************" << std::endl;
		std::vector<double> data = QuantEngine::generate_points(0, 100, 100, 1);
		QuantEngine::analysis(data);
		std::cout << "****************************************************************" << std::endl << "\n\n\n";
		i++;
	}
	return 0;

}

