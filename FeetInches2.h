#pragma once

//the FeetInches2 class holds distances or measurements
//expressed in feet and inches.

class FeetInches2
{
private:
    int feet;         //to hold a number of feet
    int inches;       //to hold a number of inches
    void simplify();  //defined in FeetInches2.cpp
public:
    //constructors
    FeetInches2(int f = 0, int i = 0)
    {
        feet = f; inches = i; simplify();
    }

    //copy constructor
    FeetInches2(const FeetInches2& obj)
    {
        feet = obj.feet; inches = obj.inches;
    }

    //mutator functions
    void setFeet(int f) { feet = f; }
    void setInches(int i) { inches = i; simplify(); }

    //accessor functions
    int getFeet() const { return feet; }
    int getInches() const { return inches; }

    //overloaded operator functions
    FeetInches2 operator + (const FeetInches2&); //overloaded +
    FeetInches2 operator - (const FeetInches2&); //overloaded -
    FeetInches2 operator * (const FeetInches2&); //overloaded *
    bool operator <= (const FeetInches2&);       //overloaded <=
    bool operator >= (const FeetInches2&);       //overloaded >=
    bool operator != (const FeetInches2&);       //overloaded !=
};
