// StatsCalcs.cpp
//
// Statistic Calculations functions implementations
//
// Version
// 01 23/03/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/StatsCalcs.h"

#include <cmath>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

float CalcSumOfVectorf(const Vector<float> &vec)
{
    float sum = 0;

    for(int i = 0; i < vec.GetSize(); i++)
    {
        sum += vec[i];
    }

    return sum;
}

//---------------------------------------------------------------------------------
float CalcMeanOfVectorf(const Vector<float> &vec)
{
    float sum;

    sum = CalcSumOfVectorf(vec);

    return sum / vec.GetSize();
}

//---------------------------------------------------------------------------------
float CalcStdDevOfVectorf(const Vector<float> &vec)
{
    float sum = 0;
    float mean = CalcMeanOfVectorf(vec);

    for(int i = 0; i < vec.GetSize(); i++)
    {
        sum += ((vec[i] - mean) * (vec[i] - mean));
    }

    return std::sqrt((sum / (vec.GetSize() - 1)));
}

//---------------------------------------------------------------------------------
