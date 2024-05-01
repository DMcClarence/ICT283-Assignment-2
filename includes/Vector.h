// Vector.h - Vector class definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

//---------------------------------------------------------------------------------

#include <assert.h>

//---------------------------------------------------------------------------------

	/**
	 * @class Vector
	 * @brief  Stores and manages Data in a Dynamic Array
	 *
	 * @author 34085068
	 * @version 01
	 * @date 28/03/2024 34085068, Started
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
             * @brief  Creates a Vector object with an initial Capacity.
             *
             *
             * @param  intitalCapacity - The initial Capacity for the Dynamic Array
             */
       explicit Vector(int initialCapacity);

            /**
             * @brief Creates a Vector Object from another Vector Object
             *
             *
             * @param  v - The Vector Object to be Copied
             */
        Vector(const Vector<T>& v);

            /**
             * @brief  Deletes A Vector Object.
             *
             *
             */
        ~Vector();

            /**
             * @brief Copies a Vector Object to another Vector Object
             *
             *
             * @param  rhs - The Vector Object to be Copied
             * @return Vector<T>& - The original vector with the new values
             */
        Vector<T>& operator=(const Vector<T> &rhs);

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
            ///Copy Method
        bool Copy(const Vector<T> &rhs);

            ///Increase Capacity of Vector
        bool IncreaseCapacity();

            ///Dynamic Array
        T *m_arr;

            ///Number of Elements
        int m_arrSize;

            ///Max Number of Elements
        int m_arrCapacity;

};

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::Vector()
{
    m_arrSize = 0;
    m_arrCapacity = 1;
    m_arr = new T[m_arrCapacity];
    assert(m_arr != nullptr);
}

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::Vector(int initialCapacity)
{
    m_arrSize = 0;
    m_arrCapacity = initialCapacity;
    m_arr = new T[m_arrCapacity];
    assert(m_arr != nullptr);
}

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
    m_arr = nullptr;
    Copy(v);
}

//---------------------------------------------------------------------------------
template <class T>
Vector<T>::~Vector()
{
    m_arrSize = 0;
    m_arrCapacity = 0;

    if(m_arr != nullptr)
    {
        delete [] m_arr;
    }
    m_arr = nullptr;
}

//---------------------------------------------------------------------------------
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T> &rhs)
{
    if(this != &rhs)
    {
        Copy(rhs);
    }

    return *this;
}

//---------------------------------------------------------------------------------
template <class T>
T& Vector<T>::operator[](int index)
{
    assert(index >= 0 && index < m_arrSize);
    return m_arr[index];
}

//---------------------------------------------------------------------------------
template <class T>
const T& Vector<T>::operator[](int index) const
{
    assert(index >= 0 && index < m_arrSize);
    return m_arr[index];
}

//---------------------------------------------------------------------------------
template <class T>
int Vector<T>::GetSize() const
{
    return m_arrSize;
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::Copy(const Vector<T> &rhs)
{
    if(rhs.m_arr != nullptr)
    {
        m_arrSize = rhs.m_arrSize;
        m_arrCapacity = rhs.m_arrCapacity;
        m_arr = new T[rhs.m_arrCapacity];
        if(m_arr != nullptr)
        {
            for(int i = 0; i < rhs.m_arrSize; i++)
            {
                m_arr[i] = rhs.m_arr[i];
            }
            return true;
        }
    }

    return false;
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::IncreaseCapacity()
{
    if(m_arrCapacity > 0)
    {
        Vector<T> temp;

            // Increase Capacity of Old Vector so when copied into temp Vector,
            // This new Capacity Value will be used to create the Dynamic Array
        m_arrCapacity *= 2;

        temp = *this;

            // Reset Vector
        if(m_arr != nullptr)
        {
            delete [] m_arr;
            m_arr = nullptr;
        }

        *this = temp;

        return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::PushBack(const T &value)
{
    if(m_arrSize == m_arrCapacity)
    {
        if(!IncreaseCapacity())
        {
            return false;
        }
    }

    m_arr[m_arrSize] = value;
    m_arrSize++;

    return true;
}

//---------------------------------------------------------------------------------
template <class T>
bool Vector<T>::PopBack()
{
    if(m_arrSize > 0)
    {
        m_arrSize--;
        return true;
    }

    return false;
}

//---------------------------------------------------------------------------------

#endif // VECTOR_H_INCLUDED

//---------------------------------------------------------------------------------
