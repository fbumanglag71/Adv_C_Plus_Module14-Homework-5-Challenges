#pragma once

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;
    bool isLeapYear(int y) const; //checks if a year is leap
    int daysInMonth(int m, int y) const; //returns days based on month/year

public:
    //constructors
    Date(); //default constructor sets to zero
    Date(int m, int d, int y); //parameterized constructor for initialization

    //mutators
    void setMonth(int m); //sets the month value
    void setDay(int d); //sets the day value
    void setYear(int y); //sets the year value

    //accessors
    int getMonth() const; //returns the month value
    int getDay() const; //returns the day value
    int getYear() const; //returns the year value

    //format functions
    string getFormat1() const; //returns "month/day/year" format
    string getFormat2() const; //returns "MonthName day, year" format
    string getFormat3() const; //returns "day MonthName year" format

    //overloaded operators
    Date& operator++(); //prefix increment increments day by one
    Date operator++(int); //postfix increment shows current then increments
    Date& operator--(); //prefix decrement decrements day by one
    Date operator--(int); //postfix decrement shows current then decrements
    int operator-(const Date& other) const; //calculates days between two dates
    friend ostream& operator<<(ostream& os, const Date& date); //outputs date in readable format
    friend istream& operator>>(istream& is, Date& date); //reads and validates user input for date
};
