// BSTUtilities.h - Binary Search Tree Utility Functions definitions/interface
//---------------------------------------------------------------------------------

#ifndef BSTUTILITIES_H_INCLUDED
#define BSTUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------

#include "BST.h"
#include "Vector.h"

//---------------------------------------------------------------------------------

template <class T1, class T2>
void InsertSortedVectorToBST(int start, int end, BST<T1> &bst, Vector<T2> &vec);

//---------------------------------------------------------------------------------

template <class T1, class T2>
void InsertSortedVectorToBST(int start, int end, BST<T1> &bst, Vector<T2> &vec)
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
    InsertSortedVectorToBST(start, (mid - 1), bst, vec);
    InsertSortedVectorToBST((mid + 1), end, bst, vec);
}

//---------------------------------------------------------------------------------

#endif // BSTUTILITIES_H_INCLUDED

//---------------------------------------------------------------------------------
