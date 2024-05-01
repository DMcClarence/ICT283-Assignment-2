#include "DateTest.h"

#include "../includes/Date.h"

#include <iostream>

using std::cout;
using std::endl;

int TestGetDay()
{
    Date d(10, 7, 2023);
    int day = d.GetDay();
    cout << day << endl;

    return 0;
}

int TestGetMonth()
{
    Date d(10, 7, 2023);
    int month = d.GetMonth();
    cout << month << endl;

    return 0;
}

int TestGetYear()
{
    Date d(10, 7, 2023);
    int year = d.GetYear();
    cout << year << endl;

    return 0;
}

int TestSetDay()
{
    Date d(10, 7, 2023);
    bool success = d.SetDay(16);
    cout << d.GetDay() << endl;

    return 0;
}

int TestSetMonth()
{
    Date d(10, 7, 2023);
    bool success = d.SetMonth(3);
    cout << d.GetMonth() << endl;

    return 0;
}

int TestSetYear()
{
    Date d(10, 7, 2023);
    d.SetYear(2024);
    cout << d.GetYear() << endl;

    return 0;
}
