#include "LandTract.h"

//constructor
//pre: lFeet, lInches, wFeet, wInches are valid integers representing length and width in feet and inches
//post: initializes the landtract object with simplified feet and inches for length and width
LandTract::LandTract(int lFeet, int lInches, int wFeet, int wInches)
    : lengthFeet(lFeet), lengthInches(lInches), widthFeet(wFeet), widthInches(wInches) {
    simplify(lengthFeet, lengthInches);
    simplify(widthFeet, widthInches);
}

//simplify inches by converting excess inches to feet
//pre: feet and inches are valid integers representing a measurement in feet and inches
//post: feet and inches are adjusted so that inches is less than 12
void LandTract::simplify(int& feet, int& inches) const {
    if (inches >= 12) {
        feet += inches / 12;
        inches %= 12;
    }
    else if (inches < 0) {
        feet -= (-inches / 12) + 1;
        inches = 12 - (-inches % 12);
    }
}

//calculate and return the area as feet and inches
//pre: lengthFeet, lengthInches, widthFeet, widthInches are initialized and valid
//post: feet and inches contain the calculated area of the landtract
void LandTract::getArea(int& feet, int& inches) const {
    //convert lengths and widths to total inches
    int totalLengthInches = (lengthFeet * 12) + lengthInches;
    int totalWidthInches = (widthFeet * 12) + widthInches;

    //calculate the area in square inches
    int areaInInches = totalLengthInches * totalWidthInches;

    //convert the area to feet
    feet = areaInInches / 144; //divide by 144 to get the number of square feet

    //calculate the remaining square inches
    int remainingInches = areaInInches % 144;

    //convert remaining square inches to inches within the final foot
    inches = remainingInches / 12; //divide remaining inches by 12 to get inches
}
