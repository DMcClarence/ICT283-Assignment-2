// Map.h - Map class definition/interface and implementation
//---------------------------------------------------------------------------------

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

//---------------------------------------------------------------------------------

#include <map>
#include <utility>

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
         *
         * @param  key - The location in the map
         * @return T2& - Reference to value in the map
         */
    T2& operator[](T1 key);

        /**
         * @brief Returns a const Reference to a value in an map
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

private:
        /// Encapsulated STL Map
    std::map<T1, T2> m_map;
};

//---------------------------------------------------------------------------------
template <class T1, class T2>
Map<T1, T2>::Map()
{

}
//---------------------------------------------------------------------------------
template <class T1, class T2>
Map<T1, T2>::~Map()
{

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

#endif // MAP_H_INCLUDED

//---------------------------------------------------------------------------------
