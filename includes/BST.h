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
    IntTreeNode *m_left;
    IntTreeNode *m_right;
    friend class intBst;
};

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

        /**
         * @brief  Searches BST for the existence of an item.
         *
         *
         * @return bool - Returns true if item is found. Otherwise returns false.
         */
    bool Search(int item);
private:
        /// Copy Tree Method
    void Copy(IntTreeNode *newNode, IntTreeNode *node);

        /// Delete Tree Method
    void Delete(IntTreeNode *&node);

        /// Insert Node to Tree
    void Insert(int data, IntTreeNode *&node);

        /// In-order Traversal
    void InOrder(IntTreeNode *node);

        /// Pre-order Traversal
    void PreOrder(IntTreeNode *node);

        /// Post-order Traversal
    void PostOrder(IntTreeNode *node);

        /// Search Tree
    void Search(int item, IntTreeNode *node, bool &found);

        /// Root Node of the Tree
    IntTreeNode* m_root;
};

#endif // BST_H_INCLUDED
