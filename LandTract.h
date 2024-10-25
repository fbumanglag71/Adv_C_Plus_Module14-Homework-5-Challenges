#pragma once

class LandTract {
private:
    int lengthFeet; //stores the feet component of length
    int lengthInches; //stores the inches component of length
    int widthFeet; //stores the feet component of width
    int widthInches; //stores the inches component of width

    //helper function to simplify inches(convert excess inches to feet)
    void simplify(int& feet, int& inches) const;

public:
    //constructor initializes land tract dimensions in feet and inches
    LandTract(int lFeet = 0, int lInches = 0, int wFeet = 0, int wInches = 0);

    //function to calculate and return the area(feet and inches as reference parameters)
    void getArea(int& feet, int& inches) const;
};
