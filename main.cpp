#include<iostream>          //standard input-output library usage required
#include"input.h"           //custom input header file required
#include"Month.h"           //Month class header file needed
#include "Date.h"           //Date class header file needed
#include <cstdlib>          //C standard library utilities used
#include "FeetInches.h"     //FeetInches class header file needed
#include "FeetInches2.h"    //FeetInches2 class header file needed
#include "LandTract.h"      //LandTract class header file needed

using namespace std;       //standard namespace for simplifying code

int menuOption();
void Challenge7();
void Challenge8();
void Challenge9();
void Challenge11();
void Challenge12();

int main()                         //entry point of the program

{
    do                             //loop to keep program running
    {
        switch (menuOption())      //evaluate menu option chosen
        {
        case 0: exit(1); break;    //exit program when option zero
        case 7: Challenge7(); break; //call Challenge7 function if selected
        case 8: Challenge8(); break; //call Challenge8 function if selected
        case 9: Challenge9(); break; //call Challenge9 function if selected
        case 11: Challenge11(); break; //call Challenge11 function if selected
        case 12: Challenge12(); break; //call Challenge12 function if selected
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break; //handle invalid options
        }
        cout << "\n";              //newline for formatting output
        system("pause");           //pause execution to view output

    } while (true);                //continue until program is exited

    return EXIT_SUCCESS;           //indicate successful program termination
}


//main menu 
int menuOption()
{
    system("cls");
    cout << "\n\tCMPR121 Chapter 14: More about classes (page 900-906) by Francisco Bumanglag";
    cout << "\n\t" << string (90, char(205));
    cout << "\n\t7. Month Class";
    cout << "\n\t8. Date class Modification";
    cout << "\n\t9. FeetInches Modification";
    cout << "\n\t11. FeetInches class Copy Constructor amd multiply Function";
    cout << "\n\t12. LandTract class";
    cout << "\n\t" << string(90, char(196));
    cout << "\n\t0. Exit";
    cout << "\n\t" << string(90, char(205));
    return inputInteger("\n\tOption: ", 0, 12);
}

void Challenge7()
{
    Month testmonth1; //test default constructor
    testmonth1.setName(inputString("\n\tEnter a name of the month: ", false));
    cout << testmonth1 << '\n';

    Month testmonth2(10);    //test arg constructor
    testmonth2.setMonthNumber(inputInteger("\n\tEnter a number(1...12) of the month: ", 1,12));
    cout << testmonth2 << '\n';

    Month testMonth4(testmonth2);   //test copy Constructor
    cout << testMonth4 << "\n";

    Month testMonth5 = testMonth4;  //test assignment operator
    cout << testMonth5 << '\n';

    cout << ++testMonth5 << '\n';   //test ++ pre-increment operator

    cout << testMonth5++ << '\n';   //test ++ post-increment operator

    cout << testMonth5 << "\n";     //display finalized month

    Month testMonth6(1);
    cout << --testMonth6 << "\n";     //test -- pre-decrement
    cout << testMonth6-- << "\n";     //test -- post-decrement
    cout << testMonth6 << "\n";     //display finalized month

}

//implementation of challenge8 (date manipulation demo)
void Challenge8()
{
    Date d1, d2;

    //input for d1
    cout << "enter new date values for d1\n";
    cin >> d1; //using the overloaded >> operator to get input for d1
    cout << "\nd1 = " << d1 << endl; //using the overloaded << operator to display d1

    //demonstrate increment operators
    cout << "\nd1++ = " << d1++ << endl;
    cout << "++d1 = " << ++d1 << endl;

    //input for d1 again
    cout << "\nenter new date values for d1\n";
    cin >> d1;

    //demonstrate decrement operators
    cout << "\nd1-- = " << d1-- << endl;
    cout << "--d1 = " << --d1 << endl;

    //input for d1 and d2
    cout << "\nenter new date values for d1\n";
    cin >> d1;
    cout << "\nenter new date values for d2\n";
    cin >> d2;

    //demonstrate subtraction operator
    cout << "d1 - d2 = " << (d1 - d2) << " days" << endl;
}

//challenge9 function for demonstrating FeetInches modifications
void Challenge9()
{
    FeetInches f1, f2;

    int feet, inches;

    //input for F1
    cout << "F1\nEnter Feet: ";
    cin >> feet;  //read feet value for f1
    cout << "Enter Inches: ";
    cin >> inches;  //read inches value for f1
    f1.setFeet(feet);
    f1.setInches(inches);

    //input for F2
    cout << "F2\nEnter Feet: ";
    cin >> feet;  //read feet value for f2
    cout << "Enter Inches: ";
    cin >> inches;  //read inches value for f2
    f2.setFeet(feet);
    f2.setInches(inches);

    //display comparisons
    cout << "F1 >= F2 -> " << (f1 >= f2 ? "true" : "false") << endl;  //compare f1 >= f2
    cout << "F1 <= F2 -> " << (f1 <= f2 ? "true" : "false") << endl;  //compare f1 <= f2
    cout << "F1 != F2 -> " << (f1 != f2 ? "true" : "false") << endl;  //compare f1 != f2
}


//challenge11 function for demonstrating FeetInches2 modifications
//creates feetinches2 objects and demonstrates copy and multiply functions
void Challenge11()
{
    FeetInches2 f1, f2;
    int feet, inches;

    //input for f1
    //collect feet and inches values for f1 from user
    cout << "Enter F1\nEnter Feet: ";
    cin >> feet;
    cout << "Enter Inches: ";
    cin >> inches;
    f1.setFeet(feet);  //set feet value for f1
    f1.setInches(inches);  //set inches value for f1 and simplify

    //demonstrate copy constructor by creating f2 as a copy of f1
    f2 = f1;

    //display the values of f1 and f2
    cout << "F1 = " << f1.getFeet() << " feet, " << f1.getInches() << " inches" << endl;
    cout << "F2 = " << f2.getFeet() << " feet, " << f2.getInches() << " inches" << endl;

    //demonstrate multiply function
    //multiply f1 and f2 and store result in f3
    FeetInches2 f3 = f1 * f2;
    //display the result of the multiplication
    cout << "F1 * F2 = " << f3.getFeet() << " feet, " << f3.getInches() << " inches" << endl;
}

//challenge12 function for demonstrating landtract class usage
void Challenge12()
{
    int feet, inches;

    //prompt user to enter length dimensions for lt1
    cout << "enter the dimensions of the landtract lt1\nlength\n\tfeet: ";
    cin >> feet; //read feet for length
    cout << "\tinches: ";
    cin >> inches; //read inches for length
    int lengthFeet = feet, lengthInches = inches; //store length values

    //prompt user to enter width dimensions for lt1
    cout << "width\n\tfeet: ";
    cin >> feet; //read feet for width
    cout << "\tinches: ";
    cin >> inches; //read inches for width
    int widthFeet = feet, widthInches = inches; //store width values

    //create landtract object with user-provided dimensions
    LandTract lt1(lengthFeet, lengthInches, widthFeet, widthInches);

    //initialize variables to store calculated area
    int areaFeet, areaInches;
    lt1.getArea(areaFeet, areaInches); //calculate area using getArea function

    //display the calculated area of lt1 to user
    cout << "\nthe area of lt1 = " << areaFeet << " feet, " << areaInches << " inches\n";
}
