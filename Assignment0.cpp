#include <iostream>
//using namespace std;
#include <math.h>

//Function that calculates the area of a trapezoid
int areaTrapezoid() {

    double a;
    double b;
    double height;
    double area;

    std::cout << "Please input the measurement of the top side (shorter side): ";
    std::cin >> a;

    std::cout << "Please input the measurement of the bottom side (longer side): ";
    std::cin >> b;

    std::cout << "Please input the measurement for the height of the trapezoid: ";
    std::cin >> height;

    //Formula that takes all necessary user input and returns the desired value.
    area = ((a + b) / 2) * height;
    std::cout << "The area of the trapezoid is: " << area;

    return area;
}

//Function that calculates the hypotenuse of a triangle
int hypotenuseTriangle() {

    double a;
    double b;
    double hypotenuse;

    std::cout << "Please input the measurement of the first side of the triangle: ";
    std::cin >> a;

    std::cout << "Please input the measurement of the second side of the triangle: ";
    std::cin >> b;

    //Formula that takes all necessary user input and returns the desired value.
    hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
    std::cout << "The hypotenuse of the triangle is: " << hypotenuse;

    return hypotenuse;
}

//Function that calculates the volume of a rectangle.
int volumeRectangle() {

    double length;
    double width;
    double height;
    double volume;

    std::cout << "Please input the measurement for the length of the rectangle: ";
    std::cin >> length;

    std::cout << "Please input the measurement for the width of the rectangle: ";
    std::cin >> width;

    std::cout << "Please input the measurement for the height of the rectangle: ";
    std::cin >> height;

    //Formula that takes all necessary user input and returns the desired value.
    volume = length * width * height;
    std::cout << "The volume of the rectangle is: " << volume;

    return volume;
}

int main()
{
    //Formula variable is used to direct the user which formula they would like a calculation for. This variable should only
    //accept the numbers 1 through 3, with anything else falling under the else category.
    unsigned int formula;
    std::cout << "Hello! This program serves as a calculator for three different math formulas.";
    std::cout << "Which formula would you like? Please pick a number 1-3, with 1 being the hypotenuse, 2 being rectangle volume, and 3 being area of a trapezoid: ";
    std::cin >> formula;

    if (formula == 1) {
        std::cout << "You have chosen the formula that calculates the hypotenuse of a triangle.";
        //Function for hypotenuse of a triangle.
        hypotenuseTriangle();
    }
    else if (formula == 2) {
        std::cout << "You have chosen the formula that calculates the volume of a rectangle.";
        //Function for volume of a rectangle.
        volumeRectangle();

    }
    else if (formula == 3) {
        std::cout << "You have chosen the formula that calculates the area of a trapezoid.";
        //Function for area of a trapezoid.
        areaTrapezoid();
    }
    //This is the last resort in case the user enters a value that does not match the number of predescribed formulas.
    else {
        std::cout << "The number you input does not fall within the range of numbers as described above. Please enter a number 1-3: ";
    }
}