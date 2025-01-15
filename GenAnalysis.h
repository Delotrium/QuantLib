#pragma once

#include <cmath>

double ReturnAmount(double currPrice, double prevPrice)
{
	return (currPrice - prevPrice) / (currPrice);
}