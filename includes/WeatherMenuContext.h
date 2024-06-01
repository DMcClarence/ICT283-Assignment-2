// WeatherMenuContext.h - WeatherMenuContext class definition/interface
//---------------------------------------------------------------------------------

#ifndef WEATHERMENUCONTEXT_H_INCLUDED
#define WEATHERMENUCONTEXT_H_INCLUDED

//---------------------------------------------------------------------------------

#include "WeatherMenuOptions.h"
#include "WeatherRec.h"

//---------------------------------------------------------------------------------

    /**
	 * @class WeatherMenuContext
	 * @brief  Context Class for the WeatherMenuStrategy Class.
	 *
	 * WeatherMenuContext is a Bridge to Execute Different Weather Menu Options at Runtime
	 *
	 *
	 * @author 34085068
	 * @version 01
	 * @date 18/04/2024 Started
	 *
	 * @author 34085068
	 * @version 02
	 * @date 01/05/2024 Modify to pass functions instead of objects
     *
	 * @author 34085068
	 * @version 03
	 * @date 14/05/2024 Modify to use function pointers instead of std::function
	 */
class WeatherMenuContext
{
    public:
            /**
             * @brief  Default Constructor for WeatherMenuContext Object.
             *
             *
             */
        WeatherMenuContext();

            /// Copy Constructor
            /// Deleted from Class as Object of this Class are not Designed to be Copied.
        WeatherMenuContext(const WeatherMenuContext& menu) = delete;

            /// Assignment operator (=) overload
            /// Deleted from Class as Object of this Class are not Designed to be Copied.
        WeatherMenuContext& operator=(const WeatherMenuContext& menu) = delete;

            /**
             * @brief  Sets the Menu Option to be used.
             *
             *
             * @param menuOption - The Menu Option to be Executed
             * @return bool - Returns true if Set Successful. Returns false if Set Failed.
             */
        bool SetWeatherMenuStrategy(void (*menuOption)(WeatherLogType&, std::map<int, std::map<int, Vector<int>>>&, BST<int>&));

            /**
             * @brief  Executes the WeatherMenuStrategy Object.
             *
             *
             * @param weatherLog - A Vector of WeatherRecType Objects
             * @return bool - Returns true if Execution Successful. Returns false if Execution Failed.
             */
        bool ExecuteWeatherMenuOption(WeatherLogType &weatherLog, std::map<int, std::map<int, Vector<int>>> &myMap, BST<int> &myBst);
    private:
            /// The Menu Option to be Executed.
        void (*m_menuOption)(WeatherLogType&, std::map<int, std::map<int, Vector<int>>>&, BST<int>&);
};

//---------------------------------------------------------------------------------

#endif // WEATHERMENUCONTEXT_H_INCLUDED

//---------------------------------------------------------------------------------
