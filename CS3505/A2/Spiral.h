/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 2

    Summary:
        This is the header file that defines the Spiral Class.
        Refer to the Spiral class comment for more information.

*/
#ifndef SPIRAL_H
#define SPIRAL_H
#include <math.h>
#include <iostream>

/*
    Spiral Class to be extended in 'Spiral.cpp' file.

    It contains variables necessary for calculating text that goes in a spiral.
*/
class Spiral {
    private:
        double _angle;
        double _letterAngle;
        double _radius;

        double _x;
        double _y;
        double _centerX;
        double _centerY;

    public:
        Spiral(double centerX, double centerY, double startAngle, double startRadius);
        Spiral& operator++();
        Spiral operator++(int); 
        double getTextX();
        double getTextY();
        double getLetterAngle();
};

#endif
