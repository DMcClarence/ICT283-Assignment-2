#include "StatsCalcsTest.h"

#include "../includes/StatsCalcs.h"

#include <iostream>

using std::cout;
using std::endl;

int TestCalcSumOfVectorf()
{
    Vector<float> vec;
    vec.PushBack(7.89);
    vec.PushBack(1.24);
    vec.PushBack(12.34);
    vec.PushBack(10);
    vec.PushBack(79);
    vec.PushBack(17);
    vec.PushBack(189.8);
    vec.PushBack(43);
    vec.PushBack(89.367);
    vec.PushBack(122.7899);

    float sum = CalcSumOfVectorf(vec);

    cout << "Sum = " << sum << endl;

    return 0;
}

int TestCalcMeanOfVectorf()
{
    Vector<float> vec;
    vec.PushBack(7.89);
    vec.PushBack(1.24);
    vec.PushBack(12.34);
    vec.PushBack(10);
    vec.PushBack(79);
    vec.PushBack(17);
    vec.PushBack(189.8);
    vec.PushBack(43);
    vec.PushBack(89.367);
    vec.PushBack(122.7899);

    float mean = CalcMeanOfVectorf(vec);

    cout << "Mean = " << mean << endl;

    return 0;
}

int TestCalcStdDevOfVectorf()
{
    Vector<float> vec;
    vec.PushBack(7.89);
    vec.PushBack(1.24);
    vec.PushBack(12.34);
    vec.PushBack(10);
    vec.PushBack(79);
    vec.PushBack(17);
    vec.PushBack(189.8);
    vec.PushBack(43);
    vec.PushBack(89.367);
    vec.PushBack(122.7899);

   float stdDev = CalcStdDevOfVectorf(vec);

   cout << "Standard Deviation = " << stdDev << endl;

   return 0;
}
