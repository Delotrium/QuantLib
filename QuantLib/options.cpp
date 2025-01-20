#include <cmath>
#include <vector>
#include "QuantLib/QuantLib.h"

namespace QuantLib
{
    double SimpleBlackScholes(double StockPrice_S, double StrikePrice_K, double TimeToMat_T, double RiskFreeRate_r, double volatility_Sigma, bool isCall)
	{
        
        {
            double d1 = (std::log(StockPrice_S / StrikePrice_K) + (RiskFreeRate_r + 0.5 * volatility_Sigma * volatility_Sigma) * TimeToMat_T) / (volatility_Sigma * std::sqrt(TimeToMat_T));
            double d2 = d1 - volatility_Sigma * std::sqrt(TimeToMat_T);

            if (isCall) 
            {
                // Call option price
                return StockPrice_S * QuantLib::normCDF(d1) - StrikePrice_K * std::exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(d2);
            }
            else 
            {
                // Put option price
                return StrikePrice_K * std::exp(-RiskFreeRate_r * TimeToMat_T) * QuantLib::normCDF(-d2) - StockPrice_S * QuantLib::normCDF(-d1);
            }
        }
	}
}
