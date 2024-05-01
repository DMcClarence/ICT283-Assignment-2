//StatsCalcs.h - Statistics Calculations functions definition/interface
//---------------------------------------------------------------------------------

#ifndef STATSCALCS_H_INCLUDED
#define STANDARDDEV_H_INCLUDED

//---------------------------------------------------------------------------------

#include "Vector.h"

//---------------------------------------------------------------------------------

    /**
	 * @file StatsCalcs.h
	 * @brief  Statistics Calculations functions definition/interface
	 *
	 * @author 34085068
	 * @version 01
	 * @date 23/03/2024 Started
	 */

	 /**
     * @brief  Calculates the sum of a Vector of floats
     *
     *
     * @return float - The Total Sum of the Vector
     */
float CalcSumOfVectorf(const Vector<float> &vec);

    /**
     * @brief  Calculates the mean from a Vector of floats
     *
     *
     * @return float - The Mean of the Vector
     */
float CalcMeanOfVectorf(const Vector<float> &vec);

    /**
     * @brief  Calculates standard deviation of a Vector of floats
     *
     *
     * @return float - The Standard Deviation of the Vector
     */
float CalcStdDevOfVectorf(const Vector<float> &vec);

//---------------------------------------------------------------------------------

#endif // STANDARDDEV_H_INCLUDED

//---------------------------------------------------------------------------------
