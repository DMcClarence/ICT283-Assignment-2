#include "TimeTest.h"

#include "../includes/Time.h"

#include <iostream>

using std::cout;
using std::endl;

int TestTimeDefaultConstructor()
{
    Time t();

    return 0;
}

int TestTimeNonDefaultConstructor()
{
    Time t(10, 25, 15);

    return 0;
}

int TestGetHours()
{
    Time t(10, 25, 15);
    int hrs = t.GetHours();
    cout << hrs << endl;

    return 0;
}

int TestGetMinutes()
{
    Time t(10, 25, 15);
    int mins = t.GetMinutes();
    cout << mins << endl;

    return 0;
}

int TestGetSeconds()
{
    Time t(10, 25, 15);
    int secs = t.GetSeconds();
    cout << secs << endl;

    return 0;
}

int TestSetHours()
{
    Time t;
    t.SetHours(10);
    int hrs = t.GetHours();
    cout << hrs << endl;

    return 0;
}

int TestSetMinutes()
{
    Time t;
    t.SetMinutes(25);
    int mins = t.GetMinutes();
    cout << mins << endl;

    return 0;
}

int TestSetSeconds()
{
    Time t;
    t.SetSeconds(15);
    int secs = t.GetSeconds();
    cout << secs << endl;

    return 0;
}
