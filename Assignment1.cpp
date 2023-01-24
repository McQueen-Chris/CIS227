#include <iostream>
using namespace std;
#include <math.h>
#include "Formulas.h"

int main()
{
    //Formula variable is used to direct the user which formula they would like a calculation for. This variable should only
    //accept the numbers 1 through 3, with anything else falling under the else category.
    unsigned int formula;
    cout << "Hello! This program serves as a calculator for three different math formulas." << endl;
    cout << "Which formula would you like?" << endl;
    cout << "Please pick a number 1 - 3, with 1 being the hypotenuse, 2 being rectangle volume, and 3 being area of a trapezoid : " << endl;
    cin >> formula;

    Formulas triangle;
    Formulas trapezoid;
    Formulas rectangle;

    if (formula == 1) {
        cout << "You have chosen the formula that calculates the hypotenuse of a triangle." << endl;
        //Function for hypotenuse of a triangle.
        triangle.hypotenuseTriangle();
    }
    else if (formula == 2) {
        cout << "You have chosen the formula that calculates the volume of a rectangle." << endl;
        //Function for volume of a rectangle.
        rectangle.volumeRectangle();

    }
    else if (formula == 3) {
        cout << "You have chosen the formula that calculates the area of a trapezoid." << endl;
        //Function for area of a trapezoid.
        trapezoid.areaTrapezoid();
    }
    //This is the last resort in case the user enters a value that does not match the number of predescribed formulas.
    else {
        cout << "The number you input does not fall within the range of numbers as described above. Please enter a number 1-3: " << endl;
    }

    string yesOrNo = "Yes";
    cout << "Would you like to calculate another formula? To stay in the program, type Yes. To exit, type No." << endl;
    cin >> yesOrNo;

    //Looping structure used to cycle through the program depending on user preference.
    //Y brings the user back to the beginning of main, N will close the program.
    while (yesOrNo == "Yes") {
        main();
    }

    if (yesOrNo == "No") {
        cout << "Exiting the program now. Goodbye!" << endl;
        return 0;
    }

}