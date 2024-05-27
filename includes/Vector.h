// Vector.h - Vector class definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <vector>
#include <cassert>
#include <stdexcept>

//---------------------------------------------------------------------------------

	/**
	 * @class Vector
	 * @brief  Encapsulates an STL Vector
	 *
	 * @author 34085068
	 * @version 01
	 * @date 28/03/2024 34085068, Started
	 *
	 * @author 34085068
	 * @version 01
	 * @date 29/04/2024 34085068, Refactor Vector to use STL Vector
	 */
template <class T>
class Vector
{
public:
        /**
         * @brief  Creates a Vector object with a Size and Capacity of 1.
         *
         *
         */
    Vector();

        /**
         * @brief  Deletes A Vector Object.
         *
         *
         */
    ~Vector();

        /**
         * @brief Returns a Reference to a value in an array
         *
         *
         * @param  index - The location of the array
         * @return T& - Reference to value in the array
         */
    T& operator[](int index);

        /**
         * @brief Returns a const Reference to a value in an array
         *
         *
         * @param  index - The location of the array
         * @return T& - Const Reference to value in the array
         */
    const T& operator[](int index) const;

        /**
         * @brief  Returns the size of the Vector Object.
         *
         *
         * @return int - The Size of the Vector
         */
    int GetSize() const;

        /**
         * @brief Inserts a value at the end of the array.
         *
         *
         * @return void
         */
    bool PushBack(const T &value);

        /**
         * @brief Removes the value at the end of the array.
         *
         *
         * @return void
         */
    bool PopBack();
private:
        ///Encapsulated STL Vector
    std::vector<T> m_vector;

};

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::Vector()
{
    m_vector.clear();
}

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::~Vector()
{
    m_vector.clear();
}

//---------------------------------------------------------------------------------
template <class T>
T& Vector<T>::operator[](int index)
{
    assert(index >= 0 && index < m_vector.size());
    return m_vector[index];
}

//---------------------------------------------------------------------------------
template <class T>
const T& Vector<T>::operator[](int index) const
{
    assert(index >= 0 && index < m_vector.size());
    return m_vector[index];
}

//---------------------------------------------------------------------------------
template <class T>
int Vector<T>::GetSize() const
{
    return m_vector.size();
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::PushBack(const T &value)
{
    try
    {
        m_vector.push_back(value);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::PopBack()
{
    if(m_vector.size() < 0)
    {
        return false;
    }

    m_vector.pop_back();

    return true;
}

//---------------------------------------------------------------------------------

#endif // VECTOR_H_INCLUDED

//---------------------------------------------------------------------------------
