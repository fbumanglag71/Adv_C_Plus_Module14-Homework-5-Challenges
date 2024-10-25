#include "Date.h"

//precondition:none
//postcondition:initializes month, day, and year to 0.
Date::Date()
{
    month = 0;
    day = 0;
    year = 0;
}

//precondition:'m' should be a valid month (1-12).
//postcondition:sets 'month' to the provided value if valid.
void Date::setMonth(int m)
{
    month = m;
}

//precondition:'month' must be set.
//postcondition:returns the current 'month' value (1-12).
int Date::getMonth() const
{
    return month;
}

//precondition:'d' should be a valid day for the current month.
//postcondition:sets 'day' to the provided value if valid.
void Date::setDay(int d)
{
    day = d;
}

//precondition:'day' must be set.
//postcondition:returns the current 'day' value.
int Date::getDay() const
{
    return day;
}

//precondition:'y' should be a valid year (non-negative).
//postcondition:sets 'year' to the provided value if valid.
void Date::setYear(int y)
{
    year = y;
}

//precondition:'year' must be set.
//postcondition:returns the current 'year' value.
int Date::getYear() const
{
    return year;
}

//precondition:'month', 'day', and 'year' must be set and valid.
//postcondition:returns date in "month/day/year" format (e.g., "4/18/2018").
string Date::getFormat1() const
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

//precondition:valid 'month', 'day', and 'year' values.
//postcondition:returns "MonthName day, year" format (e.g., "April 18, 2018").
string Date::getFormat2() const
{
    string monthName[13] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return monthName[month] + " " + to_string(day) + ", " + to_string(year);
}

//precondition:valid 'month', 'day', and 'year' values.
//postcondition:returns "day MonthName year" format (e.g., "18 April 2018").
string Date::getFormat3() const
{
    string monthName[13] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return to_string(day) + " " + monthName[month] + " " + to_string(year);
}

//precondition:date must be valid.
//postcondition:increments the day by one, adjusting month/year if needed.
Date& Date::operator++()
{
    if (day < daysInMonth(month, year))
    {
        ++day;
    }
    else
    {
        day = 1;
        if (month == 12)
        {
            month = 1;
            ++year;
        }
        else
        {
            ++month;
        }
    }
    return *this;
}

//precondition:date must be valid.
//postcondition:increments the day by one, returning the previous state.
Date Date::operator++(int)
{
    Date temp = *this;
    ++(*this);
    return temp;
}

//precondition:date must be valid.
//postcondition:decrements the day by one, adjusting month/year if needed.
Date& Date::operator--()
{
    if (day > 1)
    {
        --day;
    }
    else
    {
        if (month == 1)
        {
            month = 12;
            --year;
        }
        else
        {
            --month;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}

//precondition:date must be valid.
//postcondition:decrements the day by one, returning the previous state.
Date Date::operator--(int)
{
    Date temp = *this;
    --(*this);
    return temp;
}

//precondition:both dates must be valid.
//postcondition:returns the number of days between the two dates.
int Date::operator-(const Date& other) const
{
    int totalDays1 = (year * 365) + day;
    for (int i = 1; i < month; ++i)
    {
        totalDays1 += daysInMonth(i, year);
    }

    int totalDays2 = (other.year * 365) + other.day;
    for (int i = 1; i < other.month; ++i)
    {
        totalDays2 += daysInMonth(i, other.year);
    }

    return totalDays1 - totalDays2;
}

//precondition:'date' must have valid 'month', 'day', and 'year' values.
//postcondition:outputs the date in the format "Month day, year".
ostream& operator<<(ostream& os, const Date& date)
{
    string monthName[13] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    os << monthName[date.month] << " " << date.day << ", " << date.year;
    return os;
}

//precondition:'date' must be a valid reference.
//postcondition:reads and validates month, day, and year from user input.
istream& operator>>(istream& is, Date& date)
{
    int m, d, y = date.getYear(); //initialize y with the current year value

    cout << "Enter month(1-12): ";
    is >> m;
    while (m < 1 || m > 12)
    {
        cout << "Invalid month. Enter again (1-12): ";
        is >> m;
    }
    date.setMonth(m);

    cout << "Enter day(1-31): ";
    is >> d;
    while (d < 1 || d > date.daysInMonth(m, y))
    {
        cout << "Invalid day. Enter again (1-" << date.daysInMonth(m, y) << "): ";
        is >> d;
    }
    date.setDay(d);

    cout << "Enter year: ";
    is >> y;
    while (y < 0)
    {
        cout << "Invalid year. Enter a non-negative value: ";
        is >> y;
    }
    date.setYear(y);

    return is;
}

//precondition:'y' should be a valid year.
//postcondition:returns true if 'y' is a leap year, otherwise false.
bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

//precondition:'m' should be a valid month and 'y' a valid year.
//postcondition:returns the number of days in the given month and year.
int Date::daysInMonth(int m, int y) const
{
    if (m == 2)
    {
        return isLeapYear(y) ? 29 : 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}
