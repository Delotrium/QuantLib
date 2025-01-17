#include <vector>
#include <iostream>
#include "QuantLib.h"
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

	std::vector<double> generate_points(double lowerLimit, double upperLimit, double amount)
	{
		std::vector<double> values;
		int i = 0;
		while (i < amount)
		{
			values.push_back(QuantLib::rng(lowerLimit, upperLimit));
			i++;
		}
		return values;

	}
}

