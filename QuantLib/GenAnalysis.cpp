#include <cmath>
#include "QuantLib.h"


namespace QuantLib
{
	double ReturnAmount(double currPrice, double prevPrice)
	{
		return (currPrice - prevPrice) / (currPrice);
	}
}