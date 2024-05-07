#include "../../includes/BST.h"
#include <iostream>

//----------------------------------------------------------------------------
intBst::intBst()
{
    m_root = nullptr;
}

//----------------------------------------------------------------------------
intBst::~intBst()
{
    Delete();
    m_root = nullptr;
}

//----------------------------------------------------------------------------
intBst::intBst(const intBst& bst)
{
}

//----------------------------------------------------------------------------
intBst& intBst::operator=(const intBst& bst)
{
}

//----------------------------------------------------------------------------
void intBst::Insert(int data)
{
    if(*this == nullptr)
    {
        *this = new IntTreeNode(data);
        return;
    }

    if(data < m_data)
    {
        m_left.Insert(data);
        return;
    }

    if(data >= m_data)
    {
        m_right.Insert(data);
        return;
    }
}

//----------------------------------------------------------------------------
void intBst::InOrder()
{
    if(*this == nullptr)
    {
        return;
    }

    m_left.InOrder();
    std::cout << data << std::endl;
    m_right.InOrder();
}

//----------------------------------------------------------------------------
void intBst::PreOrder()
{
    if(*this == nullptr)
    {
        return;
    }

    std::cout << data << std::endl;
    m_left.InOrder();
    m_right.InOrder();
}

//----------------------------------------------------------------------------
void intBst::PostOrder()
{
    if(*this == nullptr)
    {
        return;
    }

    m_left.InOrder();
    m_right.InOrder();
    std::cout << data << std::endl;
}

//----------------------------------------------------------------------------
