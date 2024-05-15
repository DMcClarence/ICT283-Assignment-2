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

using std::sqrt;

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

float StatsCalcs::CalcSumOfVectorf(const Vector<float> &vec)
{
    float sum = 0;

    for(int i = 0; i < vec.GetSize(); i++)
    {
        sum += vec[i];
    }

    return sum;
}

//---------------------------------------------------------------------------------
float StatsCalcs::CalcMeanOfVectorf(const Vector<float> &vec)
{
    float sum;

    sum = CalcSumOfVectorf(vec);

    return sum / vec.GetSize();
}

//---------------------------------------------------------------------------------
float StatsCalcs::CalcStdDevOfVectorf(const Vector<float> &vec)
{
    float sum = 0;
    float mean = CalcMeanOfVectorf(vec);

    for(int i = 0; i < vec.GetSize(); i++)
    {
        sum += ((vec[i] - mean) * (vec[i] - mean));
    }

    return sqrt((sum / (vec.GetSize() - 1)));
}

//---------------------------------------------------------------------------------
float StatsCalcs::CalcSPCCOfVectorf(const Vector<float> &vec1, const Vector<float> &vec2)
{
    float sampleMeanVec1 = CalcMeanOfVectorf(vec1);
    float sampleMeanVec2 = CalcMeanOfVectorf(vec2);

    float sumVec1Vec2 = 0;
    float sumVec1 = 0;
    float sumVec2 = 0;
    for(int i = 0; i < vec1.GetSize(); i++)
    {
        sumVec1Vec2 += ((vec1[i] - sampleMeanVec1) * (vec2[i] - sampleMeanVec2));
        sumVec1 += ((vec1[i] - sampleMeanVec1) * (vec1[i] - sampleMeanVec1));
        sumVec2 += ((vec2[i] - sampleMeanVec2) * (vec2[i] - sampleMeanVec2));
    }

    return sumVec1Vec2 / sqrt(sumVec1 * sumVec2);
}

//---------------------------------------------------------------------------------
float StatsCalcs::CalcMADOfVectorf(const Vector<float> &vec)
{
    float mean = CalcMeanOfVectorf(vec);

    float sum = 0;
    for(int i = 0; i < vec.GetSize(); i++)
    {
        sum += abs((vec[i] - mean));
    }

    return sum / vec.GetSize();
}

//---------------------------------------------------------------------------------
