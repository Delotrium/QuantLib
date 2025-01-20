#pragma once

namespace QuantLib
{
	double SimpleBlackScholes(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, bool isCall);
}


