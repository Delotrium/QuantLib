#pragma once
#include "../QuantLib/QuantLib.h"

namespace QuantEngine
{
	std::vector<double> csv_read(std::string filename);
	std::vector<double> update_point(std::vector<double> values, int n, double UpdatedValue);
	std::vector<double> generate_points(double lowerLimit, double upperLimit, double amount, int mode);
	void create_csv(std::string filename, const std::vector<double>& values);
	void append_to_csv_line(const std::string& filename, int line_number, const std::vector<double>& values);
}