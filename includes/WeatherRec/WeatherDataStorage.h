#ifndef WEATHERDATASTORAGE_H_INCLUDED
#define WEATHERDATASTORAGE_H_INCLUDED

#include "WeatherRec.h"
#include "../Vector/Vector.h"
#include "../BST/BST.h"
#include "../Map/Map.h"

struct WeatherDataStorage
{
        ///
    WeatherLogType m_weatherLog;

        /// Outer map key is year, inner map key is month.
    Map<int, Map<int, Vector<int>>> m_weatherLogMap;

        ///
    BST<int> m_yearMonthBST;
};

#endif // WEATHERDATASTORAGE_H_INCLUDED
