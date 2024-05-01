#include "WeatherRecUtilitiesTest.h"
#include "../includes/WeatherRecUtilities.h"

#include <iostream>

using std::cout;
using std::endl;

int TestExtractValuesFromWeatherLog()
{
    WeatherLogType log;
    WeatherRecType rec;

    Date d(12, 5, 2023);
    Time t(12, 15, 0);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 6.3;
    rec.m_t = 21;
    rec.m_sr = 12.9;
    log.PushBack(rec);

    t.SetMinutes(16);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 6.9;
    rec.m_t = 21;
    rec.m_sr = 12.3;
    log.PushBack(rec);

    d.SetMonth(6);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 8.9;
    rec.m_t = 26;
    rec.m_sr = 15.0;
    log.PushBack(rec);

    t.SetMinutes(17);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 6.7;
    rec.m_t = 26;
    rec.m_sr = 12.2;
    log.PushBack(rec);

    d.SetYear(2024);
    d.SetMonth(5);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 8.9;
    rec.m_t = 26;
    rec.m_sr = 15.0;
    log.PushBack(rec);

    t.SetMinutes(18);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 6.7;
    rec.m_t = 26;
    rec.m_sr = 12.2;
    log.PushBack(rec);

    d.SetMonth(6);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 8.9;
    rec.m_t = 26;
    rec.m_sr = 15.0;
    log.PushBack(rec);

    t.SetMinutes(19);
    rec.m_date = d;
    rec.m_time = t;
    rec.m_s = 6.7;
    rec.m_t = 26;
    rec.m_sr = 12.2;
    log.PushBack(rec);

    Vector<float> extract;
    ExtractValuesFromWeatherLog(log, 5, 2024, &WeatherRecType::m_s, extract);

    int size = log.GetSize();

    cout << "Size = " << size << endl;
    for(int i = 0; i < extract.GetSize(); i++)
    {
        cout << extract[i] << endl;
    }
    cout << endl;

    return 0;
}

int TestMonthToString()
{
    int month = 4;
    string m = MonthToString(month);

    cout << m << endl;

    return 0;
}

int TestToKMperHr()
{
    float mps = 6;
    ToKMperHr(mps);

    cout << "km/h: " << mps << endl;

    return 0;
}

int TestTokWh()
{
    float Wpm = 1026;
    TokWh(Wpm);

    cout << "kWh/m^2: " << Wpm << endl;

    return 0;
}
