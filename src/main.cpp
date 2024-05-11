// main.cpp
//
// The main Program
//
// Version
// 01 19/04/2024 34085068
//      Started
//---------------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Includes

#include "../includes/WeatherMenu.h"
#include "../includes/WeatherRecIO.h"
#include "../includes/VectorUtilities.h"
#include "../includes/WeatherRecUtilities.h"
// #include "../includes/Stack.h"
#include "../includes/BST.h"

#include <iostream>
#include <string>

//----------------------------------------------------------------------------
// Global variables/defines

//----------------------------------------------------------------------------
// Prototypes

//----------------------------------------------------------------------------
// Function implementations

int main()
{
//    bool readSuccessful = false;
//    Stack<std::string> fileStack;
//    WeatherLogType weatherLog;
//
//    readSuccessful = GetDataFileNameFromSrcFile(fileStack);
//    if(readSuccessful)
//    {
//        while(!fileStack.IsEmpty())
//        {
//            std::string fileName;
//            fileStack.Pop(fileName);
//            ReadWeatherDataFromFile(fileName, weatherLog);
//        }
//    }
//
//        // Checks weatherLog isn't empty before running Weather Menu
//    if(weatherLog.GetSize() > 0)
//    {
//        RemoveDuplicatesFromWeatherLog(weatherLog);
//        RunWeatherMenu(weatherLog);
//    }
//
    intBst intTree;
    intTree.Insert(4);
    intTree.Insert(2);
    intTree.Insert(6);
    intTree.Insert(5);
    intTree.InOrder();
    std::cout << std::endl;
    intTree.PreOrder();
    std::cout << std::endl;
    intTree.PostOrder();
    std::cout << std::endl;
    bool found;
    found = intTree.Search(6);
    std::cout << found << std::endl;
    found = intTree.Search(15);
    std::cout << found << std::endl;
//
//    BST<float> floatTree;
//    floatTree.Insert(4);
//    floatTree.Insert(2);
//    floatTree.Insert(6);
//    floatTree.Insert(5);
//    floatTree.InOrder();
//    std::cout << std::endl;
//    floatTree.PreOrder();
//    std::cout << std::endl;
//    floatTree.PostOrder();
//    std::cout << std::endl;

    return 0;
}

//----------------------------------------------------------------------------
