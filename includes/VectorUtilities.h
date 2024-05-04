// VectorUtilities.h - Vector class Utilities definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef VECTORUTILITIES_H_INCLUDED
#define VECTORUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "Vector.h"
#include <algorithm>
#include <iostream>

//---------------------------------------------------------------------------------

	/**
	 * @file VectorUtilities.h
	 * @brief  Defines and Implements Utility Functions for the Vector class
	 *
	 * @author 34085068
	 * @version 01
	 * @date 18/04/2024 34085068, Started
	 */

//---------------------------------------------------------------------------------

//    /**
//     * @brief Inserts a value at a specified location in a Vector.
//     *
//     *
//     * @param vec - The Vector to insert the value to
//     * @param value - The value to be inserted
//     * @param location - The index of the array
//     * @return bool - True if value inserted Sucessfully, False if insert fails
//     */
//template <class T>
//bool InsertToVector(Vector<T> &vec, const T value, int location);
//
//    /**
//     * @brief Removes a value at a specified location in a Vector.
//     *
//     *
//     * @param vec - The Vector for the value to be removed from
//     * @param location - The index of the array
//     * @return void
//     */
//template <class T>
//void RemoveFromVector(Vector<T> &vec, int location);

//template <class T>
//bool SortVector(Vector<T> &vec);

template <class T>
bool MergeSortVector(Vector<T> &vec, int first, int last);

template <class T>
bool MergeVector(Vector<T> &vec, int first, int middle, int last);

//---------------------------------------------------------------------------------

//template <class T>
//bool InsertToVector(Vector<T> &vec, const T value, int location)
//{
//        // Create New Vector to add old and new Values to
//    int newVecSize = vec.GetSize() + 1;
//    Vector<T> temp(newVecSize);
//
//        // Populates the Vector
//    for(int i = 0; i < newVecSize; i++)
//    {
//            // Adds previous Values before the new Value Location
//        if(i < location)
//        {
//            temp.PushBack(vec[i]);
//        }
//            // Adds New Value to Specified Location
//        else if(i == location)
//        {
//            temp.PushBack(value);
//        }
//            // Adds Remaining Values from Original Vector after new Value
//        else
//        {
//            temp.PushBack(vec[i - 1]);
//        }
//    }
//
//        // Deletes Old Vector and Copies new One into vec to return New Vector
//    vec.~Vector();
//    vec = temp;
//
//    return true;
//}
//
////---------------------------------------------------------------------------------
//template <class T>
//void RemoveFromVector(Vector<T> &vec, int location)
//{
//        // Creates new Vector to add old Values without Value from Specified Location
//    int newVecSize = vec.GetSize() - 1;
//    Vector<T> temp(newVecSize);
//
//    for(int i = 0; i < newVecSize; i++)
//    {
//            // Adds all old Values before Specified Location
//        if(i < location)
//        {
//            temp.PushBack(vec[i]);
//        }
//            // Adds all old Values after Specified Location
//        else
//        {
//            temp.PushBack(vec[i + 1]);
//        }
//    }
//
//        // Deletes Old Vector and Copies new One into vec to return New Vector
//    vec.~Vector();
//    vec = temp;
//}

//---------------------------------------------------------------------------------
//template <class T>
//bool SortVector(Vector<T> &vec);
//{
//    try
//    {
//        std::sort(VectorIteratorBegin, VectorIteratorEnd);
//    }
//    catch(...)
//    {
//        return false;
//    }
//
//    return true;
//}
//---------------------------------------------------------------------------------
template <class T>
bool MergeSortVector(Vector<T> &vec, int first, int last)
{
    if(first >= last)
    {
        return true;
    }

    int middle = (first + last) / 2;
    MergeSortVector(vec, first, middle);
    MergeSortVector(vec, middle + 1, last);
    MergeVector(vec, first, middle, last);

    return false;
}

template <class T>
bool MergeVector(Vector<T> &vec, int first, int middle, int last)
{
    int leftVecSize = (middle - first) + 1;
    int rightVecSize = last - middle;

    Vector<T> left;
    Vector<T> right;
    for(int i = 0; i < leftVecSize; i++)
    {
        left.PushBack(vec[first + i]);
    }
    for(int j = 0; j < rightVecSize; j++)
    {
        right.PushBack(vec[middle + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = first;

    while(i < leftVecSize && j < rightVecSize)
    {
        if(left[i] <= right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < leftVecSize)
    {
        vec[k] = left[i];
        i++;
        k++;
    }

    while(j < rightVecSize)
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}
//---------------------------------------------------------------------------------

#endif // VECTORUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
