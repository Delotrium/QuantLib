#include <vector>
#include <iostream>
#include "../QuantLib/QuantLib.h"
#include "sstream"
#include "fstream"
#include "string"
#include "QuantEngine.h"
#include <experimental/generator>

namespace QuantEngine
{
	std::vector<double> csv_read(std::string filename)
	{
		std::vector<double> values;
		std::ifstream file(filename);
		std::string line;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string token;
			while (std::getline(ss, token, ','))
			{
				values.push_back(std::stod(token));
			}
		}
		return values;
	}

	std::vector<double> update_point(std::vector<double> values, int n, double UpdatedValue)
	{
		values[n] = UpdatedValue;
		return values;
	}

	std::vector<double> generate_points(double lowerLimit, double upperLimit, double amount, int mode)
	{
		std::vector<double> values;
		int i = 0;
		double step = (upperLimit - lowerLimit) / amount;
		while (i < amount)
		{
			switch (mode)
			{
			case 1:
				values.push_back(lowerLimit+(i*step));
				break;
			case 2:
				values.push_back(upperLimit - (i*step));
				break;
			default:
				values.push_back(QuantLib::rng(lowerLimit, upperLimit));
				break;
			}
			i++;
		}
		return values;

	}
}

