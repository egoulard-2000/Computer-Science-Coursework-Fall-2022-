/*
    Emile Goulard
    uID: u1244855
    CS3505 - Assignment 2

    Summary:
        This file is meant to implement the functions provided in 'Spiral.h' using the 
        variables. It calculates the operations needed to make the text on a pdf page print
        in a spiral formation.

*/
#include "Spiral.h"

/*
    Constructor for Spiral object. 
        - It takes in a center spiral coordinate (centerX and centerY),
        a starting angle given in degrees, and a starting radius from the center of the circle
*/
Spiral::Spiral(double centerX, double centerY, double startAngle, double startRadius) {
    _centerX = centerX;
    _centerY = centerY;
    _radius = startRadius;
    _angle = startAngle;

    // This ensures starting angle is not negative (default is starting at 12 o'clock position)
    double minAngle = 90;
    if(startAngle < 0)
        _angle = minAngle;

    // This ensures the starting radius isn't negative (default radius is 30)
    double minRadius = 30;
    if(startRadius < 0)
        _radius = minRadius;

    //Starting Positions and Angles for accurate retrieval of values
    _x = _radius;
    _y = _centerY;
    _letterAngle = _angle;
}

/*
    Prefix operator for moving the spiral
*/
Spiral& Spiral::operator++() {
    // This determines the angle of the letter on the page
    _letterAngle = (_angle - 90) / 180 * M_PI;
    
    // circumference is how far around the circle you are.
    // (both letterAngles and rad2 are perpendicular to each other)
    double circumference = _angle / 180 * M_PI;

    // The position of the character depends on the center point
    // plus the angle and the radius.
    _x = _centerX + cos(circumference) * _radius;
    _y = _centerY + sin(circumference) * _radius;

    double angleScalar = 10.0;

    // Change the angle around the circle and avoid weird spacing issues bewteen characters
    _angle -= (angleScalar * 100 / _radius);

    // Change the radius around the circle to create spiral effect (in clockwise direction)
    _radius += 1.3 + (1/circumference);

    return *this;
}

/*
    Postfix operator for moving the spiral
*/
Spiral Spiral::operator++(int increment) {
    Spiral result(*this); //make a copy for result
    ++(*this); //use prefix version to do work
    return result; //return the copy (the old) value 
}

/*
    Returns the current x coordinate value
*/
double Spiral::getTextX() {
    return _x;
}

/*
    Returns the current y coordinate value
*/
double Spiral::getTextY() {
    return _y;
}

/*
    Returns the current angle of the text (consistent with the angle of the spiral)
*/
double Spiral::getLetterAngle() {
    return _letterAngle;
}