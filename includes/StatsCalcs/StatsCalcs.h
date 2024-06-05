//StatsCalcs.h - Statistics Calculations functions definition/interface
//---------------------------------------------------------------------------------

#ifndef STATSCALCS_H_INCLUDED
#define STANDARDDEV_H_INCLUDED

//---------------------------------------------------------------------------------

#include "../Vector/Vector.h"

//---------------------------------------------------------------------------------

    /**
	 * @namespace StatsCalcs
	 * @brief  Statistics Calculations functions definition/interface
	 *
	 * @author 34085068
	 * @version 01
	 * @date 23/03/2024 Started
	 */
namespace StatsCalcs
{
         /**
         * @brief  Calculates the sum of a Vector of floats
         *
         *
         * @param vec - The Vector of floats
         * @return float - The Total Sum of the Vector
         */
    float CalcSumOfVectorf(const Vector<float> &vec);

        /**
         * @brief  Calculates the mean from a Vector of floats
         *
         *
         * @param vec - The Vector of floats
         * @return float - The Mean of the Vector
         */
    float CalcMeanOfVectorf(const Vector<float> &vec);

        /**
         * @brief  Calculates standard deviation of a Vector of floats
         *
         *
         * @param vec - The Vector of floats
         * @return float - The Standard Deviation of the Vector
         */
    float CalcStdDevOfVectorf(const Vector<float> &vec);

        /**
         * @brief  Calculates sample Pearson Correlation Coefficient of two Vectors of floats
         *
         *
         * @param vec1 - The First Vector of floats
         * @param vec2 - The Second Vector of floats
         * @return float - The sample Peason Correlation Coefficient
         */
    float CalcSPCCOfVectorf(const Vector<float> &vec1, const Vector<float> &vec2);

        /**
         * @brief  Calculates the Mean Absolute Deviation of a Vector of floats
         *
         *
         * @param vec - The Vector of floats
         * @return float - The Mean Absolute Deviation
         */
    float CalcMADOfVectorf(const Vector<float> &vec);
}

//---------------------------------------------------------------------------------

#endif // STANDARDDEV_H_INCLUDED

//---------------------------------------------------------------------------------
