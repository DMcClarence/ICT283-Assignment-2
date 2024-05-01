// Date.h - Date class definition/interface
//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------
    /**
	 * @class Date
	 * @brief  Date class definition/interface
	 *
	 * Date contains basic member variables and functions for using Dates.
	 *
	 * @author 34085068
	 * @version 01
	 * @date 21/03/2024 Started
	 */
class Date {
    public:
            /**
             * @brief  Constructs a Date object Day and Month set to 1 and Year set to 2000.
             *
             *
             */
        Date();

            /**
             * @brief  Construct a Date object from a day, month, and year.
             *
             *
             * @param d - The day
             * @param m - The month
             * @param y - The year
             */
        Date(int d, int m, int y);

            /**
             * @brief  Returns the day.
             *
             *
             * @return int - The day
             */
        int GetDay() const;

            /**
             * @brief  Returns the month.
             *
             *
             * @return int - The month
             */
        int GetMonth() const;

            /**
             * @brief  Returns the year.
             *
             *
             * @return int - The year
             */
        int GetYear() const;

            /**
             * @brief  Sets the day.
             *
             * Returns true if day is valid and set.
             * Returns false if day not valid and not set.
             *
             *
             * @param d - The day value to set
             * @return bool - Day set (true) or Day not set (false)
             */
        bool SetDay(int d);

            /**
             * @brief  Sets the month.
             *
             * Returns true if month is valid and set.
             * Returns false if month not valid and not set.
             *
             *
             * @param m - The month value to set
             * @return bool -  Month set (true) or Month Not Set (false)
             */
        bool SetMonth(int m);

            /**
             * @brief  Sets the year.
             *
             *
             * @param y - The year value to set
             * @return void
             */
        void SetYear(int y);

    private:
            /// The Day
        int m_day;

            /// The Month
        int m_month;

            /// The Year
        int m_year;
};

//---------------------------------------------------------------------------------

#endif // DATE_H

//---------------------------------------------------------------------------------
