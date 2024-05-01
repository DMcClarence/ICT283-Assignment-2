#include "VectorTest.h"

#include "../includes/Vector.h"

#include <iostream>

using std::cout;
using std::endl;

int TestVectorDefaultConstructor()
{
    Vector<int> vec;

    return 0;
}

int TestVectorNonDefaultConstructor(int vecSize)
{
    Vector<int> vec(vecSize);

    return 0;
}

int TestVectorCopyConstructor(int vecSize)
{
    Vector<int> vec1(vecSize);
    Vector<int> vec2(vec1);

    return 0;
}

int TestVectorAssignmentOperator(int vecSize)
{
    Vector<int> vec1(vecSize);
    Vector<int> vec2;

    vec2 = vec1;

    return 0;
}

int TestGetSize(int vecSize)
{
    Vector<int> vec(vecSize);

    int size = vec.GetSize();

    cout << "Size = " << size << endl;
    cout << endl;

    return 0;
}

int TestDestructor(int vecSize)
{
    Vector<int> vec(vecSize);
    vec.~Vector();

    int size = vec.GetSize();

    cout << "Size = " << size << endl;
    cout << endl;

    return 0;
}

int TestPushBack(int vecSize, int value)
{
    Vector<int> vec(vecSize);
    bool success = vec.PushBack(value);

    int size = vec.GetSize();

    cout << "Size = " << size << endl;
    cout << "Success? = " << success << endl;
    cout << endl;

    return 0;
}

int TestPopBack(int vecSize, int value)
{
    Vector<int> vec(vecSize);
    vec.PushBack(value);
    bool success = vec.PopBack();

    int size = vec.GetSize();

    cout << "Size = " << size << endl;
    cout << "Success? = " << success << endl;
    cout << endl;

    return 0;
}

int TestVectorArrayIndexOperator(int vecSize, int value, int loc)
{
    Vector<int> vec(vecSize);
    vec.PushBack(value);
    vec.PushBack(value);
    vec.PushBack(value);
    vec.PushBack(value);

    int size = vec.GetSize();

    cout << "Size = " << size << endl;
    cout << "Item = " << vec[loc] << endl;
    cout << endl;

    return 0;
}
