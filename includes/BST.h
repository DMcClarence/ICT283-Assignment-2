// BST.h - Binary Search Tree class definition/interface
//---------------------------------------------------------------------------------

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

//---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------
    /**
	 * @struct IntTreeNode
	 * @brief  Integer Binary Search Tree Node
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 07/05/2024 Started
	 */
struct IntTreeNode
{
private:
    IntTreeNode(int data, IntTreeNode *left = nullptr, IntTreeNode *right = nullptr);
    int m_data;
    IntTreeNode* m_left;
    IntTreeNode* m_right;
    friend class intBst;
};

IntTreeNode::IntTreeNode(int data, IntTreeNode *left, IntTreeNode *right)
{
    m_data = data;
    m_left = left;
    m_right = right;
}

    /**
	 * @class intBst
	 * @brief  Integer Binary Search Tree
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 07/05/2024 Started
	 */
class intBst
{
public:
        /**
         * @brief  Default Constructor
         *
         *
         */
    intBst();

        /**
         * @brief  Destructor
         *
         *
         */
    ~intBst();

        /**
         * @brief  Copy Constructor
         *
         *
         * @param bst - The BST to Copy
         */
    intBst(const intBst& bst);

        /**
         * @brief  Assignment Operator
         *
         *
         * @param bst - The BST to Copy
         * @return intBst - The Copied BST
         */
    intBst& operator=(const intBst& bst);

        /**
         * @brief  Insert a new node to the BST
         *
         *
         * @param data - The data to store in the new node.
         * @return bool - Returns true if Insert Successful. Otherwise returns false.
         */
    void Insert(int data);

        /**
         * @brief  Executes In-Order Traversal.
         *
         * Processes Nodes in the order of left node, self, right node.
         *
         *
         * @return bool - Returns true if traversal successful. Otherwise returns false.
         */
    void InOrder();

        /**
         * @brief  Executes Pre-Order Traversal.
         *
         * Processes Nodes in the order of self, left node, right node.
         *
         *
         * @return bool - Returns true if traversal successful. Otherwise returns false.
         */
    void PreOrder();

        /**
         * @brief  Executes Post-Order Traversal.
         *
         * Processes Nodes in the order of left node, right node, self.
         *
         *
         * @return bool - Returns true if traversal successful. Otherwise returns false.
         */
    void PostOrder();
private:
        /// Delete Tree Method
    void Delete();

        /// Insert Node to Tree
    void Insert(int data, IntTreeNode *node);

        /// Root Node of the Tree
    IntTreeNode* m_root;
};

#endif // BST_H_INCLUDED
