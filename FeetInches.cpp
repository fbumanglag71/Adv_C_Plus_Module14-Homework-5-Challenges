//implementation file for the feetinches class
#include <cstdlib>  //needed for abs()
#include "FeetInches.h"

//**************************************************************
//definition of member function simplify. this function       *
//checks for values in the inches member greater than         *
//twelve or less than zero. if such a value is found,         *
//the numbers in feet and inches are adjusted to conform      *
//to a standard feet & inches expression. for example,        *
//3 feet 14 inches would be adjusted to 4 feet 2 inches and   *
//5 feet -2 inches would be adjusted to 4 feet 10 inches.     *
//**************************************************************

//pre: feet and inches values may be unnormalized
//post: feet and inches are normalized to a standard format
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}

//**********************************************
//overloaded binary + operator                
//**********************************************

//pre: takes another feetinches object as a parameter
//post: returns a new feetinches object with summed values
FeetInches FeetInches::operator + (const FeetInches& right)
{
    FeetInches temp;

    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//**********************************************
//overloaded binary - operator                
//**********************************************

//pre: takes another feetinches object as a parameter
//post: returns a new feetinches object with subtracted values
FeetInches FeetInches::operator - (const FeetInches& right)
{
    FeetInches temp;

    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//**********************************************
//overloaded <= operator                      
//**********************************************

//pre: takes another feetinches object as a parameter
//post: returns true if the calling object is less than or equal to the parameter object
bool FeetInches::operator <= (const FeetInches& right)
{
    if (feet < right.feet)
        return true;
    else if (feet == right.feet && inches <= right.inches)
        return true;
    else
        return false;
}

//**********************************************
//overloaded >= operator                      
//**********************************************

//pre: takes another feetinches object as a parameter
//post: returns true if the calling object is greater than or equal to the parameter object
bool FeetInches::operator >= (const FeetInches& right)
{
    if (feet > right.feet)
        return true;
    else if (feet == right.feet && inches >= right.inches)
        return true;
    else
        return false;
}

//**********************************************
//overloaded != operator                      
//**********************************************

//pre: takes another feetinches object as a parameter
//post: returns true if the calling object is not equal to the parameter object
bool FeetInches::operator != (const FeetInches& right)
{
    return (feet != right.feet || inches != right.inches);
}
