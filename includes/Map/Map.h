// Map.h - Map class definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

//---------------------------------------------------------------------------------

#include <map>

//---------------------------------------------------------------------------------
	/**
	 * @class Map
	 * @brief  Encapsulates an STL Map
	 *
	 * @author 34085068
	 * @version 01
	 * @date 21/05/2024 34085068, Started
	 */
template <class T1, class T2>
class Map
{
public:
        /**
         * @brief  Creates a Default Map object.
         *
         *
         */
    Map();

        /**
         * @brief  Deletes A Map Object.
         *
         *
         */
    ~Map();

        /**
         * @brief Returns a Reference to a value in a map
         *
         * If map key doesn't exist, it will be created and added to the map.
         *
         *
         * @param  key - The location in the map
         * @return T2& - Reference to value in the map
         */
    T2& operator[](T1 key);

        /**
         * @brief Returns a const Reference to a value in an map
         *
         * If map key doesn't exist, it will be created and added to the map.
         *
         *
         * @param  key - The location of the map
         * @return T2& - Const Reference to value in the map
         */
    const T2& operator[](T1 key) const;

        /**
         * @brief Inserts a Key/Value pair into the Map.
         *
         *
         * @return bool - Returns true if successful. Otherwise returns false
         */
    bool Insert(T1 key, T2 value);

        /**
         * @brief Defines an iterator for the Encapsulated STL map Class.
         *
         * Required to be able to traverse the elements of the map.
         *
         *
         */
    typedef typename std::map<T1, T2>::iterator iterator;

        /**
         * @brief Returns an iterator pointing to the first element of the Map.
         *
         *
         * @return iterator - The beginning elemement in the map
         */
    iterator Begin();

        /**
         * @brief Returns an iterator pointing to the element Past the End of the Map.
         *
         * Past the End means the first Address after the Final Element of the Map
         *
         *
         * @return iterator - Element Past the End of the Map
         */
    iterator End();

private:
        /// Encapsulated STL Map
    std::map<T1, T2> m_map;
};

//---------------------------------------------------------------------------------
template <class T1, class T2>
Map<T1, T2>::Map()
{
    m_map.clear();
}
//---------------------------------------------------------------------------------
template <class T1, class T2>
Map<T1, T2>::~Map()
{
    m_map.clear();
}
//---------------------------------------------------------------------------------
template <class T1, class T2>
T2& Map<T1, T2>::operator[](T1 key)
{
    return m_map[key];
}

//---------------------------------------------------------------------------------
template <class T1, class T2>
const T2& Map<T1, T2>::operator[](T1 key) const
{
    return m_map[key];
}

//---------------------------------------------------------------------------------
template <class T1, class T2>
bool Map<T1, T2>::Insert(T1 key, T2 value)
{
    try
    {
        m_map.insert(std::make_pair(key, value));
    }
    catch(...)
    {
        return false;
    }

    return true;
}

//---------------------------------------------------------------------------------
template <class T1, class T2>
typename Map<T1, T2>::iterator Map<T1, T2>::Begin()
{
    return m_map.begin();
}

//---------------------------------------------------------------------------------
template <class T1, class T2>
typename Map<T1, T2>::iterator Map<T1, T2>::End()
{
    return m_map.end();
}

//---------------------------------------------------------------------------------

#endif // MAP_H_INCLUDED

//---------------------------------------------------------------------------------
