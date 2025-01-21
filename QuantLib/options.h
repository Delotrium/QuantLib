#pragma once

namespace QuantLib
{
	double d1(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma);
	double d2(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma);
	double SimpleBlackScholes(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double DividendReturns_q, bool isCall);
	double Delta(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double dividend_q, bool isCall);
}