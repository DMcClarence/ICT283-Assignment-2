#include "../includes/BST.h"
#include <assert.h>
#include <iostream>

//----------------------------------------------------------------------------
bool intBst::Search(int item)
{
    bool found = false;
    Search(item, m_root, found);
    return found;
}

//----------------------------------------------------------------------------
void intBst::Search(int item, IntTreeNode *node, bool &found)
{
    if(found == true || node == nullptr)
    {
        return;
    }

    if(node->m_data == item)
    {
        found = true;
        return;
    }

    if(item < node->m_data)
    {
        Search(item, node->m_left, found);
    }
    else
    {
        Search(item, node->m_right, found);
    }
}

//----------------------------------------------------------------------------
void intBst::MaintainRI(IntTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    bool leftValid = true;
    bool rightValid = true;
    if(node->m_left != nullptr)
    {
        leftValid = (node->m_left->m_data < node->m_data);
    }

    if(node->m_right != nullptr)
    {
        rightValid = (node->m_right->m_data > node->m_data);
    }

    if(!leftValid || !rightValid)
    {
        Delete(m_root);
        assert(!leftValid || !rightValid);
    }

    MaintainRI(node->m_left);
    MaintainRI(node->m_right);
}

//----------------------------------------------------------------------------
