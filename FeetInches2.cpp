#include <cstdlib>  //needed for abs()
#include "FeetInches2.h"

//precondition:simplify() is called when inches is set or modified
//postcondition:feet and inches are adjusted to a standard form (inches < 12)
void FeetInches2::simplify()
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

//precondition: none
//postcondition:returns a new FeetInches2 object that is the sum of this object and the right operand
FeetInches2 FeetInches2::operator + (const FeetInches2& right)
{
    FeetInches2 temp;
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}

//precondition: none
//postcondition:returns a new FeetInches2 object that is the difference between this object and the right operand
FeetInches2 FeetInches2::operator - (const FeetInches2& right)
{
    FeetInches2 temp;
    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}

//precondition: none
//postcondition:returns a new FeetInches2 object that is the product of this object and the right operand
FeetInches2 FeetInches2::operator * (const FeetInches2& right)
{
    FeetInches2 temp;
    temp.feet = feet * right.feet;
    temp.inches = inches * right.inches;
    temp.simplify();
    return temp;
}

//precondition:the right operand must be a valid FeetInches2 object
//postcondition:returns true if this object is less than or equal to the right operand
bool FeetInches2::operator <= (const FeetInches2& right)
{
    if (feet < right.feet)
        return true;
    else if (feet == right.feet && inches <= right.inches)
        return true;
    else
        return false;
}

//precondition:the right operand must be a valid FeetInches2 object
//postcondition:returns true if this object is greater than or equal to the right operand
bool FeetInches2::operator >= (const FeetInches2& right)
{
    if (feet > right.feet)
        return true;
    else if (feet == right.feet && inches >= right.inches)
        return true;
    else
        return false;
}

//precondition: none
//postcondition:returns true if this object is not equal to the right operand
bool FeetInches2::operator != (const FeetInches2& right)
{
    return (feet != right.feet || inches != right.inches);
}
