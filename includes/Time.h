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
             * @return void
             */
        void SetSeconds(int secs);

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
