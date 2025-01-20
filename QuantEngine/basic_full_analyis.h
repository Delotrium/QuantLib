#pragma once
#include "../QuantLib/QuantLib.h"
#include <string>
namespace QuantEngine
{
	void analysis(const std::vector<double>&data);
	void SimpleRandomWalkGenerator();
	void GenerateNormalDistributionFromFile(std::string filename, const std::vector<double>& data, double width, int amount);
	void GenerateNormalDistribution(std::string filename, double sd, double mean, double width, int amount);
	void SimpleRandomWalkGeneratorMultiplier();
}