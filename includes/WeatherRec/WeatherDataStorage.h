// WeatherDataStorage.h - Weather Data Storage definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERDATASTORAGE_H_INCLUDED
#define WEATHERDATASTORAGE_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherRec.h"
#include "../Vector/Vector.h"
#include "../BST/BST.h"
#include "../Map/Map.h"

//---------------------------------------------------------------------------------

    /**
	 * @struct WeatherDataStorage
	 * @brief  Defines WeatherDataStorage Data Structure
	 *
	 * @author 34085068
	 * @version 01
	 * @date 04/06/2024 34085068, Started
	 */
typedef struct
{
        /// The Vector of Weather Records
    WeatherLogType m_weatherLog;

        /// Map of Vector indexes sorted by Year and Month
        /// Outer map key is year, inner map key is month.
    Map<int, Map<int, Vector<int>>> m_weatherLogMap;

        /// BST consisting of Existing Map Keys
        /// Map Keys are a concat of the outer and inner map keys
    BST<int> m_yearMonthBST;
}WeatherDataStorage;

//---------------------------------------------------------------------------------

#endif // WEATHERDATASTORAGE_H_INCLUDED

//---------------------------------------------------------------------------------
