template <class T>
void printNodeData(const T& data)
{
    std::cout << data << std::endl;
}

    BST<int> intTree;
    intTree.Insert(4);
    intTree.Insert(2);
    intTree.Insert(6);
    intTree.Insert(5);
    intTree.InOrder(printNodeData);
    std::cout << std::endl;
    intTree.PreOrder(printNodeData);
    std::cout << std::endl;
    intTree.PostOrder(printNodeData);
    std::cout << std::endl;
    bool found;
    found = intTree.Search(6);
    std::cout << found << std::endl;
    found = intTree.Search(15);
    std::cout << found << std::endl;

    BST<float> floatTree;
    floatTree.Insert(4);
    floatTree.Insert(2);
    floatTree.Insert(6);
    floatTree.Insert(5);
    floatTree.Delete(6);
    floatTree.InOrder(printNodeData);
    std::cout << std::endl;
    floatTree.PreOrder(printNodeData);
    std::cout << std::endl;
    floatTree.PostOrder(printNodeData);
    std::cout << std::endl;

    BST<Date> dateTree;
    dateTree.Insert(Date(12, 6, 2020));
    dateTree.Insert(Date(17, 5, 2020));
    dateTree.Insert(Date(12, 6, 2021));
    dateTree.Insert(Date(31, 5, 2020));
    dateTree.InOrder(printNodeData);
    std::cout << std::endl;
    dateTree.PreOrder(printNodeData);
    std::cout << std::endl;
    dateTree.PostOrder(printNodeData);
    std::cout << std::endl;
