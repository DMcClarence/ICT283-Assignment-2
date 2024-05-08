#include "../includes/BST.h"
#include <iostream>

//----------------------------------------------------------------------------
intBst::intBst()
{
    m_root = nullptr;
}

//----------------------------------------------------------------------------
intBst::~intBst()
{
    Delete(m_root);
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
    Insert(data, m_root);
}

//----------------------------------------------------------------------------
void intBst::Insert(int data, IntTreeNode *node)
{
    if(node == nullptr)
    {
        node = new IntTreeNode(data);
        return;
    }

    if(data < m_data)
    {
        Insert(data, node.m_left);
        return;
    }

    if(data >= m_data)
    {
        Insert(data, node.m_right);
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
void intBst::Delete(IntTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    Delete(m_left);
    Delete(m_right);
    delete node;
    node = nullptr;
}

//----------------------------------------------------------------------------
