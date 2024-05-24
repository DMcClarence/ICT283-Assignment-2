#include "StackTest.h"

#include "../includes/Stack.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int TestStackDefaultConstructor()
{
        // Integer Stack
    Stack<int> myStack;

        // String Stack
    Stack<string> myStack2;

    return 0;
}

int TestStackPush()
{
            // Integer Stack
    Stack<int> myStack;

    int data = 5;
    bool success = myStack.Push(data);
    cout << "Success? = " << success << endl;
    cout << endl;

        // String Stack
    Stack<string> myStack2;

    string data2 = "test";
    success = myStack2.Push(data2);
    cout << "Success? = " << success << endl;
    cout << endl;

    return 0;
}

int TestStackPop()
{
            // Integer Stack
    Stack<int> myStack;

    int data = 5;
    myStack.Push(data);
    int value;
    bool success = myStack.Pop(value);
    cout << value << endl;
    cout << "Success? = " << success << endl;
    cout << endl;

        // String Stack
    Stack<string> myStack2;

    string data2 = "test";
    myStack2.Push(data2);
    string value2;
    success = myStack2.Pop(value2);
    cout << value2 << endl;
    cout << "Success? = " << success << endl;
    cout << endl;

    return 0;
}

int TestStackPopFromEmptyStack()
{
        // Empty Integer Stack
    Stack<int> myStack;

    int value;
    bool success = myStack.Pop(value);
    cout << "Success? = " << success << endl;
    cout << endl;

        // Empty String Stack
    Stack<string> myStack2;

    string value2;
    success = myStack2.Pop(value2);
    cout << "Success? = " << success << endl;
    cout << endl;

    return 0;
}

int TestStackIsEmpty()
{
        // Empty Integer Stack
    Stack<int> myStack;

    cout << myStack.IsEmpty() << endl;

        // Empty String Stack
    Stack<string> myStack2;

    cout << myStack2.IsEmpty() << endl;

        // Integer Stack
    int data = 5;
    myStack.Push(data);
    cout << myStack.IsEmpty() << endl;

        // String Stack
    string data2 = "test";
    myStack2.Push(data2);
    cout << myStack2.IsEmpty() << endl;

    return 0;
}
