// BST.h - Binary Search Tree class definition/interface
//---------------------------------------------------------------------------------

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

//---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------

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
         * @return BST<T> - The Copied BST
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
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @return void
         */
    void InOrder(void (*ProcessNode)(T&)) const;

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of self, left node, right node.
         *
         *
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @return void
         */
    void PreOrder(void (*ProcessNode)(const T&)) const;

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of left node, right node, self.
         *
         *
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @return void
         */
    void PostOrder(void (*ProcessNode)(const T&)) const;

        /**
         * @brief  Searches BST for the existence of an item.
         *
         *
         * @return bool - Returns true if item is found. Otherwise returns false.
         */
    bool Search(const T& item);
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
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @param node - The Current Node
         * @return void
         */
    void InOrder(void (*ProcessNode)(T&), TreeNode<T> *node) const;

        /**
         * @brief  Recursively Processes each Node in a BST in Pre Order
         *
         *
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @param node - The Current Node
         * @return void
         */
    void PreOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node) const;

        /**
         * @brief  Recursively Processes each Node in a BST in Post Order
         *
         *
         * @param ProcessNode - A void Function Pointer that Takes T as a parameter.
         *                       This is the function used to Process each node.
         * @param node - The Current Node
         * @return void
         */
    void PostOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node) const;

        /**
         * @brief  Searches the BST for a Specific Data item
         *
         *
         * @param item - The Item to search for
         * @return TreeNode - The node containing the item
         */
    TreeNode<T>* SearchTree(const T& item);

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
void BST<T>::InOrder(void (*ProcessNode)(T&)) const
{
    InOrder(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::InOrder(void (*ProcessNode)(T&), TreeNode<T> *node) const
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
void BST<T>::PreOrder(void (*ProcessNode)(const T&)) const
{
    PreOrder(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PreOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node) const
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
void BST<T>::PostOrder(void (*ProcessNode)(const T&)) const
{
    PostOrderTraversal(ProcessNode, m_root);
}

//----------------------------------------------------------------------------
template <class T>
void BST<T>::PostOrder(void (*ProcessNode)(const T&), TreeNode<T> *&node) const
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
    const TreeNode<T>* node = SearchTree(item);
    if(node == nullptr)
    {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------
template <class T>
BST<T>::TreeNode<T>* BST<T>::SearchTree(const T& item)
{
    TreeNode<T>* current = m_root;

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
