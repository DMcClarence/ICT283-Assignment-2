// BST.h - Binary Search Tree class definition/interface
//---------------------------------------------------------------------------------

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

//---------------------------------------------------------------------------------

#include <cassert>
#include <stdexcept>

//---------------------------------------------------------------------------------

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
	 *
	 * @author 34085068
	 * @version 03
	 * @date 20/05/2024 Modify to be complete minimal BST class.
     *
	 * @author 34085068
	 * @version 04
	 * @date 27/05/2024 Move TreeNode to be Apart of BST class.
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
         * Used for
         *
         *
         * @return void
         */
    void InOrder(void (*ProcessNode)(const T&));

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of self, left node, right node.
         *
         *
         * @return void
         */
    void PreOrder(void (*ProcessNode)(const T&));

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of left node, right node, self.
         *
         *
         * @return void
         */
    void PostOrder(void (*ProcessNode)(const T&));

        /**
         * @brief  Searches BST for the existence of an item.
         *
         *
         * @return bool - Returns true if item is found. Otherwise returns false.
         */
    bool Search(const T& item);

        /**
         * @brief  Deletes an Item from the Tree
         *
         *
         * @return bool - Returns true if item is found. Otherwise returns false.
         */
    void Delete(const T& item);
private:
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
         * @author 34085068
         * @version 03
         * @date 27/05/2024 Move TreeNode to be Apart of BST class.
         */
    template <class T2>
    struct TreeNode
    {
            /// Node Data
        T2 m_data;
            /// Left Node
        TreeNode<T2> *m_left = nullptr;
            /// Right Node
        TreeNode<T2> *m_right = nullptr;
    };

        /**
         * @brief  Recursively copies TreeNodes
         *
         *
         * @param newNode - The new Node
         * @param node - The node to be copied
         * @return void
         */
    void Copy(TreeNode<T> *&newNode, TreeNode<T> *node);

        /**
         * @brief  Deletes a Single TreeNode from a BST
         *
         *
         * @param deleteNode - The node to be deleted
         * @return void
         */
    void DeleteNode(TreeNode<T>*& deleteNode);

        /**
         * @brief  Recursively Deletes an Entire BST
         *
         *
         * @param node - The Current Node
         * @return void
         */
    void DeleteTree(TreeNode<T>*& node);

        /**
         * @brief  Recursively Inserts a TreeNode into a BST
         *
         *
         * @param data - The data to stored
         * @param node - The node to insert
         * @return void
         */
    void Insert(const T& data, TreeNode<T> *&node);

        /**
         * @brief  Recursively Processes each Node in a BST in In Order
         *
         *
         * @param ProcessNode - The function to Process each node
         * @param node - The Current Node
         * @return void
         */
    void InOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node);

        /**
         * @brief  Recursively Processes each Node in a BST in Pre Order
         *
         *
         * @param ProcessNode - The function to Process each node
         * @param node - The Current Node
         * @return void
         */
    void PreOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node);

        /**
         * @brief  Recursively Processes each Node in a BST in Post Order
         *
         *
         * @param ProcessNode - The function to Process each node
         * @param node - The Current Node
         * @return void
         */
    void PostOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node);

        /**
         * @brief  Searches the BST for a Specific Data item
         *
         *
         * @param tree - The Tree to Search
         * @param item - The Item to search for
         * @return TreeNode - The node containing the item
         */
    TreeNode<T>*& SearchTree(BST<T>& tree, const T& item);

        /**
         * @brief  Checks the Representation Invariant Property of the BST Holds True
         *
         * If violated the program will assert.
         *
         *
         * @param node - The node being checked
         * @return void
         */
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
    DeleteTree(m_root);
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
        if(m_root != nullptr)
        {
            DeleteTree();
        }
        Copy(m_root, bst.m_root);
    }

    return *this;
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Copy(TreeNode<T> *&newRoot, TreeNode<T> *node)
{
    if(node == nullptr)
    {
        newRoot = nullptr;
    }
    else
    {
        newRoot = new TreeNode<T>;
        newRoot->m_data = node->m_data;
        Copy(newRoot->m_left, node->m_left);
        Copy(newRoot->m_right, node->m_right);
    }
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Insert(const T& data)
{
    Insert(data, m_root);
    MaintainRI(m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Insert(const T& data, TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        node = new TreeNode<T>;
        node->m_data = data;
        return;
    }

    if(data < node->m_data)
    {
        Insert(data, node->m_left);
        return;
    }

    if(data > node->m_data)
    {
        Insert(data, node->m_right);
        return;
    }
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::InOrder(void (*ProcessNode)(const T&))
{
    InOrder(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::InOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        return;
    }

    InOrder(ProcessNode, node->m_left);
    (*ProcessNode)(node->m_data);
    InOrder(ProcessNode, node->m_right);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PreOrder(void (*ProcessNode)(const T&))
{
    PreOrder(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PreOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        return;
    }

    (*ProcessNode)(node->m_data);
    PreOrder(ProcessNode, node->m_left);
    PreOrder(ProcessNode, node->m_right);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PostOrder(void (*ProcessNode)(const T&))
{
    PostOrderTraversal(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PostOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node)
{
    if(node == nullptr)
    {
        return;
    }

    PostOrder(ProcessNode, node->m_left);
    PostOrder(ProcessNode, node->m_right);
    (*ProcessNode)(node->m_data);
}

//----------------------------------------------------------------------------
template <class T>
bool BST<T>::Search(const T& item)
{
    TreeNode<T>*& node = SearchTree(*this, item);
    if(node == nullptr)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
template <class T>
BST<T>::TreeNode<T>*& BST<T>::SearchTree(BST<T>& tree, const T& item)
{
    TreeNode<T>*& current = tree.m_root;

    while(current != nullptr && current->m_data != item)
    {
        if(item < current->m_data)
        {
            current = current->m_left;
        }
        else
        {
            current = current->m_right;
        }
    }

    return current;
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
        Delete(m_root->m_data);
        assert(leftValid && rightValid); // Might just throw an error instead of asserting?
    }

    MaintainRI(node->m_left);
    MaintainRI(node->m_right);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::Delete(const T& data)
{
            // Implemented from: C++ Programming: Program Design Including Data Structures
                            // By D.S. Malik

    TreeNode<T>* current = nullptr;
    TreeNode<T>* currentParent = nullptr;
    bool found = false;

    current = m_root;
    currentParent = m_root;

    while(current != nullptr && !found)
    {
        if(current->m_data == data)
        {
            found = true;
        }
        else
        {
            currentParent = current;
            if(current->m_data > data)
            {
                current = current->m_left;
            }
            else
            {
                current = current->m_right;
            }
        }

        if(found)
        {
            if(current == m_root)
            {
                DeleteNode(m_root);
            }
            else if(currentParent->m_data > data)
            {
                DeleteNode(currentParent->m_left);
            }
            else
            {
                DeleteNode(currentParent->m_right);
            }
        }
    }

    MaintainRI(m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::DeleteNode(TreeNode<T>*& deleteNode)
{
        // Implemented from: C++ Programming: Program Design Including Data Structures
                            // By D.S. Malik

    TreeNode<T>* current = nullptr;
    TreeNode<T>* currentParent = nullptr;
    TreeNode<T>* temp = nullptr;

    if(deleteNode == nullptr)
    {
        return;
    }

        // Case 1: Node has no Children
    if(deleteNode->m_left == nullptr && deleteNode->m_right == nullptr)
    {
        delete deleteNode;
        deleteNode = nullptr;
    }  // Case 2: Node only has Right Child
    else if(deleteNode->m_left == nullptr)
    {
        temp = deleteNode;
        deleteNode = temp->m_right;
        delete temp;
    }  // Case 3: Node only has Left Child
    else if(deleteNode->m_right == nullptr)
    {
        temp = deleteNode;
        deleteNode = temp->m_left;
        delete temp;
    }  // Case 4: Node has 2 Children
    else
    {
        current = deleteNode->m_left;

        while(current->m_right != nullptr)
        {
            currentParent = current;
            current = current->m_right;
        }

        deleteNode->m_data = current->m_data;

        if(currentParent == nullptr)
        {
            deleteNode->m_left = current->m_left;
        }
        else
        {
            currentParent->m_right = current->m_left;
        }

        delete current;
    }
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::DeleteTree(TreeNode<T>*& node)
{
    if(node == nullptr)
    {
        return;
    }

    DeleteTree(node->m_left);
    DeleteTree(node->m_right);
    delete node;
    node == nullptr;
}

//----------------------------------------------------------------------------

#endif // BST_H_INCLUDED

//----------------------------------------------------------------------------
