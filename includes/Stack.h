// Stack.h - Stack class definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

//---------------------------------------------------------------------------------

#include <stack>

//---------------------------------------------------------------------------------

	/**
	 * @class Stack
	 * @brief  Stores data in a Stack Structure
	 *
	 * @author 34085068
	 * @version 01
	 * @date 01/05/2024 34085068, Started
	 */
template <class T>
class Stack
{
public:
    Stack();

        /**
         * @brief Pushes a value onto the top of the Stack.
         *
         *
         * @param data - The value to add to the Stack.
         * @return bool - Returns true if successful, and false if fail.
         */
    bool Push(T &data);

        /**
         * @brief Pops a value off the top of the Stack.
         *
         *
         * @param data - The value removed from the Stack.
         * @return bool - Returns true if successful, and false if fail.
         */
    bool Pop(T &data);

        /**
         * @brief Returns Empty Status of the Stack
         *
         *
         * @return  - Returns true if empty, and false if not empty.
         */
    bool IsEmpty();
private:
        /// The Stack Structure
    std::stack<T> m_stack;
};

//---------------------------------------------------------------------------------
template <class T>
Stack<T>::Stack()
{
}

//---------------------------------------------------------------------------------
template <class T>
bool Stack<T>::Push(T &data)
{
    try
    {
        m_stack.push(data);
    }
    catch(std::bad_alloc& ba)
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------
template <class T>
bool Stack<T>::Pop(T &data)
{
    if(m_stack.empty())
    {
        return false;
    }

    data = m_stack.top();
    m_stack.pop();

    return true;
}

//---------------------------------------------------------------------------------
template <class T>
bool Stack<T>::IsEmpty()
{
    return m_stack.empty();
}

//---------------------------------------------------------------------------------

#endif // STACK_H_INCLUDED

//---------------------------------------------------------------------------------
