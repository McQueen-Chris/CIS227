#include <math.h>

class Formulas {

public:

    //Function that calculates the hypotenuse of a triangle.
    double hypotenuseTriangle() {

        double a;
        double b;
        double hypotenuse;

        cout << "Please input the measurement of the first side of the triangle: ";
        cin >> a;

        cout << "Please input the measurement of the second side of the triangle: ";
        cin >> b;

        //Formula that takes all necessary user input and returns the desired value.
        hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
        cout << "The hypotenuse of the triangle is: " << hypotenuse << endl;

        return hypotenuse;
    }

    //Function that calculates the area of a trapezoid.
    double areaTrapezoid() {

        double a;
        double b;
        double height;
        double area;

        cout << "Please input the measurement of the top side (shorter side): ";
        cin >> a;

        cout << "Please input the measurement of the bottom side (longer side): ";
        cin >> b;

        cout << "Please input the measurement for the height of the trapezoid: ";
        cin >> height;

        //Formula that takes all necessary user input and returns the desired value.
        area = ((a + b) / 2) * height;
        cout << "The area of the trapezoid is: " << area << endl;

        return area;
    }

    //Function that calculates the volume of a rectangle.
    double volumeRectangle() {

        double length;
        double width;
        double height;
        double volume;

        cout << "Please input the measurement for the length of the rectangle: ";
        cin >> length;

        cout << "Please input the measurement for the width of the rectangle: ";
        cin >> width;

        cout << "Please input the measurement for the height of the rectangle: ";
        cin >> height;

        //Formula that takes all necessary user input and returns the desired value.
        volume = length * width * height;
        cout << "The volume of the rectangle is: " << volume << endl;

        return volume;
    }
};
