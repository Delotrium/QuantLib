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
				values.emplace_back(std::stod(token));
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
				values.emplace_back(lowerLimit+(i*step));
				break;
			case 2:
				values.emplace_back(upperLimit - (i*step));
				break;
			default:
				values.emplace_back(QuantLib::rng(lowerLimit, upperLimit));
				break;
			}
			i++;
		}
		return values;

	}
	void create_csv(std::string filename, const std::vector<double>& values)
	{
		std::ofstream file(filename);
		for (auto& value : values)
		{
			file << value << ",";
		}
		file.close();
	}

	void append_to_csv_line(const std::string& filename, int line_number, const std::vector<double>& values) 
	{
		if (line_number < 1) {
			std::cerr << "Error: Line number must be greater than or equal to 1." << std::endl;
			return;
		}
		std::ifstream infile(filename);
		if (!infile.is_open()) {
			std::cerr << "Error: Unable to open file " << filename << std::endl;
			return;
		}
		std::vector<std::string> lines;
		std::string line;
		while (std::getline(infile, line)) {
			lines.push_back(line);
		}
		infile.close();
		while (static_cast<int>(lines.size()) < line_number) {
			lines.emplace_back(""); 
		}
		std::ostringstream oss;
		if (!lines[line_number - 1].empty()) {
			oss << lines[line_number - 1] << ",";
		}
		for (const auto& value : values) {
			oss << value << ",";
		}
		lines[line_number - 1] = oss.str();

		std::ofstream outfile(filename);
		if (!outfile.is_open()) {
			std::cerr << "Error: Unable to write to file " << filename << std::endl;
			return;
		}
		for (const auto& l : lines) {
			outfile << l << "\n";
		}
		outfile.close();
	}

}

