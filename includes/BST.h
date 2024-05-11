// BST.h - Binary Search Tree class definition/interface
//---------------------------------------------------------------------------------

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

//---------------------------------------------------------------------------------

#include <assert.h>

//---------------------------------------------------------------------------------
    /**
	 * @struct TreeNode
	 * @brief  Binary Search Tree Node
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 07/05/2024 Started
	 *
	 * @author 34085068
	 * @version 02
	 * @date 09/05/2024 Templated and Renamed Class to be reusable with different types.
	 *
	 * @todo Remove Public Traversal Methods
	 * @todo Modify Private Traversal Methods to take function pointers
	 * @todo Modify Methods that Require Traversal to use private Traversal Methods with Function Pointers
	 */
template <class T>
struct TreeNode
{
private:
    TreeNode(T data, TreeNode<T> *left = nullptr, TreeNode<T> *right = nullptr);
    T m_data;
    TreeNode<T> *m_left;
    TreeNode<T> *m_right;

    template <class T2>
    friend class BST;
};

//----------------------------------------------------------------------------
template <class T>
TreeNode<T>::TreeNode(T data, TreeNode<T> *left, TreeNode<T> *right)
{
    m_data = data;
    m_left = left;
    m_right = right;
}

//----------------------------------------------------------------------------

    /**
	 * @class BST
	 * @brief  Binary Search Tree
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 07/05/2024 Started
     *
	 * @author 34085068
	 * @version 02
	 * @date 09/05/2024 Templated and Renamed Class to be reusable with different types.
	 */
template <class T>
class BST
{
public:
        /**
         * @brief  Default Constructor
         *
         *
         */
    BST();

        /**
         * @brief  Destructor
         *
         *
         */
    ~BST();

        /**
         * @brief  Copy Constructor
         *
         *
         * @param bst - The BST to Copy
         */
    BST(const BST<T>& bst);

        /**
         * @brief  Assignment Operator
         *
         *
         * @param bst - The BST to Copy
         * @return *this - The Copied BST
         */
    BST<T>& operator=(const BST<T>& bst);

        /**
         * @brief  Insert a new node to the BST
         *
         *
         * @param data - The data to store in the new node.
         * @return void
         */
    void Insert(const T& data);

        /**
         * @brief  Executes In-Order Traversal.
         *
         * Processes Nodes in the order of left node, self, right node.
         *
         *
         * @return void
         */
    void InOrder();

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of self, left node, right node.
         *
         *
         * @return void
         */
    void PreOrder();

        /**
         * @brief  Executes Post-Order Traversal.
         *
         * Processes Nodes in the order of left node, right node, self.
         *
         *
         * @return void
         */
    void PostOrder();

        /**
         * @brief  Searches BST for the existence of an item.
         *
         *
         * @return bool - Returns true if item is found. Otherwise returns false.
         */
    bool Search(const T& item);
private:
        /// Copy Tree Method
    void Copy(TreeNode<T> *newNode, TreeNode<T> *node);

        /// Delete Tree Method
    void Delete(TreeNode<T> *&node);

        /// Insert Node to Tree
    void Insert(const T& data, TreeNode<T> *&node);

        /// In-order Traversal
    void InOrder(TreeNode<T> *node);

        /// Pre-order Traversal
    void PreOrder(TreeNode<T> *node);

        /// Post-order Traversal
    void PostOrder(TreeNode<T> *node);

        /// Search Tree
    void Search(const T& item, TreeNode<T> *node, bool &found);

        /// Maintain Representation Invariant
    void MaintainRI(TreeNode<T> *node);

        /// Root Node of the Tree
    TreeNode<T>* m_root;
};

//----------------------------------------------------------------------------
template <class T>
BST<T>::BST()
{
    m_root = nullptr;
}

//----------------------------------------------------------------------------
template <class T>
BST<T>::~BST()
{
    Delete(m_root);
    m_root = nullptr;
}

//----------------------------------------------------------------------------
template <class T>
BST<T>::BST(const BST& bst)
{
    Copy(m_root, bst.m_root);
}

//----------------------------------------------------------------------------
template <class T>
BST<T>& BST<T>::operator=(const BST<T>& bst)
{
    if(this != &bst)
    {
        Copy(m_root, bst.m_root);
    }

    return *this;
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Copy(TreeNode<T> *newRoot, TreeNode<T> *node)
{
    if(node == nullptr)
    {
        newRoot = nullptr;
    }
    else
    {
        newRoot = new TreeNode<T>(node->m_data);
        Copy(newRoot->m_left, node->m_left);
        Copy(newRoot->m_right, node->m_right);
    }
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Insert(const T& data)
{
    Insert(data, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Insert(const T& data, TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        node = new TreeNode<T>(data);
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
template <class T>
void BST<T>::InOrder()
{
    InOrder(m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::InOrder(TreeNode<T> *node)
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
template <class T>
void BST<T>::PreOrder()
{
    PreOrder(m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PreOrder(TreeNode<T> *node)
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
template <class T>
void BST<T>::PostOrder()
{
    PostOrder(m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PostOrder(TreeNode<T> *node)
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
template <class T>
bool BST<T>::Search(const T& item)
{
    bool found = false;
    Search(item, m_root, found);

    return found;
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Search(const T& item, TreeNode<T> *node, bool &found)
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
template <class T>
void BST<T>::MaintainRI(TreeNode<T> *node)
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
        assert(false);
    }

    MaintainRI(node->m_left);
    MaintainRI(node->m_right);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Delete(TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        return;
    }

    Delete(node->m_left);
    Delete(node->m_right);
    delete node;
    node = nullptr;

    // PostOrderTraversal(node, functionPtr);
}

//----------------------------------------------------------------------------

#endif // BST_H_INCLUDED
