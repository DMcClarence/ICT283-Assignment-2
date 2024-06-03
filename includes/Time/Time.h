// Time.h - Time class definition/interface
//---------------------------------------------------------------------------------

#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

//---------------------------------------------------------------------------------



//---------------------------------------------------------------------------------

    /**
	 * @class Time
	 * @brief  Defines Time class methods/interface
	 *
	 * @author 34085068
	 * @version 01
	 * @date 08/04/2024 34085068, Started
	 *
	 * @author 34085068
	 * @version 02
	 * @date 04/05/2024 34085068, Add comparison operator overloads as Times have a natural order.
	 */
class Time
{
    public:
            /**
             * @brief  Creates a Time object and Sets Hours, Minutes, and Seconds to 0.
             *
             *
             */
        Time();

            /**
             * @brief  Creates a Time object.
             *
             *
             * @param  hrs - The Hours (Set to the value returned by hrs % 24)
             * @param  mins - The Minutes (Set to the value returned by mins % 60)
             * @param  secs - The Seconds (Set to the value returned by secs % 60)
             */
        Time(int hrs, int mins, int secs);

            /**
             * @brief  Returns the value of Hours.
             *
             *
             * @return int - Value of Hours
             */
        int GetHours() const;

            /**
             * @brief  Returns the value of Minutes.
             *
             *
             * @return int - Value of Minutes
             */
        int GetMinutes() const;

            /**
             * @brief  Returns the value of Seconds.
             *
             *
             * @return int - Value of Seconds
             */
        int GetSeconds() const;

            /**
             * @brief Sets the value of Hours
             *
             * The Hours value is set to hrs % 24.
             * This ensures Hours is always valid.
             *
             * @param hrs - Value of Hours
             * @return void
             */
        void SetHours(int hrs);

            /**
             * @brief Sets the value of Minutes
             *
             * The Hours value is set to mins % 60.
             * This ensures Minutes is always valid.
             *
             * @param mins - Value of Minutes
             * @return void
             */
        void SetMinutes(int mins);

            /**
             * @brief Sets the value of Seconds
             *
             * The Hours value is set to secs % 60.
             * This ensures Seconds is always valid.
             *
             * @param secs - Value of Seconds
             * @return voidTime
             */
        void SetSeconds(int secs);

            /**
             * @brief  Compares dates for equality.
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Dates are Equal. Otherwise returns false.
             */
        bool operator==(Time &right) const;

            /**
             * @brief  Checks if Time is less than another Time
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Time is less than another Time. Otherwise returns false.
             */
        bool operator<(Time &right) const;

            /**
             * @brief  Checks if Time is less than or equal to another Time.
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Time is less than or equal too another Time. Otherwise returns false.
             */
        bool operator<=(Time &right) const;

            /**
             * @brief  Checks if Time is greater than another Time.
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Time is greater than another Time. Otherwise returns false.
             */
        bool operator>(Time &right) const;

            /**
             * @brief  Checks if Time is greater than or equal to another Time.
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Time is less than or equal too another Time. Otherwise returns false.
             */
        bool operator>=(Time &right) const;

            /**
             * @brief  Compares dates for inequality.
             *
             *
             * @param right - Time object to be compared against
             * @return bool - Returns true if Dates are not Equal. Otherwise returns false.
             */
        bool operator!=(Time &right) const;

    private:
            /// Hours: Values 0-23
        int m_hours;

            /// Minutes: Values 0-59
        int m_minutes;

            /// Seconds: Values 0-59
        int m_seconds;
};

//---------------------------------------------------------------------------------

#endif // TIME_H_INCLUDED

//---------------------------------------------------------------------------------
