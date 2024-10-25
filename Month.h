#pragma once
#include <string>
using namespace std;

const string monthNames[] = { "unknown", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

class Month
{
private:
    string name;            // month name
    int monthNumber;        // month number
public:
    Month();                // default constructor
    Month(string name);     // constructor with name
    Month(int m);           // constructor with number
    Month(const Month& obj); // copy constructor

    const Month operator=(const Month& obj);

    void setName(string newName);
    string getName() const;

    void setMonthNumber(int n);
    int getMonthNumber() const;

    Month operator++();     // pre-increment
    Month operator++(int);  // post-increment

    Month operator--();     // pre-decrement
    Month operator--(int);  // post-decrement

    friend ostream& operator<<(ostream& out, const Month& obj);
};

// outputs the Month object
// pre: obj must be a valid Month object
// post: outputs the name and number in "MonthName(Number)" format
ostream& operator<<(ostream& out, const Month& obj)
{
    out << obj.getName() << "(" << obj.getMonthNumber() << ")";
    return out;
}

// pre-increment operator
// pre: none
// post: increments month number, wraps to 1 if over 12
Month Month::operator++()
{
    if (monthNumber >= 12)
        setMonthNumber(1);
    else
        setMonthNumber(++monthNumber);

    return *this;
}

// post-increment operator
// pre: none
// post: increments month number, wraps to 1 if over 12
Month Month::operator++(int)
{
    Month temp = *this;

    if (monthNumber >= 12)
        setMonthNumber(1);
    else
        setMonthNumber(++monthNumber);

    return temp;
}

// pre-decrement operator
// pre: none
// post: decrements month number, wraps to 12 if below 1
Month Month::operator--()
{
    if (monthNumber <= 1)
        setMonthNumber(12);
    else
        setMonthNumber(--monthNumber);

    return *this;
}

// post-decrement operator
// pre: none
// post: decrements month number, wraps to 12 if below 1
Month Month::operator--(int)
{
    Month temp = *this;

    if (monthNumber <= 1)
        setMonthNumber(12);
    else
        setMonthNumber(--monthNumber);

    return temp;
}

// default constructor
// pre: none
// post: sets name to "unknown" and monthNumber to 0
Month::Month()
{
    name = "unknown";
    monthNumber = 0;
}

// constructor with month name
// pre: newName should be a valid month name
// post: sets name and monthNumber based on newName
Month::Month(string newName)
{
    setName(newName);
}

// constructor with month number
// pre: m should be an integer between 1 and 12
// post: sets name and monthNumber based on m
Month::Month(int m)
{
    setMonthNumber(m);
}

// copy constructor
// pre: obj must be a valid Month object
// post: creates a new Month object with obj's values
Month::Month(const Month& obj)
{
    name = obj.name;
    monthNumber = obj.monthNumber;
}

// assignment operator
// pre: obj must be a valid Month object
// post: assigns obj's values to this object
const Month Month::operator=(const Month& obj)
{
    if (this != &obj) // check for self-assignment
    {
        name = obj.name;
        monthNumber = obj.monthNumber;
    }
    return *this;
}

// sets the month name
// pre: newName should be a valid month name
// post: updates name and monthNumber based on newName
void Month::setName(string newName)
{
    name = "unknown";
    monthNumber = 0;

    for (int m = 0; m < 13; m++)
    {
        if (newName == monthNames[m])
        {
            name = monthNames[m];
            monthNumber = m;
        }
    }
}

// gets the month name
// pre: none
// post: returns the name as a string
string Month::getName() const
{
    return name;
}

// sets the month number
// pre: m should be an integer between 1 and 12
// post: updates name and monthNumber based on m
void Month::setMonthNumber(int m)
{
    name = "unknown";
    monthNumber = 0;

    if (m >= 1 && m <= 12)
    {
        monthNumber = m;
        name = monthNames[m];
    }
}

// gets the month number
// pre: none
// post: returns the month number as an integer
int Month::getMonthNumber() const
{
    return monthNumber;
}
