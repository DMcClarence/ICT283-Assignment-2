#include "../includes/BST.h"
#include <iostream>

//----------------------------------------------------------------------------
IntTreeNode::IntTreeNode(int data, IntTreeNode *left, IntTreeNode *right)
{
    m_data = data;
    m_left = left;
    m_right = right;
}

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
    Copy(m_root, bst.m_root);
}

//----------------------------------------------------------------------------
intBst& intBst::operator=(const intBst& bst)
{
    if(this != &bst)
    {
        Copy(m_root, bst.m_root);
    }

    return *this;
}

//----------------------------------------------------------------------------
void intBst::Copy(IntTreeNode *newRoot, IntTreeNode *node)
{
    if(node == nullptr)
    {
        newRoot = nullptr;
    }
    else
    {
        newRoot = new IntTreeNode(node->m_data);
        Copy(newRoot->m_left, node->m_left);
        Copy(newRoot->m_right, node->m_right);
    }
}

//----------------------------------------------------------------------------
void intBst::Insert(int data)
{
    Insert(data, m_root);
}

//----------------------------------------------------------------------------
void intBst::Insert(int data, IntTreeNode *&node)
{
    if(node == nullptr)
    {
        node = new IntTreeNode(data);
        return;
    }

    if(data < node->m_data)
    {
        Insert(data, node->m_left);
        return;
    }

    if(data >= node->m_data)
    {
        Insert(data, node->m_right);
        return;
    }
}

//----------------------------------------------------------------------------
void intBst::InOrder()
{
    InOrder(m_root);
}

//----------------------------------------------------------------------------
void intBst::InOrder(IntTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    InOrder(node->m_left);
    std::cout << node->m_data << std::endl;
    InOrder(node->m_right);
}

//----------------------------------------------------------------------------
void intBst::PreOrder()
{
    PreOrder(m_root);
}

//----------------------------------------------------------------------------
void intBst::PreOrder(IntTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    std::cout << node->m_data << std::endl;
    InOrder(node->m_left);
    InOrder(node->m_right);
}

//----------------------------------------------------------------------------
void intBst::PostOrder()
{
    PostOrder(m_root);
}

//----------------------------------------------------------------------------
void intBst::PostOrder(IntTreeNode *node)
{
    if(node == nullptr)
    {
        return;
    }

    InOrder(node->m_left);
    InOrder(node->m_right);
    std::cout << node->m_data << std::endl;
}

//----------------------------------------------------------------------------
void intBst::Delete(IntTreeNode *&node)
{
    if(node == nullptr)
    {
        return;
    }

    Delete(node->m_left);
    Delete(node->m_right);
    delete node;
    node = nullptr;
}

//----------------------------------------------------------------------------
