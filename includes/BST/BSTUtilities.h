// BSTUtilities.h - Binary Search Tree Utility Functions definitions/interface
//---------------------------------------------------------------------------------

#ifndef BSTUTILITIES_H_INCLUDED
#define BSTUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "BST.h"
#include "../Vector/Vector.h"

//---------------------------------------------------------------------------------
    /**
	 * @namespace BSTUtilities
	 * @brief  Defines utility functions for the BST class
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 27/05/2024 Started
	 */
namespace BSTUtilities
{
        /**
         * @brief  Inserts a Sorted Vector into a BST
         *
         *
         * @param start - Index of the start of the Vector
         * @param end - Index of the end of the Vector
         * @param bst - The BST to store the Data
         * @param vec - The Vector the Data is being inserted from.
         * @return void
         */
    template <class T>
    void InsertSortedVectorToBST(int start, int end, BST<T> &bst, Vector<T> &vec);
}

//---------------------------------------------------------------------------------

template <class T>
void BSTUtilities::InsertSortedVectorToBST(int start, int end, BST<T> &bst, Vector<T> &vec)
{
    if(start > end)
    {
        return;
    }

    if(start == end)
    {
        bst.Insert(vec[start]);
        return;
    }

    int mid = (start + end) / 2;
    bst.Insert(vec[mid]);
    BSTUtilities::InsertSortedVectorToBST(start, (mid - 1), bst, vec);
    BSTUtilities::InsertSortedVectorToBST((mid + 1), end, bst, vec);
}

//---------------------------------------------------------------------------------

#endif // BSTUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
