#include <cmath>
#include <vector>
#include "QuantLib.h"

namespace QuantLib
{
    double d1(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma)
    {
        return (std::log(StockPrice_S / StrikePrice_K) + (RiskFreeRate_r + 0.5 * volatility_Sigma * volatility_Sigma) * TimeToMat_T) / (volatility_Sigma * std::sqrt(TimeToMat_T));
    }

    double d2(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma)
    {
        return d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma) - volatility_Sigma * std::sqrt(TimeToMat_T);
    }

    double SimpleBlackScholes(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double DividendReturns_q, bool isCall)
    {
        double d_1 = d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma);
        double d_2 = d2(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma);
        if (isCall)
        {
            // Call option price

            return StockPrice_S * exp(-DividendReturns_q * TimeToMat_T) * QuantLib::normCDF(d_1) - StrikePrice_K * std::exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(d_2);
        }
        else
        {
            // Put option price
            return StrikePrice_K * std::exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(-d_2) - StockPrice_S * exp(-DividendReturns_q * TimeToMat_T) * QuantLib::normCDF(-d_1);
        }
    }

    double Delta(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double dividend_q, bool isCall)
    {
        if (isCall)
        {
            return exp(-dividend_q * TimeToMat_T) * QuantLib::normCDF(d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma));
        }
        else
        {
            return -exp(-dividend_q * TimeToMat_T) * (QuantLib::normCDF(-d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)));
        }
    }
    double Vega(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double dividend_q)
    {
        return StockPrice_S * exp(-dividend_q * TimeToMat_T) * QuantLib::GaussianDistr(0, 1, d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)) * sqrt(TimeToMat_T);
    }
	double Theta(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double dividend_q, bool isCall)
	{
		if (isCall)
		{
			return -StockPrice_S * exp(-dividend_q * TimeToMat_T) * QuantLib::GaussianDistr(0, 1, d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)) * volatility_Sigma / (2 * sqrt(TimeToMat_T)) - dividend_q * StockPrice_S * exp(-dividend_q * TimeToMat_T) * QuantLib::normCDF(d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)) + RiskFreeRate_r * StrikePrice_K * exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(d2(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma));
		}
		else
		{
			return -StockPrice_S * exp(-dividend_q * TimeToMat_T) * QuantLib::GaussianDistr(0, 1, d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)) * volatility_Sigma / (2 * sqrt(TimeToMat_T)) + dividend_q * StockPrice_S * exp(-dividend_q * TimeToMat_T) * QuantLib::normCDF(-d1(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma)) - RiskFreeRate_r * StrikePrice_K * exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(-d2(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma));
		}
	}
    double Rho(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, double dividend_q, bool isCall)
    {
		if (isCall)
		{
			return TimeToMat_T * StrikePrice_K * exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(d2(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma));
		}
		else
		{
			return -TimeToMat_T * StrikePrice_K * exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(-d2(StockPrice_S, StrikePrice_K, TimeToMat_T, RiskFreeRate_r, volatility_Sigma));
		}
    }
}
