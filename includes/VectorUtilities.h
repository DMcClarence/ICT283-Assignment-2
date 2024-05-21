// VectorUtilities.h - Vector class Utilities definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef VECTORUTILITIES_H_INCLUDED
#define VECTORUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "Vector.h"
#include "WeatherRecIO.h"

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

    /**
     * @brief Removes a value at a specified location in a Vector.
     *
     *
     * @param vec - The Vector for the value to be removed from
     * @param location - The index of the array
     * @return void
     */
template <class T>
void RemoveFromVector(Vector<T> &vec, int location);

    /**
     * @brief Sorts a Vector using the Merge Sort Algorithm
     *
     *
     * @param vec - The Vector to be sorted
     * @return void
     */
template <class T>
void MergeSortVector(Vector<T> &vec);

    /**
     * @brief Sorts a Vector using the Merge Sort Algorithm
     *
     *
     * @param vec - The Vector to be sorted
     * @param first - The first index of the Vector
     * @param last - The last index of the Vector
     * @return void
     */
template <class T>
void MergeSortVector(Vector<T> &vec, int first, int last);

    /**
     * @brief
     *
     *
     * @param vec - The Vector
     * @param first
     * @param middle
     * @param last
     * @return void
     */
template <class T>
void MergeVector(Vector<T> &vec, int first, int middle, int last);

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
//---------------------------------------------------------------------------------
template <class T>
void RemoveFromVector(Vector<T> &vec, int location)
{
        // Creates new Vector to add old Values without Value from Specified Location
    Vector<T> temp;

    for(int i = 0; i < vec.GetSize() - 1; i++)
    {
            // Adds all old Values before Specified Location
        if(i < location)
        {
            temp.PushBack(vec[i]);
        }
            // Adds all old Values after Specified Location
        else
        {
            temp.PushBack(vec[i + 1]);
        }
    }

        // Copies new Vector into original Vector
    vec = temp;
}

//---------------------------------------------------------------------------------
template <class T>
void MergeSortVector(Vector<T> &vec)
{
    int first = 0;
    int last = vec.GetSize() - 1;

    MergeSortVector(vec, first, last);
}

//---------------------------------------------------------------------------------
template <class T>
void MergeSortVector(Vector<T> &vec, int first, int last)
{
        // Returns if Vector is already sorted
    if(first >= last)
    {
        return;
    }

        // Find middle of Vector
    int middle = first + (last - first) / 2;
        // Sort the first half
    MergeSortVector(vec, first, middle);
        // Sort the second half
    MergeSortVector(vec, middle + 1, last);
        // Merge the two halves together
    MergeVector(vec, first, middle, last);
}

//---------------------------------------------------------------------------------
template <class T>
void MergeVector(Vector<T> &vec, int first, int middle, int last)
{
    int leftVecSize = (middle - first) + 1;
    int rightVecSize = last - middle;

    T *left = new T[leftVecSize];
    T *right = new T[rightVecSize];

        // Populate the two subvectors
    for(int i = 0; i < leftVecSize; i++)
    {
        left[i] = vec[first + i];
    }
    for(int j = 0; j < rightVecSize; j++)
    {
        right[j] = vec[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = first;

        // Add each element to the original vector from smallest to largest
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

        // Add Remaining elements to original Vector
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

    delete [] left;
    delete [] right;
}
//---------------------------------------------------------------------------------

#endif // VECTORUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
