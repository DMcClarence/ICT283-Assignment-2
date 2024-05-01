#include "VectorTest.h"
#include "DateTest.h"
#include "TimeTest.h"
#include "StatsCalcsTest.h"
#include "WeatherRecUtilitiesTest.h"
#include "weatherRecIOTest.h"
#include "MenuTest.h"

#include <iostream>

using std::cout;
using std::endl;

void TestComplete(int complete);
void VectorTest();
void DateTest();
void TimeTest();
void StatsCalcsTest();
void WeatherRecUtilitiesTest();
void WeatherRecIOTest();
void MenuTest();

int main()
{
    cout << "Test Program" << endl;
    cout << endl;

    VectorTest();
    DateTest();
    TimeTest();
    StatsCalcsTest();
    WeatherRecUtilitiesTest();
    WeatherRecIOTest();
    MenuTest();

    cout << "Test Program Completed" << endl;
    return 0;
}

void TestComplete(int complete)
{
    if(complete == 0)
    {
        cout << "Test Completed" << endl;
    }
    else
    {
        cout << "Test Failed to Complete" << endl;
    }
}

void VectorTest()
{
    int complete;

    cout << "Vector Test Commencing" << endl;
    cout << endl;

    cout << "Vector Test 1 - Default Constructor" << endl;
    complete = TestVectorDefaultConstructor();
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 2 - Non Default Constructor" << endl;
    complete = TestVectorNonDefaultConstructor(10);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 3 - Copy Constructor" << endl;
    complete = TestVectorCopyConstructor(10);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 4 - Operator =" << endl;
    complete = TestVectorAssignmentOperator(10);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 5 - GetSize()" << endl;
    complete = TestGetSize(10);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 6 - Destructor()" << endl;
    complete = TestDestructor(10);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 7 - PushBack()" << endl;
    complete = TestPushBack(2, 5);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 8 - PopBack()" << endl;
    complete = TestPopBack(2, 5);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test 9 - [] Operator for Arrays" << endl;
    complete = TestVectorArrayIndexOperator(5, 5, 2);
    TestComplete(complete);
    cout << endl;

    cout << "Vector Test Complete" << endl;
}

void DateTest()
{
    int complete;

    cout << "Date Test Commencing" << endl;
    cout << endl;

    cout << "Date Test 1 - GetDay()" << endl;
    complete = TestGetDay();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test 2 - GetMonth()" << endl;
    complete = TestGetMonth();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test 3 - GetYear()" << endl;
    complete = TestGetYear();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test 4 - SetDay()" << endl;
    complete = TestSetDay();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test 5 - SetMonth()" << endl;
    complete = TestSetMonth();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test 6 - SetYear()" << endl;
    complete = TestSetYear();
    TestComplete(complete);
    cout << endl;

    cout << "Date Test Complete" << endl;
    cout << endl;
}

void TimeTest()
{
    int complete;

    cout << "Time Test Commencing" << endl;
    cout << endl;

    cout << "Time Test 1 - Default Constructor" << endl;
    complete = TestTimeDefaultConstructor();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 2 - Non Default Constructor" << endl;
    complete = TestTimeNonDefaultConstructor();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 3 - GetHours()" << endl;
    complete = TestGetHours();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 4 - GetMinutes()" << endl;
    complete = TestGetMinutes();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 5 - GetSeconds()" << endl;
    complete = TestGetSeconds();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 6 - SetHours()" << endl;
    complete = TestSetHours();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 7 - SetMinutes()" << endl;
    complete = TestSetMinutes();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test 8 - SetSeconds()" << endl;
    complete = TestSetSeconds();
    TestComplete(complete);
    cout << endl;

    cout << "Time Test Complete" << endl;
    cout << endl;
}

void StatsCalcsTest()
{
    int complete;

    cout << "Statistics Calculations Test Commencing" << endl;
    cout << endl;

    cout << "Statistics Calculations Test 1 - CalcSumOfVectorf()" << endl;
    complete = TestCalcSumOfVectorf();
    TestComplete(complete);
    cout << endl;

    cout << "Statistics Calculations Test 2 - CalcMeanOfVectorf()" << endl;
    complete = TestCalcMeanOfVectorf();
    TestComplete(complete);
    cout << endl;

    cout << "Statistics Calculations Test 3 - CalcStdDevOfVectorf()" << endl;
    complete = TestCalcStdDevOfVectorf();
    TestComplete(complete);
    cout << endl;

    cout << "Statistics Calculations Test Complete" << endl;
    cout << endl;
}

void WeatherRecUtilitiesTest()
{
    int complete;

    cout << "Weather Record Utilities Test Commencing" << endl;
    cout << endl;

    cout << "Weather Record Utilities Test 1 - ExtractValuesFromWeatherLog()" << endl;
    complete = TestExtractValuesFromWeatherLog();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record Utilities Test 2 - MonthToString()" << endl;
    complete = TestMonthToString();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record Utilities Test 3 - ToKMperHr()" << endl;
    complete = TestToKMperHr();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record Utilities Test 4 - TokWh()" << endl;
    complete = TestTokWh();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record Utilities Test Complete" << endl;
    cout << endl;
}

void WeatherRecIOTest()
{
    int complete;

    cout << "Weather Record IO Test Commencing" << endl;
    cout << endl;

    cout << "Weather Record IO Test 1 - Date Insertion >>" << endl;
    complete = TestDateInsertion();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record IO Test 2 - Time Insertion >>" << endl;
    complete = TestTimeInsertion();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record IO Test 3 - WeatherLogType Insertion >>" << endl;
    complete = TestWeatherLogTypeInsertion();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record IO Test 4 - GetDataFileNameFromSrcFile()" << endl;
    complete = TestGetDataFileNameFromSrcFile();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record IO Test 5 - ReadWeatherDataFromFile()" << endl;
    complete = TestReadWeatherDataFromFile();
    TestComplete(complete);
    cout << endl;

    cout << "Weather Record IO Test Complete" << endl;
    cout << endl;
}

void MenuTest()
{
    int complete;

    cout << "Menu Test Commencing" << endl;
    cout << endl;

    cout << "Menu Test 1 - Wind Menu Strategy" << endl;
    complete = TestWindSpeedMenuOption();
    TestComplete(complete);
    cout << endl;

    cout << "Menu Test 2 - Temperature Menu Strategy" << endl;
    complete = TestTemperatureMenuOption();
    TestComplete(complete);
    cout << endl;

    cout << "Menu Test 3 - Solar Radiation Menu Strategy" << endl;
    complete = TestSolarRadiationMenuOption();
    TestComplete(complete);
    cout << endl;

    cout << "Menu Test 4 - Print to File Menu Strategy" << endl;
    complete = TestPrintToFileMenuOption();
    TestComplete(complete);
    cout << endl;

    cout << "Menu Test 5 - Menu Strategy Context" << endl;
    complete = TestWeatherMenuStrategyContext();
    TestComplete(complete);
    cout << endl;

    cout << "Menu Test Complete" << endl;
    cout << endl;
}
